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

#define MATCH_DENY 0
#define MATCH_ACCEPT 1

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
    curr->next = new_stat(ATTR_END,'\0');
    return head;
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

static int
process_curr_step(step *curr_step, char *input_char, step *tail_step)
{
    statm *curr_stat = curr_step->curr_stat;
    
    for (;curr_stat != NULL; curr_stat = curr_stat->next) {
        if (curr_stat->attr == ATTR_END) return MATCH_ACCEPT;
        printf("xxxxinput_char %s step at %s\n", input_char, &curr_stat->val);
        if (is_compatibale(&curr_stat->val, input_char)) {
            printf("input_char %s step at %s\n", input_char, &curr_stat->val);
            step *tmp_step = new_step(curr_stat);
            tail_step->next = tmp_step;
        } else {
            if (curr_stat->attr != ATTR_REPEAT) {
                break;
            }
        }
    }
    curr_step->status = STEP_OFF;
    return MATCH_DENY;
}

static bool 
isMatch(char* s, char* p) {
    char *ss = NULL;
    int  res = MATCH_DENY;
    statm *stat_head = compile_pattern(p);

    step *curr_step = NULL;
    step *tail_step = NULL;
    step *step_head = new_step(stat_head);

    int end_flag = 0;
    for (ss=s; end_flag != 1; ss++) {
        if(*ss == '\0') end_flag = 1;
        curr_step = step_head;
        do {
            tail_step = curr_step;
            curr_step = curr_step->next;
        } while (curr_step != NULL);

        printf("input_char %s step\n", ss);
        for (curr_step = step_head; curr_step!=NULL && curr_step->next!=tail_step; curr_step=curr_step->next) {
            if (curr_step->status == STEP_ON) {
                res = process_curr_step(curr_step, ss, tail_step); 
                if (res == MATCH_ACCEPT) return true;
            }
        }
        if (tail_step->status == STEP_ON) {
            res = process_curr_step(tail_step, ss, tail_step); 
            if (res == MATCH_ACCEPT) return true;
        }
    }
    return false; 
}

int main(int argc, char **argv) 
{
    printf("isMatch %d\n", isMatch("acc", "acb*x*c*.*"));
    return 0;
}
