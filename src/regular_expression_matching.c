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


typedef struct step_s step;

struct step_s {
    char *pos;
    step *next;
}; 

static step *
new_step()
{
    step *res = NULL;
    res = malloc(sizeof(step));
    memset(res, 0, sizeof(step));
    return res;
}

static bool
is_accept(step *sp, char *ss) {
    if (*sp->pos == '.') {
        return true;
    } else {
        if (*sp->pos == *ss) {
            return true;
        }
    }
    return false;
}

static bool 
isMatch(char* s, char* p) {
    char *ss = NULL;
    step *sp = NULL; 
    step *head = NULL;
    step *curr = NULL;
    step *prev = NULL;
    step *tmp = NULL;
    for (ss=s; *ss!='\0'; ss++) {
        //init
        if (sp == NULL && ss==s) {
            sp = new_step();
            sp->pos = p; 
            head = sp;
        }

        curr = head; 
        prev = NULL;
        do {
            if (is_accept(curr, ss)) {
                    printf("2\n");
                if (curr->pos[1] == '*') {
                    //fork new step
                    tmp = new_step();
                    tmp->pos = curr->pos;
                    tmp->next = curr->next;
                    curr->next = tmp;
                    //curr go far step
                    curr->pos = &curr->pos[2];
                } else {
                    curr->pos++;
                }
                if (*curr->pos == '\0') {
                    return true;
                } else {
                    prev = curr;
                }
            } else {
                if (curr->pos[1] != '*') {
                    if (prev == NULL) {
                        free(curr);
                        return false;
                    } else {
                        prev->next = curr->next;
                        free(curr);
                        if (prev->next == NULL) {
                            return false;
                        }
                        continue;
                    }
                } else {
                    curr->pos = &curr->pos[2];
                    prev = curr;
                    continue;
                }
            }
            curr = prev->next;
        } while (curr!=NULL);
    }
    return true; 
}

int main(int argc, char **argv) 
{
    printf("isMatch %d\n", isMatch("abb", "c*a*b"));
    return 0;
}
