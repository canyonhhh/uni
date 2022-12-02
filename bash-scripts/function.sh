#!/bin/bash
#
# Display functions in dmenu
# Outputs selected function,
# which can be typed out using vim

shopt -s lastpipe

cd ~/doc/uni/procprog
ctags -R # Refresh tags

line=$(grep "\sf\s" ~/doc/uni/procprog/tags | sort -u | dmenu -l 20)
echo $line | cut -d ' ' -f2 | read location
location="/home/joris/doc/uni/procprog/${location}"

echo $line | cut -d '^' -f2 | cut -d '$' -f1 | read function

grep -nF "$function" $location | cut -d ':' -f1 | read firstLine

grep -n '^}' $location | cut -d ':' -f1 | awk -v r=$firstLine '$1>r' | sed 1q | read lastLine

sed "$firstLine,$lastLine!d" $location
