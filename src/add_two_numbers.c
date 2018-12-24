/*
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <linux_config.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *
addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *r = NULL;
    struct ListNode *result = NULL;
    int asc_value = 0;
    int cur_value = 0;

    while (1) {
        if (l1 != NULL && l2 != NULL) {
            cur_value = l1->val + l2->val;
        } else
        if (l1 != NULL) {
            cur_value = l1->val;
        } else
        if (l2 != NULL) {
            cur_value = l2->val;
        }
        cur_value += asc_value;
        asc_value = 0;

        if (r == NULL) {
            r = malloc(sizeof(struct ListNode));
            r->next = NULL;
            result = r;
        } else {
            r->next = malloc(sizeof(struct ListNode));
            r = r->next;
            r->next = NULL;
        }
        r->val = cur_value > 9 ? cur_value - 10 : cur_value;
        asc_value = cur_value > 9 ? 1 : 0;

        if (l1!=NULL) l1 = l1->next;
        if (l2!=NULL) l2 = l2->next;
        if (l1==NULL && l2==NULL) break;
    }

    if (asc_value > 0) {
        r->next = malloc(sizeof(struct ListNode));
        r = r->next;
        r->next = NULL;
        r->val = asc_value;
    }

    return result;
}

int main(int argc, char **argv)
{
    return 0;
}
