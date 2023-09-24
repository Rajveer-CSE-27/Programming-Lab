#!/bin/bash

# Define a range of probabilities
probabilities=(0 10 20 ... 100)

for start_prob in "${probabilities[@]}"; do
    for ins_prob in "${probabilities[@]}"; do
    
        /usr/bin/time -o time_space_output.txt -v ./your_program --start_prob $start_prob --ins_prob $ins_prob > program_output.txt 2> program_error.txt

        # Append the extracted data to a summary file in LaTeX table format
        echo "\\hline" >> summary_table.tex
        echo "$start_prob & $ins_prob & $runtime & $memory_usage \\\\" >> summary_table.tex
    done
done


