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
    step *prev;
}; 

static step *
new_step(char *pos)
{
    step *res = NULL;
    res = malloc(sizeof(step));
    memset(res, 0, sizeof(step));
    res->pos = pos;
    return res;
}

static bool
is_accept(step *sp, char *ss) {
    if (*sp->pos == '\0') return false;
    if (*sp->pos == '.') {
        return true;
    } else {
        if (*sp->pos == *ss) return true;
    }
    return false;
}

static bool 
isMatch(char* s, char* p) {
    char *ss = NULL;
    char *tmpstr = NULL;
    step *stp = NULL; 
    step *head = NULL;
    step *tmp = NULL;
    int score = 0;

    head = new_step(p);

    for (ss=s; *ss!='\0'; ss++) {
        for (stp = head; stp!=NULL; stp=stp->next) {
            if (is_accept(stp, ss)) {
                if (stp->pos[1] == '*') {
                    //fork new step
                    tmp = new_step(stp->pos);
                    if (stp->prev == NULL) {
                        head = tmp; 
                    } else {
                        stp->prev->next = tmp; tmp->prev = stp->prev;
                    }
                    tmp->next = stp; stp->prev = tmp;
                    //step over * 
                    stp->pos = &stp->pos[2];
                } else {
                    stp->pos++;
                }
            } else {
                if (stp->pos[1] == '*') {
                    //step over * 
                    stp->pos = &stp->pos[2];
                } else {
                    //remove this step from list
                    if (stp->prev == NULL) {
                        head = stp->next; 
                        tmp = stp->next; free(stp); stp = tmp;
                    } else {
                        stp->prev->next = stp->next;
                        if (stp->next != NULL) {
                            stp->next->prev = stp->prev;
                        }
                        tmp = stp->next; free(stp); stp = tmp;
                    }
                }
            }
        }
    }

    //check remain step
    for (stp = head; stp!=NULL; stp=stp->next) {
        if (*stp->pos == '\0') return true;
        score = 0;
        for (tmpstr = stp->pos; *tmpstr!='\0'; tmpstr++) {
            if (*tmpstr != '*') {
                score++;
                if (score != 1) return false;
            } else {
                score--;
                if (score != 0) return false;
            }
            return true;
        }
    }
    return false; 
}

int main(int argc, char **argv) 
{
    printf("isMatch %d\n", isMatch("abb", "c*a*b"));
    return 0;
}
