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

**Note:** currently error is

> ./test: error while loading shared libraries: libcunit.so.1: cannot open shared object file: No such file or directory

