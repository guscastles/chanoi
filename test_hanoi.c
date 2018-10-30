#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include <malloc.h>
#include "hanoi_func.h"

#define SIZE(v) (sizeof(v) / sizeof(v[0]))

struct Test {
    char name[40];
    void (*func)(void);
};

void test_left_pin(void) {
    int *left = left_pin(0);
    left[2] = 1;
    CU_ASSERT(left[1] == 0);
    CU_ASSERT(left[2] == 1);
}

void test_right_pin(void) {
    int *right = right_pin(0);
    right[2] = 1;
    CU_ASSERT(right[1] == 0);
    CU_ASSERT(right[2] == 1);
}

void add_tests(CU_pSuite suite, struct Test *tests, int size) {
    for (int i = 0; i < size; ++i)
        CU_add_test(suite, tests[i].name, tests[i].func);
}

void run(struct Test *tests, int size){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("hanoi_test", 0, 0);
    add_tests(suite, tests, size);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}

void gather_tests(void (*run)()) {
    struct Test tests[2];
    strcpy(tests[0].name, "test_left_pin");
    tests[0].func = test_left_pin;
    strcpy(tests[1].name, "test_right_pin");
    tests[1].func = test_right_pin;
    run(tests, SIZE(tests));
}

int main(void) {
    gather_tests(run);

    return 0;
}

