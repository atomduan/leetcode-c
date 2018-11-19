/*
 *Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 *
 *'.' Matches any single character.
 *'*' Matches zero or more of the preceding element.
 *The matching should cover the entire input string (not partial).
 *
 *Note:
 *
 *s could be empty and contains only lowercase letters a-z.
 *p could be empty and contains only lowercase letters a-z, and characters like . or *.
 *Example 1:
 *
 *Input:
 *s = "aa"
 *p = "a"
 *Output: false
 *Explanation: "a" does not match the entire string "aa".
 *Example 2:
 *
 *Input:
 *s = "aa"
 *p = "a*"
 *Output: true
 *Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 *Example 3:
 *
 *Input:
 *s = "ab"
 *p = ".*"
 *Output: true
 *Explanation: ".*" means "zero or more (*) of any character (.)".
 *Example 4:
 *
 *Input:
 *s = "aab"
 *p = "c*a*b"
 *Output: true
 *Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
 *Example 5:
 *
 *Input:
 *s = "mississippi"
 *p = "mis*is*p*."
 *Output: false
 */

#include <linux_config.h>
#include <misc_utils.h>

#define ATTR_START 0
#define ATTR_PLAN 1 
#define ATTR_REPEAT 2
#define ATTR_END 3

#define STEP_OFF 0
#define STEP_ON 1

typedef struct statm_s statm;
typedef struct step_s step;

struct statm_s {
    int     attr; 
    char    val;
    statm   *next;
}; 

struct step_s {
    int     status;
    statm   *curr_stat;
    step    *next;
}; 

static statm *
new_stat(int attr, char val)
{
    statm *res = NULL;
    res = malloc(sizeof(statm));
    memset(res, 0, sizeof(statm));
    res->attr = attr;
    res->val = val;
    return res;
}

static step *
new_step(statm *st)
{
    step *res = NULL;
    res = malloc(sizeof(step));
    memset(res, 0, sizeof(step));
    res->status = STEP_ON;
    res->curr_stat = st;
    res->next = NULL;
    return res;
}

/**
 * compile and build a NFA, in this case is a link list
 */
static statm *
compile_pattern(char *pattern)
{
    char *p = NULL;
    statm *head = NULL;
    statm *curr = NULL;
    head = curr = new_stat(ATTR_START, '\a');
    for (p=pattern; *p!='\0'; p++) {
        if (p[1] == '*') {
            curr->next = new_stat(ATTR_REPEAT,*p++);
        } else {
            curr->next = new_stat(ATTR_PLAN,*p);
        }
        curr = curr->next;
    }
    curr->next = new_stat(ATTR_PLAN,'\0');
    curr = curr->next;
    curr->next = new_stat(ATTR_END,'\a');
    return head;
}

static step *
get_tail_step(step *step_head) 
{
    step *curr_step = step_head;
    step *tail_step = NULL;
    do {
        tail_step = curr_step;
        curr_step = curr_step->next;
    } while (curr_step != NULL);
    return tail_step;
}

static bool
is_compatibale(char *sp, char *ss) {
    if (*sp == '.') {
        return true;
    } else {
        if (*sp == *ss) return true;
    }
    return false;
}

static void 
process_stat_detect(statm *des_stat, char input_char, step *tail_step)
{
    if (des_stat == NULL) return;
    if (is_compatibale(&des_stat->val, &input_char)) {
        step *tmp_step = new_step(des_stat);
        tail_step->next = tmp_step;
        tail_step = tail_step->next;
    }
    if (des_stat->attr == ATTR_REPEAT){
        process_stat_detect(des_stat->next, input_char, tail_step);
    }
}

static void
evaluate_src_step_close(step *src_step, char input_char)
{
    if (src_step->curr_stat->attr != ATTR_REPEAT){
        src_step->status = STEP_OFF;
    } else {
        if (false == is_compatibale(&src_step->curr_stat->val, &input_char)) {
            src_step->status = STEP_OFF;
        }
    }
}

static void
process_curr_step(step *src_step, char input_char, step *tail_step)
{
    statm *des_stat = NULL;
    if (src_step->status == STEP_ON) {
        des_stat = src_step->curr_stat->next;
        process_stat_detect(des_stat, input_char, tail_step);
        evaluate_src_step_close(src_step, input_char);
    }
}

static void
read_one_char(char c, step *head_step) {
    step *curr_step = NULL;
    step *tail_step = NULL;
    tail_step = get_tail_step(head_step);
    for (curr_step=head_step; 
            curr_step!=NULL && 
            curr_step!=tail_step; 
            curr_step=curr_step->next) {
        process_curr_step(curr_step,c,tail_step); 
    }
    process_curr_step(tail_step,c,tail_step); 
}

void 
print_steps(step *head_step)
{
    step *tmp = NULL;
    char *status = NULL;
    char *statval = NULL;
    char *stattyp = NULL;
    int count = 0;

    for (tmp = head_step; tmp != NULL; tmp=tmp->next) {
        if(tmp->status == STEP_OFF) {
            status = "STEP_OFF";
        } else if (tmp->status == STEP_ON) {
            status = "STEP_ON";
        } else {
            status = "UNKNOWN";
        }

        if (tmp->curr_stat != NULL) {
            if (tmp->curr_stat->attr == ATTR_START) {
                statval = "\\a";
                stattyp = "ATTR_START";
            }
            if (tmp->curr_stat->attr == ATTR_END) {
                statval = "\\a";
                stattyp = "ATTR_END";
            }
            if (tmp->curr_stat->attr == ATTR_PLAN) {
                statval = &tmp->curr_stat->val;
                stattyp = "ATTR_PLAN";
            }
            if (tmp->curr_stat->attr == ATTR_REPEAT) {
                statval = &tmp->curr_stat->val;
                stattyp = "ATTR_REPEAT";
            }
        }
        printf ("[%d: step_stat:%s, step_typ:%s, step_status:%s]\n", count, statval, stattyp, status);
        count++;
    }
}

static bool
determin_match(step *head_step)
{
    step *curr_step = NULL;
    for (curr_step=head_step; curr_step!=NULL; curr_step=curr_step->next) {
        if (curr_step->curr_stat->val == '\0') return true; 
    }
    return false;
}

static bool 
isMatch(char* s, char* p) 
{
    char *ss = NULL;
    int end_flag = 0;
    statm *stat_head = compile_pattern(p);
    step *head_step = new_step(stat_head);
    for (ss=s; end_flag != 1; ss++) {
        if(*ss == '\0') end_flag = 1;
        printf("\n\n%s,%c-------------------------------------------%s\n",s, *ss, p);
        print_steps(head_step);
        read_one_char(*ss, head_step);
        printf("########################\n");
        print_steps(head_step);
    }
    return determin_match(head_step); 
}

int main(int argc, char **argv) 
{
    //printf("isMatch %d\n", isMatch("aa", "a"));
    //printf("isMatch %d\n", isMatch("aa", ".*"));
    //printf("isMatch %d\n", isMatch("aa", "."));
    //printf("isMatch %d\n", isMatch("aa", ".*ax*aa*"));
    //printf("isMatch %d\n", isMatch("mississippi", "mis*is*p*."));
    //printf("isMatch %d\n", isMatch("mississippi", "mis*is*ip*."));
    printf("isMatch %d\n", isMatch("abbaaaabaabbcba", "a*.*ba.*c*..a*.a*."));
    return 0;
}
