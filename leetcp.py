#!/usr/bin/python

import re, sys

if len(sys.argv) == 1:
    sys.exit(1)
file_name = str(sys.argv[1])
content = ""
with open(file_name, "r") as f:
    content = f.read()
new_content = ""
m = re.search("\/\*[.\s]*\*\/", content)
try:
    new_content += re.search(r'/\*.*?\*/', content, re.MULTILINE|re.DOTALL).group(0)
except:
    pass
try:
    new_content += "\n\n#include \"header.h\"\n\n\n\n"
    new_content += re.search(r"int\ +main.*$", content, re.DOTALL|re.MULTILINE).group(0)
except:
    pass
with open(file_name, "w") as f:
    f.write(new_content)
