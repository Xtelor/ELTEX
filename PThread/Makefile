BIN := test
BINM := test_mutex
SOURCES := test.c
SOURCESM := test_mutex.c
HEADERS := 
CC := gcc
CFLAGS :=
LDFLAGS := -lpthread

.PHONY: 1 
1: $(BIN) b 

$(BIN): $(SOURCES)
		$(CC) $(SOURCES) -o $(BIN) $(CFLAGS) $(LDFLAGS)
b:		
		./$(BIN)
$(BIN): $(HEADERS)

.PHONY: 2
2: $(BINM) b2

$(BINM): $(SOURCESM)
		$(CC) $(SOURCESM) -o $(BINM) $(CFLAGS) $(LDFLAGS)
b2:
		./$(BINM)
$(BINM): $(HEADERS)

.PHONY: cl
cl:
		rm -rf $(BIN) 
		rm -rf $(BINM)
		clear
