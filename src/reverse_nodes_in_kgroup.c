/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * k is a positive integer and is less than or equal to the length of the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * 
 * Example:
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be changed.
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
    struct ListNode *res = NULL;
    res = leet_malloc(sizeof(struct ListNode));
    res->val = val;
    return res;
}

struct ListNode * 
reverseKGroup(struct ListNode* head, int k)
{
    return head;
}

int
main(int argc, char **argv)
{
    int k=2;
    struct ListNode *res_head, *res, *tmp, *result;
    res_head = res = tmp = init_node(1);
    tmp = init_node(2); res->next = tmp; res = tmp;
    tmp = init_node(3); res->next = tmp; res = tmp;
    tmp = init_node(4); res->next = tmp; res = tmp;
    tmp = init_node(5); res->next = tmp; res = tmp;
    tmp = init_node(6); res->next = tmp; res = tmp;
    tmp = init_node(7); res->next = tmp; res = tmp;
    tmp = init_node(8); res->next = tmp; res = tmp;
    tmp = init_node(9); res->next = tmp; res = tmp;
    result = reverseKGroup(res_head,k);
    printf("result print:\n");
    while (result != NULL) {
        printf("->%d",result->val);
        result = result->next;
    }
    printf("\n");
    return 0; 
}
