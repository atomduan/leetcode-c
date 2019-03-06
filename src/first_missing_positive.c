/**
 * Given an unsorted integer array, find the smallest missing positive integer.
 *
 * Example 1:
 * Input: [1,2,0]
 * Output: 3
 *
 * Example 2:
 * Input: [3,4,-1,1]
 * Output: 2
 *
 * Example 3:
 * Input: [7,8,9,11,12]
 * Output: 1
 *
 * Note:
 * Your algorithm should run in O(n) time and uses constant extra space.
 */
#include <linux_config.h>

#define LEET_SET_SLOT_SIZE 73

typedef struct leet_hash_node_s leet_hash_node;
struct leet_hash_node_s {
    int val;
    leet_hash_node *next;
};

typedef struct leet_hash_set_s leet_hash_set;
struct leet_hash_set_s {
    leet_hash_node **slot;
    int slot_size;
};

static void *
leet_malloc(size_t size)
{
    void *res = malloc(size);
    memset(res,0,size);
    return res;
}

static leet_hash_node *
leet_hash_node_new(int val)
{
    leet_hash_node *res = leet_malloc(sizeof(leet_hash_node));
    res->val = val;
    return res;
}

static int
leet_hash_code(leet_hash_set *set, int key)
{
    int slot_size = set->slot_size;
    key = key<0 ? -key:key;
    return key % slot_size;
}

static leet_hash_set *
leet_hash_set_new()
{
    leet_hash_set *res = leet_malloc(sizeof(leet_hash_set));
    res->slot_size = LEET_SET_SLOT_SIZE;
    leet_hash_node **slot = leet_malloc(LEET_SET_SLOT_SIZE*sizeof(leet_hash_node *));
    res->slot = slot;
    return res;
}

static int
leet_hash_set_put(leet_hash_set *set, int key)
{
    int hc = leet_hash_code(set,key);
    leet_hash_node **slot = set->slot;
    leet_hash_node *entry = slot[hc];
    if (entry == NULL) {
        slot[hc] = leet_hash_node_new(key);
        return 1;
    } else {
        while (entry != NULL) {
            if (entry->val == key)  return 0;
            if (entry->next != NULL) {
                entry = entry->next;
                continue;
            } else {
                entry->next = leet_hash_node_new(key);
                return 1;
            }
        }
    }
    return 0;
}

static int*
leet_dedup_nums(int* nums, int *numsSize)
{
    int nsz = *numsSize;
    int *res = leet_malloc((nsz+1)*sizeof(int));
    int i=0,j=0;
    leet_hash_set *dict = leet_hash_set_new();
    for (i=0,j=0; i<nsz; i++) {
        if (nums[i] <= 0) continue;
        if (leet_hash_set_put(dict,nums[i])) {
            res[j++] = nums[i];
        }
    }
    *numsSize = j;
    free(dict);
    return res;
}

int
firstMissingPositive(int* nums, int numsSize)
{
    int i, min, max, posn, *dict, idx;
    max = 0;
    min = INT_MAX;
    posn = 0;

    //dedup nums
    nums = leet_dedup_nums(nums,&numsSize);

    //statistic
    for (i=0; i<numsSize; i++) {
        if (nums[i]>0 && nums[i]>max) max = nums[i];
        if (nums[i]>0 && nums[i]<min) min = nums[i];
        if (nums[i]>0) posn++;
    }
    if (min >  1) return 1;
    if (max <= 0) return 1;
    if (min+posn-1 < max) {
        dict = leet_malloc((posn+1)*sizeof(int));
        for (i=0; i<numsSize; i++) {
            if (nums[i]<=0) continue;
            if (min+posn < nums[i]) continue;
            idx = nums[i] - min;
            dict[idx] = 1;
        }
        for (i=0;;i++)
           if (dict[i] == 0)  return i+min;
    } else {
        return max+1;
    }
}

int
main(int argc, char **argv)
{
    //int nums[] = {7,8,9,11,12};
    //int nums[] = {3,4,-1,1};
    //int nums[] = {0,1,2};
    int nums[] = {1,3,3,76,76};
    int numsSize = sizeof(nums)/sizeof(int);
    int result = firstMissingPositive(nums,numsSize);
    printf("result is :%d\n", result);
    return 0;
}
