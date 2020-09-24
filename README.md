# swapf

Command line tool for swapping 2 files or directories using the renameat2() function / system call.

## Requirements

Kernel >= 3.15

glibc >= 2.28

## Compilation

gcc -o swapf -Wall -Wextra -O3 main.c

## Usage

swapf path1 path2
