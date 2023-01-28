#!/usr/bin/bash
for f in print_array.c print_list.c sort.h 0-bubble_sort.c 
do
    #git update-index --chmod=+x $f
    betty $f
    
done
