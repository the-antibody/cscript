# cscript
An interpreter that allows you to script in C.

# About
cscript (csc) is an interpreter that allows you to script in C while keeping the raw C performance. This way you don't have to compile, and you can write programs at a similar pace to python.

# Installation
To install the cscript interpreter, open a terminal and type these commands:
```sh
git clone https://github.com/the-antibody/cscript
cd cscript
sudo make install
```

# Usage
**To write a cscript program, create a file ending in the `.csc` extension.**<br />
<br />
Here's an example of some cscript code:
```c
// you can import headers like this
import unistd

printf("Hello World!\n");

for (int i = 0; i < 5; i++)
  printf("%d\n", i);
  
// no return necessary
```
To run your program with the interpreter, type this into your terminal:
```sh
csc scriptname.csc
```
