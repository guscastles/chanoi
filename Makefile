#hanoi.c test_hanoi.c
SRC=src
HDR=hdr
TST_SRC=test_hanoi.c
EXE=hanoi
BIN=bin
TST_EXE=test_hanoi
TST=tst
DEST=~/bin
CC=gcc
DBG=-g
ODIR=obj
_OBJ=hanoi.o hanoi_func.o
_TST_OBJ=test_hanoi.o hanoi_func.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
TST_OBJ=$(patsubst %,$(ODIR)/%,$(_TST_OBJ))

all: run

$(ODIR)/%.o: $(SRC)/%.c
	$(CC) $(DBG) -c -o $@ $< -I $(HDR)

$(EXE): $(OBJ)
	$(CC) -o $(BIN)/$@ $^

install: $(EXE)
	cp $(BIN)/$< $(DEST)

run: 
	$(EXE)

test_hanoi: $(TST_OBJ)
	$(CC) $(DBG) -o $@ $^ -lcunit

test: $(TST_EXE)
	$(TST)/$<

clean:
	rm -f $(BIN)/* $(TST)/$(TST_EXE) $(ODIR)/*.o

uninstall:
	rm $(BIN)/$(EXE)
