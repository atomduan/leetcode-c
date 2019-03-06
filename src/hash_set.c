/**
 * Quick sort DEMO
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

leet_hash_set *
leet_hash_set_new()
{
    leet_hash_set *res = leet_malloc(sizeof(leet_hash_set));
    res->slot_size = LEET_SET_SLOT_SIZE;
    leet_hash_node **slot = leet_malloc(LEET_SET_SLOT_SIZE*sizeof(leet_hash_node *));
    res->slot = slot;
    return res;
}

int
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

int
main(int argc,char **argv)
{
    return 0;
}
