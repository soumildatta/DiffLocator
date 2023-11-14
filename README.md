# DiffLocator

A simple console-based utility written in C++ that compares two text files and displays the differences character by character. Mimics the functionality of the __diff__ UNIX command to compare files, but this utility compares individual characters instead of whole lines. It reads two files as input and then uses the Longest Common Subsequence (LCS) algorithm to find and display the differences between them. Differences are color-coded for added clarity.

Developed for a class project, but found it to be useful in other applications. 

## Instructions to run
First compile the code with 
```
make
```

The code can then be run with the command and arguments:
```
./difflocator <filename1> <filename2>
```
