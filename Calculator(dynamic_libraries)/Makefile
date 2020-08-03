BIN := calc_d
LIB := calc_dl
SOURCES := main.c
LIB_SOURCES := menu.c sum.c subtraction.c multiplication.c division.c 
HEADERS := header.h
CC := gcc
CFLAGS := 
LDFLAGS := 

.PHONY: r
r: $(LIB) $(BIN) cl

$(LIB): $(LIB_SOURCES)
		$(CC) -fPIC -c $(LIB_SOURCES)
		$(CC) -shared -o lib$(LIB).so *.o

$(BIN): $(SOURCES)
		$(CC) $(SOURCES) -L. -l$(LIB) -o $(BIN)
		$(CC) -c $(SOURCES)
		$(CC) main.o -L. -l$(LIB) -o $(BIN)
		$ LD_LIBRARY_PATH=. ./$(BIN)

#$(BIN): $(HEADERS)

.PHONY: cl
cl:
	rm -rf $(BIN)
	rm -rf lib$(LIB).so
	rm -rf *.o && clear
