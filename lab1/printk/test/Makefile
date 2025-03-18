.PHONY: generate clean

AWK						:= awk
SHELL					:= bash
CC						:= gcc
CFLAGS					:= -Wall -Wextra -g

SOURCE_DIR				:= src
INPUT_DIR				:= test_data/input
GENERATED_SOURCES_DIR	:= generated_source
TEST_PROGRAM_DIR		:= test_prog
TEST_OUTPUT_DIR			:= test_out
STD_OUTPUT_DIR			:= test_data/std_output

INPUT_FILES				= $(wildcard $(INPUT_DIR)/*.in)
SOURCE_FILES			= $(wildcard $(SOURCE_DIR)/*.c)
GENERATED_SOURCES		= $(patsubst $(INPUT_DIR)/%.in,$(GENERATED_SOURCES_DIR)/%.c,$(INPUT_FILES))
TEST_PROGRAMS			= $(patsubst $(INPUT_DIR)/%.in,$(TEST_PROGRAM_DIR)/%,$(INPUT_FILES))
TEST_OUTPUTS			= $(patsubst $(INPUT_DIR)/%.in,$(TEST_OUTPUT_DIR)/%.out,$(INPUT_FILES))
STD_OUTPUTS				= $(patsubst $(INPUT_DIR)/%.in,$(STD_OUTPUT_DIR)/%.out,$(INPUT_FILES))

$(GENERATED_SOURCES_DIR)/%.c: $(INPUT_DIR)/%.in in_to_c.awk
	@$(AWK) -f in_to_c.awk $< > $@

$(TEST_PROGRAM_DIR)/%: $(GENERATED_SOURCES_DIR)/%.c $(SOURCE_FILES)
	@$(CC) $(CFLAGS) $^ -o $@ 

$(TEST_OUTPUT_DIR)/%.out: $(TEST_PROGRAM_DIR)/% $(INPUT_DIR)/%.in
	@echo Running Test $(patsubst $(TEST_PROGRAM_DIR)/%,%,$^)...
	@$< < $(patsubst $(TEST_PROGRAM_DIR)/%,$(INPUT_DIR)/%.in,$^) > $@

test: $(INPUT_FILES) $(TEST_OUTPUTS) $(STD_OUTPUTS) check.sh
	@$(SHELL) check.sh $(INPUT_DIR) $(TEST_OUTPUT_DIR) $(STD_OUTPUT_DIR)

generate:
	$(MAKE) -C ../generate

	cp ../generate/input/* ./test_data/input/
	cp ../generate/std_output/* ./test_data/std_output/

	$(MAKE) -C ../generate clean


source: $(GENERATED_SOURCES)
compile: $(TEST_PROGRAMS)

clean:
	rm -f $(GENERATED_SOURCES_DIR)/*
	rm -f $(TEST_PROGRAM_DIR)/*
	rm -f $(TEST_OUTPUT_DIR)/*