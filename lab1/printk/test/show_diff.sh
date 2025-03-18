#!/bin/bash

INPUT_FILE_DIR="test_data/input"
STD_OUTPUT_DIR="test_data/std_output"
TEST_OUTPUT_DIR="test_out"

if [ ! -d "${TEST_OUTPUT_DIR}" ]
then
    echo "output directory: ${TEST_OUTPUT_DIR} doesn't exist. Run \"make test\" first!"
    exit 1
fi

file_basename=${1}

test_output_path="${TEST_OUTPUT_DIR}/${file_basename}.out"
std_output_path="${STD_OUTPUT_DIR}/${file_basename}.out"

if [ ! -e "${test_output_path}" -o ! -e "${std_output_path}" ]
then
    echo "cannot find specific test: ${file_basename}"
    exit 1
fi

diff ${test_output_path} ${std_output_path}

