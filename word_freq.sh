#!/bin/bash

#   Write a bash script to calculate the frequency of each word in a text file words.txt.
#   
#   For simplicity sake, you may assume:
#   
#   words.txt contains only lowercase characters and space ' ' characters.
#   Each word must consist of lowercase characters only.
#   Words are separated by one or more whitespace characters.
#   For example, assume that words.txt has the following content:
#   
#   the day is sunny the the
#   the sunny is is
#   
#   Your script should output the following, sorted by descending frequency:
#   
#   the 4
#   is 3
#   sunny 2
#   day 1
#   
#   Don't worry about handling ties, it is guaranteed that each word's frequency count is unique.

while read line; do
    if [[ $line =~ ([0-9]+)\ ([A-Za-z]*) ]]; then
        echo ${BASH_REMATCH[2]} ${BASH_REMATCH[1]}
    fi
done < <(for i in `cat words.txt`;do echo $i;done | sort | uniq -c | sort -r) 

# grep -oE '[a-z]+' words.txt | sort | uniq -c | sort -r | awk '{print $2" "$1}' 
# sed -r 's/\s+/\n/g' words.txt | grep -v "^$" | sort | uniq -c | sort -r | awk '{print $2" "$1}'
