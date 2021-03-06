/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * Example:
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */
#include <let_config.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

static void *
leet_malloc(size_t size)
{
    void *res = NULL;
    if (size > 0) {
        res = malloc(size);
        memset(res,0,size);
    }
    return res;
}

static void
init_heading_tuple(struct ListNode** lists,
                   int listsSize,
                   struct ListNode **heading_tuple)
{
    int i = 0;
    for (i=0; i<listsSize; i++) {
        *heading_tuple++ = lists[i];
    }
}

static struct ListNode *
init_node(int val)
{
    struct ListNode *res;
    res = leet_malloc(sizeof(struct ListNode));
    res->val = val;
    return res;
}

struct ListNode*
mergeKLists(struct ListNode** lists,int listsSize)
{
    struct ListNode **heading_tuple, **tmp_tuple, *tmp_node;
    struct ListNode *res = NULL, *res_tmp = NULL, *res_head = NULL;
    int min_index, i, min_val, all_null, hd_size;

    hd_size = sizeof(struct ListNode*)*(listsSize+1);
    heading_tuple = leet_malloc(hd_size);
    init_heading_tuple(lists, listsSize, heading_tuple);
    all_null = 0;
    while (!all_null) {
        tmp_tuple = heading_tuple;
        min_index = 0, i = 0, min_val = INT_MAX;
        all_null = 1;
        for (i=0; i<listsSize; i++) {
            tmp_node = tmp_tuple[i];
            if (tmp_node != NULL) {
                all_null = 0;
                if (tmp_node->val < min_val) {
                    min_index = i;
                    min_val = tmp_node->val;
                }
            }
        }
        if (!all_null) {
            if (res == NULL) {
                res = init_node(heading_tuple[min_index]->val);
                res_head = res;
            } else {
                res_tmp = init_node(heading_tuple[min_index]->val);
                res->next = res_tmp;
                res = res_tmp;
            }
            heading_tuple[min_index] = heading_tuple[min_index]->next;
        }
    }
    return res_head;
}

int
main(int argc,char **argv)
{
    struct ListNode *res_head, *res, *tmp, **tuple, *result;
    int listsSize = 3;
    tuple = leet_malloc(sizeof(struct ListNode*)*4);

    res_head = res = init_node(1);
    tmp = init_node(4); res->next = tmp; res = tmp;
    tmp = init_node(5); res->next = tmp; res = tmp;
    tuple[0] = res_head;

    res_head = res = init_node(1);
    tmp = init_node(3); res->next = tmp; res = tmp;
    tmp = init_node(4); res->next = tmp; res = tmp;
    tuple[1] = res_head;

    res_head = res = init_node(2);
    tmp = init_node(6); res->next = tmp; res = tmp;
    tuple[2] = res_head;

    result = mergeKLists(tuple, listsSize);

    printf("result is :\n");
    while (result != NULL) {
        printf("->%d", result->val);
        result = result->next;
    }
    printf("\n");

    return 0;
}
