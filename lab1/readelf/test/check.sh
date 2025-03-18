#!/bin/bash

INPUT_FILE_DIR=${1}
TEST_OUTPUT_DIR=${2}
STD_OUTPUT_DIR=${3}

pass_count=0
total_count=0

for input_file in `ls ${1}`
do
    file_basename=`basename ${input_file}`

    test_output_path="${TEST_OUTPUT_DIR}/${file_basename}.out"
    std_output_path="${STD_OUTPUT_DIR}/${file_basename}.out"

    if diff ${test_output_path} ${std_output_path} > /dev/null
    then
        ((pass_count ++))
    else
        echo "Test: ${file_basename} Failed!"
    fi

    ((total_count ++))
done

failed_count=$((total_count - pass_count))
echo "Total = ${total_count} Passed = ${pass_count} Failed = ${failed_count}"

if [ "${pass_count}" -eq "${total_count}" ]
then
    echo "All Test Passed!"
fi