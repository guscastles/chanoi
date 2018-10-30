#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "hanoi_func.h"

struct Test {
    char *name;
    void (*func)(void);
};

void test_left_pin(void) {
    int *left = left_pin(0);
    left[2] = 1;
    CU_ASSERT(left[1] == 0);
    CU_ASSERT(left[2] == 1);
}

void run(struct Test *tests){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("hanoi_test", 0, 0);
    CU_add_test(suite, tests[0].name, tests[0].func);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}

int main(void) {
    struct Test tests[1];
    strcpy(tests[0].name, "test_left_pin");
    tests[0].func = test_left_pin;
    run(tests);
    return 0;
}

