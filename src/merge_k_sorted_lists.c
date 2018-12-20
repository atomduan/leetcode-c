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
init_heading_tuple(struct ListNode** lists, 
                   int listsSize, 
                   struct ListNode **heading_tuple)
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
    struct ListNode *res=NULL, *res_tmp=NULL, *res_head=NULL;
    int min_index, i, min_val, all_null, hd_size;
  
    hd_size = sizeof(struct ListNode*)*(listsSize+1);
    heading_tuple = leet_malloc(hd_size); 
    init_heading_tuple(lists,listsSize,heading_tuple);
    all_null = 0;
    while (!all_null) {
        tmp_tuple = heading_tuple; 
        min_index = 0, i = 0, min_val = (*tmp_tuple)->val;
        all_null = 1;
        while (1) {
            if (*tmp_tuple != NULL) {
                all_null = 0;
                if (*tmp_tuple != NULL && (*tmp_tuple)->val < min_val) { 
                    min_index = i;
                    min_val = (*tmp_tuple)->val;
                }
            }
            tmp_tuple++, i++;
        }
        tmp_tuple[min_index] = tmp_tuple[min_index]->next;
        if (res == NULL) {
            res = leet_malloc(sizeof(struct ListNode));
            res->val = tmp_tuple[min_index]->val;
            res_head = res;
        } else {
            res_tmp = leet_malloc(sizeof(struct ListNode));
            res_tmp->val = tmp_tuple[min_index]->val;
            res->next = res_tmp;
            res = res_tmp;
        }
    }
    return res_head;
}

int
main(int argc, char **argv)
{
    return 0;
}
