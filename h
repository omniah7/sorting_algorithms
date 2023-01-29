#!/usr/bin/bash
for f in  sort.h 3-quick_sort.c
do
    git update-index --chmod=+x $f
    #betty $f
    
done
