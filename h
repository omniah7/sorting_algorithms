#!/usr/bin/bash
for f in  sort.h 2-selection_sort.c
do
    git update-index --chmod=+x $f
    #betty $f
    
done
