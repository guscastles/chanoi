#hanoi.c test_hanoi.c
SRC=src
INC=include
INCLUDE=$(HOME)/.local/include
TST_SRC=test_hanoi.c
EXE=hanoi
BIN=bin
TEXE=unittest
TST=test
DEST=~/bin
CC=gcc
ODIR=obj
TODIR=obj/test
_OBJ=hanoi_func.o
_TOBJ=unittest.o test_hanoi.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
TOBJ=$(patsubst %,$(TODIR)/%,$(_TOBJ))

all: run

$(TODIR)/%.o: $(TST)/%.c
	$(CC) -Wall $(DEBUG) -c -o $@ $< -iquote $(INC) -I $(INCLUDE)

$(ODIR)/%.o: $(SRC)/%.c
	$(CC) -Wall $(DEBUG) -c -o $@ $< -iquote $(INC) -I $(INCLUDE)

$(EXE): $(OBJ) obj/hanoi.o
	$(CC) -Wall -o $(BIN)/$@ $^ -L $(LD_LIBRARY_PATH) -llist

run: $(EXE) 
	$(BIN)/$<

unittest: $(TOBJ) $(OBJ)
	$(CC) -Wall $(DEBUG) -o $(BIN)/$@ $^ -lcunit -iquote $(INC)/ -L $(LD_LIBRARY_PATH) -llist 

test: $(TEXE)
	$(BIN)/$<

clean:
	rm -f $(BIN)/* $(ODIR)/*.o $(TODIR)/*.o

install: $(EXE)
	cp $(BIN)/$< $(DEST)

uninstall:
	rm $(DEST)/$(EXE)

debug: unittest
	$(eval DEBUG=-g)
	gdb $(BIN)/$<
