#!/usr/bin/bash
for f in  sort.h 0-bubble_sort.c 1-insertion_sort_list.c 
do
    #git update-index --chmod=+x $f
    betty $f
    
done
