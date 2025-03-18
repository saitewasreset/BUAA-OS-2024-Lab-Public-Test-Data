.PHONY: clean

AWK						:= awk
SED						:= sed
CC						:= gcc
CFLAGS					:= -Wall -Wextra -g

INPUT_DIR				:= input
GENERATED_SOURCES_DIR	:= generated_source
STD_PROGRAM_DIR			:= test_prog
STD_OUTPUT_DIR			:= std_output

INPUT_FILES				:= $(wildcard $(INPUT_DIR)/*.in)
GENERATED_SOURCES		:= $(patsubst $(INPUT_DIR)/%.in,$(GENERATED_SOURCES_DIR)/%.c,$(INPUT_FILES))
STD_PROGRAMS			:= $(patsubst $(INPUT_DIR)/%.in,$(STD_PROGRAM_DIR)/%,$(INPUT_FILES))
STD_OUTPUTS				:= $(patsubst $(INPUT_DIR)/%.in,$(STD_OUTPUT_DIR)/%.out,$(INPUT_FILES))

all: $(STD_OUTPUTS)

$(GENERATED_SOURCES_DIR):
	mkdir -p $(GENERATED_SOURCES_DIR)

$(STD_PROGRAM_DIR):
	mkdir -p $(STD_PROGRAM_DIR)

$(STD_OUTPUT_DIR):
	mkdir -p $(STD_OUTPUT_DIR)

$(GENERATED_SOURCES_DIR)/%.c: $(INPUT_DIR)/%.in in_to_c.awk
	$(AWK) -f in_to_c.awk $< > $@

$(STD_PROGRAM_DIR)/%: $(GENERATED_SOURCES_DIR)/%.c
	$(CC) $(CFLAGS) $^ -o $@

$(STD_OUTPUT_DIR)/%.out: $(STD_PROGRAM_DIR)/%
	$^ < $(patsubst $(STD_PROGRAM_DIR)/%,$(INPUT_DIR)/%.in,$^) > $@

source: $(GENERATED_SOURCES_DIR) $(GENERATED_SOURCES)
compile: $(STD_PROGRAM_DIR) $(STD_PROGRAMS)
generate: $(STD_OUTPUT_DIR) $(GENERATED_SOURCES_DIR) $(STD_PROGRAM_DIR) $(STD_OUTPUTS)

clean:
	rm -f $(GENERATED_SOURCES_DIR)/*
	rm -f $(STD_PROGRAM_DIR)/*
	rm -f $(STD_OUTPUT_DIR)/*