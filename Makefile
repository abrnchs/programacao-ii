CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -O2

SOURCE_DIR := parte-1/Se1
BIN_DIR := build/parte-1/Se1
PROGRAMS := prog11 prog12 prog13 prog14 prog15
TARGETS := $(addprefix $(BIN_DIR)/,$(PROGRAMS))

.PHONY: all clean

all: $(TARGETS)

$(BIN_DIR):
	mkdir -p $@

$(BIN_DIR)/prog11: $(SOURCE_DIR)/prog11.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BIN_DIR)/prog12: $(SOURCE_DIR)/prog12.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BIN_DIR)/prog13: $(SOURCE_DIR)/prog13.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BIN_DIR)/prog14: $(SOURCE_DIR)/prog14.c $(SOURCE_DIR)/norm.c $(SOURCE_DIR)/norm.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(SOURCE_DIR)/prog14.c $(SOURCE_DIR)/norm.c

$(BIN_DIR)/prog15: $(SOURCE_DIR)/prog15.c $(SOURCE_DIR)/norm.c $(SOURCE_DIR)/norm.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(SOURCE_DIR)/prog15.c $(SOURCE_DIR)/norm.c

clean:
	rm -rf build
