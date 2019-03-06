#include <linux_config.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct nlist_s nlist;
struct nlist_s {
    int val;
    nlist next;
};

void *
leet_malloc(size_t size)
{
    void *res = malloc(size);
    memset(res,0,size);
    return res;
}

void
append_list(nlist **head, int val)
{
    int count;
    nlist *pre,*tmp,*nw; 
    if (*head == NULL) {
        *head = leet_malloc(sizeof(nlist));
        tmp = *head;
        tmp->val = val;
    } else {
        tmp = *head; pre = NULL;
        for (tmp=head,count=0; tmp->next!=NULL; tmp++,count++) {
            if (count < 5) {
                if (val < tmp->val) {
                    nw = leet_malloc(sizeof(nlist));
                    nw->val = val; 
                    nw->next = tmp;
                    if (pre == NULL) {
                        *head = nw;
                    } else {
                        pre->next = nw;
                    }
                }
            } else {
                pre->next = NULL; 
                free(tmp);
            }
            pre = tmp;
        }
    }
}

void
doKthSmallest(struct TreeNode* root, int k, nlist **head)
{
    int val = root->val;
    append_list(head,val);
    if (root->left != NULL) {
        doKthSmallest(root->left,head);
    }
    if (root->right != NULL) {
        doKthSmallest(root->right,head);
    }
}

int
kthSmallest(struct TreeNode* root, int k)
{
    int i;
    nlist *head = NULL; 
    doKthSmallest(root,k,&head);
    for (int i=0; i<4; i++) {
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
