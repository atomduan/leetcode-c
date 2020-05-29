#include <let_config.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct nlist {
    int val;
    struct nlist *next;
};

void *
leet_malloc(size_t size)
{
    void *res = malloc(size);
    memset(res,0,size);
    return res;
}

void
append_sort_list(struct nlist **head_pt, int val, int k)
{
    int count, add_flag, kbar;
    kbar = k+1;
    struct nlist *pre,*tmp,*nw;
    if (*head_pt == NULL) {
        *head_pt = leet_malloc(sizeof(struct nlist));
        tmp = *head_pt;
        tmp->val = val;
    } else {
        tmp = *head_pt; pre = NULL; add_flag=0;
        for (count=0; tmp!=NULL; count++) {
            if (count < kbar) {
                if (val < tmp->val) {
                    nw = leet_malloc(sizeof(struct nlist));
                    nw->val = val;
                    if (pre == NULL) {
                        *head_pt = nw;
                    } else {
                        pre->next = nw;
                    }
                    nw->next = tmp;
                    add_flag = 1;
                }
            }
            //clean tail, if tmp is the last
            if (tmp->next==NULL && count>=kbar && add_flag==1) {
                pre->next = NULL;
                free(tmp);
                break;
            } else {
                pre = tmp;
                tmp = tmp->next;
            }
        }
    }
}

void
doKthSmallest(struct TreeNode* root, int k, struct nlist **head_pt)
{
    int val = root->val;
    append_sort_list(head_pt,val,k);
    if (root->left != NULL) {
        doKthSmallest(root->left,k,head_pt);
    }
    if (root->right != NULL) {
        doKthSmallest(root->right,k,head_pt);
    }
}

int
kthSmallest(struct TreeNode* root, int k)
{
    int i;
    struct nlist *head = NULL;
    doKthSmallest(root,k,&head);
    for (i=0; i<k-1; i++) {
        head++;
    }
    return head->val;
}

/**
 * TODO need implemented
 */
int
main(int argc,char **argv)
{
    return 0;
}
