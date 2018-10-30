SRC=hanoi.c test_hanoi.c
TST_SRC=test_hanoi.c
EXE=hanoi
TST=test_hanoi
CC=gcc
ODIR=obj
_OBJ=hanoi.o hanoi_func.o
_TST_OBJ=test_hanoi.o hanoi_func.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
TST_OBJ=$(patsubst %,$(ODIR)/%,$(_TST_OBJ))

all: run

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

hanoi: $(OBJ)
	$(CC) -o $@ $^

run: hanoi
	chmod u+x $(EXE); ./$(EXE)

test_hanoi: $(TST_OBJ)
	$(CC) -o $@ $^ -lcunit

test: test_hanoi
	chmod u+x $(TST); ./$(TST)

clean:
	rm -f $(EXE) $(TST) $(ODIR)/*.o

