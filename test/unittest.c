#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "unittest.h"

#define SIZE(v) (sizeof(v) / sizeof(v[0]))

typedef struct unittest {
    char name[40];
    void (*func)(void);
} Test;

void add_tests(CU_pSuite suite, Test *tests, int size, int next) {
    if (next < size) {
       CU_add_test(suite, tests[next].name, tests[next].func);
       add_tests(suite, tests, size, next + 1);
    }
}

int runme(Test *tests, int size) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("hanoi_test", 0, 0);
    add_tests(suite, tests, size, 0);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    unsigned int errors = CU_get_number_of_tests_failed();
    CU_cleanup_registry();
    return errors;
}

int gather_tests(int (*run)()) {
    int size = SIZE(names);
    Test tests[size];
    for (int i = 0; i < size; ++i) {
        strcpy(tests[i].name, names[i]);
        tests[i].func = functions[i];
    }
    return run(tests, SIZE(tests));
}

int main(void) {
    unsigned int errors = gather_tests(runme);
    printf("\n#### Errors: %d ####\n", errors);
    return errors;
}

