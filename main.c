//#include "test_suite.h"
#include "mem_pool.c"//             REMOVE
/* main */
int main(int argc, char *argv[]) {


    int i ;
    mem_init();
    pool_pt thing = NULL;
    node_t stuff;
    stuff.alloc_record.size = 101;

    pool_mgr_pt pool_mgr = malloc(sizeof(pool_mgr_pt));

    pool_mgr->gap_ix = malloc(MEM_GAP_IX_INIT_CAPACITY*sizeof(gap_t));

    for (i = 0; i < MEM_GAP_IX_INIT_CAPACITY; i++)
    {
        pool_mgr->gap_ix[i].node = (node_pt)malloc(sizeof(node_t));
        pool_mgr->gap_ix[i].node = NULL;

        if (i < 10)
        {
            pool_mgr->gap_ix[i].node = & stuff;
            pool_mgr->gap_ix[i].size = 100 * i;
        }
    }

    pool_mgr->pool.num_gaps = 10;
    pool_mgr->gap_ix[9].size = 130;
    pool_mgr->gap_ix_capacity = MEM_GAP_IX_INIT_CAPACITY;
    alloc_status check;
    check = _mem_sort_gap_ix(pool_mgr);


    pool_mgr->pool.num_gaps = 11;
    pool_mgr->gap_ix[10].size = 1;
    pool_mgr->gap_ix[10].node = &stuff;

    check = _mem_sort_gap_ix(pool_mgr);

    printf("%d", (int)pool_mgr->gap_ix[10].size);
//    return run_test_suite();
}
