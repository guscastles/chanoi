# Installing and Using CUnit

## CUnit Website

> http://cunit.sourceforge.net/index.html

## Steps towards Usage

- Download and unzip it 
- README
    - bootstrap
    - configure
    - make
    - make install 

## Compilation (WIP)

```
gcc -Wall -o test test_hanoi.c -I ./CUnit/Headers/ -lcunit -L /usr/local/lib/libcunit.so.1
```

## Execution

```
./test
```

## Key Code

```
void add_tests(CU_pSuite suite, struct Test tests[], int size) {
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
}.
```
