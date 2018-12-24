/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 * Example:
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Note:
 * Your algorithm should use only constant extra space.
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 */

#include <linux_config.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void *
leet_malloc(size_t size)
{
    void *res = NULL;
    if (size > 0) {
        res = malloc(size);
        memset(res,0,size);
    }
    return res;
}

struct ListNode *
init_node(int val)
{
    struct ListNode *res;
    res = leet_malloc(sizeof(struct ListNode));
    res->val = val;
    return res;
}

struct ListNode*
swapPairs(struct ListNode* head)
{
    struct ListNode *tmp;
    if (head == NULL) return head;
    tmp = head->next;
    if (tmp != NULL) {
        head->next = swapPairs(tmp->next);
        tmp->next = head;
        return tmp;
    } else {
        return head;
    }
}

int
main(int argc, char **argv)
{
    struct ListNode *res_head, *res, *tmp, *result;
    res_head = res = tmp = init_node(1);
    tmp = init_node(2); res->next = tmp; res = tmp;
    tmp = init_node(3); res->next = tmp; res = tmp;
    tmp = init_node(4); res->next = tmp; res = tmp;
    tmp = init_node(5); res->next = tmp; res = tmp;
    tmp = init_node(6); res->next = tmp; res = tmp;
    result = swapPairs(res_head);
    printf("result print:\n");
    while (result != NULL) {
        printf("->%d",result->val);
        result = result->next;
    }
    printf("\n");
    return 0;
}
