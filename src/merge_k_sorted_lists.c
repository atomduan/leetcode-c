/**
*   Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*   Example:
*   Input:
*   [
*     1->4->5,
*     1->3->4,
*     2->6
*   ]
*   Output: 1->1->2->3->4->4->5->6
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

void
init_heading_tuple(struct ListNode** lists, int listsSize, struct ListNode **heading_tuple)
{
    int i = 0;
    for (i=0; i<listsSize; i++) {
        *heading_tuple++ = lists[i];
    }
}

struct ListNode* 
mergeKLists(struct ListNode** lists, int listsSize) 
{
    struct ListNode **heading_tuple, **tmp_tuple;
    int max_index, i, max_val;

    heading_tuple = leet_malloc(sizeof(struct ListNode*)*(listsSize+1)); 
    init_heading_tuple(lists,listsSize,heading_tuple);
    while (1) {
        tmp_tuple = heading_tuple; 
        max_index = 0, i = 0, max_val = (*tmp_tuple)->val;
        while (*tmp_tuple != NULL) {
            if (*tmp_tuple != NULL && (*tmp_tuple)->val > max_val) { 
                max_index = i;
                max_val = (*tmp_tuple)->val;
            }
            tmp_tuple++, i++;
        }
        tmp_tuple[max_index] = tmp_tuple[max_index]->next;
    }
    return NULL;
}

int
main(int argc, char **argv)
{
    return 0;
}
