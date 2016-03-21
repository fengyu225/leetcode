#!/bin/bash

cnt=0;
IFS=$'\n'
for line in `cat file.txt`; do
    cnt=$((cnt + 1))
    if [[ $cnt == 10 ]]; then 
        echo $line;
    fi
done;

# Solution 2
awk 'FNR == 10 {print }'  file.txt
# OR
awk 'NR == 10' file.txt

# Solution 3
sed -n 10p file.txt

# Solution 4
tail -n+10 file.txt|head -1