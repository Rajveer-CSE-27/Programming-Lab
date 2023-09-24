#!/bin/bash

# Define a range of probabilities
probabilities=(0 10 20 ... 100)

# Loop through different probabilities
for start_prob in "${probabilities[@]}"; do
    for ins_prob in "${probabilities[@]}"; do
        # Run your program with specified parameters and collect time and space data
        /usr/bin/time -o time_space_output.txt -v ./your_program --start_prob $start_prob --ins_prob $ins_prob > program_output.txt 2> program_error.txt

        # Parse the output file to extract relevant performance metrics
        # (You'll need to implement this part based on your program's output format)
        # Example: extract runtime and memory usage from program_output.txt and program_error.txt

        # Append the extracted data to a summary file in LaTeX table format
        echo "\\hline" >> summary_table.tex
        echo "$start_prob & $ins_prob & $runtime & $memory_usage \\\\" >> summary_table.tex
    done
done


