.PHONY: clean

CC					:= gcc
SHELL				:= bash
CFLAGS				:= -Wall -Wextra -g
INCLUDE				:= -Isrc

INPUT_DIR			:= test_data/input
TEST_OUTPUT_DIR		:= test_out
STD_OUTPUT_DIR		:= test_data/std_output
SOURCE_DIR			:= src
TEST_PROGRAM_DIR	:= test_prog

INPUT_FILES			:= $(wildcard $(INPUT_DIR)/*)
SOURCE_FILES		:= $(wildcard $(SOURCE_DIR)/*.c)
TEST_PROGRAM		:= $(TEST_PROGRAM_DIR)/readelf
TEST_OUTPUTS		:= $(patsubst $(INPUT_DIR)/%,$(TEST_OUTPUT_DIR)/%.out,$(INPUT_FILES))

$(TEST_PROGRAM): $(SOURCE_FILES)
	@$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

$(TEST_OUTPUT_DIR)/%.out: $(INPUT_DIR)/% $(TEST_PROGRAM)
	@$(TEST_PROGRAM) $< > $@

test: $(INPUT_FILES) $(TEST_OUTPUTS) $(STD_OUTPUTS) check.sh
	@$(SHELL) check.sh $(INPUT_DIR) $(TEST_OUTPUT_DIR) $(STD_OUTPUT_DIR)

compile: $(TEST_PROGRAM)

clean:
	rm -f $(TEST_PROGRAM_DIR)/*
	rm -f $(TEST_OUTPUT_DIR)/*