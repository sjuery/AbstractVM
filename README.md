# Abstract VM

AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.

## AbstractVM Example

![alt text](https://raw.githubusercontent.com/sjuery/AbstractVM/master/image/visualizer.gif)

## Description

The main aim of the project was to force us to use C++ functions and methods we will most likely need to use in the future.
A virtual machine is nothing more than a program that simulates a physical machine,
or another virtual machine. Nevertheless, it is clear that a virtual machine that emulates
a physical machine such as a desktop computer is a very advanced program that requires
an important programming experience as well as a very in-depth architectural knowledge.
For this project, requirements will be limited to a very simple virtual machine: it will
run some basic arithmetic programs coded in a very basic assembly language. If you want
to have an idea of what your program’s capabilities should look like, type the command
man dc in your shell.

### Installing

This Makefile has multiple instructions:

> abstractVM(Creates Project), clean(Removes extraneous files), and fclean(Cleans, and removes executable)
```
make
[...] Creating AbstractVM
g++ -Wall -Wextra -Werror -O3 -march=native -flto=thin -std=c++14 srcs/abstractVM.cpp srcs/IOperand.cpp srcs/VirtualMachine.cpp srcs/LexInput.cpp -o abstractVM
[ ✔ ] Created AbstractVM
```
Simply typing "make" will create the abstractVM executable

## Running the executables

### AbstractVM

The abstract VM executable can take input either from an Assembly Like file, or directly from standard input(Source File can be found below).

```
./abstractVM
$> PUSH INT8(16)
$> PUSH INT16(32)
$> ...
./abstractVM inputfile.s
$> results
```

## Valid Commands

```
1  S := INSTR [SEP INSTR]* #
2 
3  INSTR :=
4  push VALUE
5  | pop
6  | dump
7  | assert VALUE
8  | add
9  | sub
10 | mul
11 | div
12 | mod
13 | print
14 | exit
15
16 VALUE :=
17 int8(N)
18 | int16(N)
19 | int32(N)
20 | float(Z)
21 | double(Z)
22
23 N := [-]?[0..9]+
24
25 Z := [-]?[0..9]+.[0..9]+
26
27 SEP := '\n'+
```

### Valid source file

```
;---------------------
;- Valid Source File -
;---------------------

push int32(42)

push int32(33)

add ;comment

push float(44.55)

mul

push double(42.42)

;other comment

push int32(42)

dump

pop

assert double(42.42)

exit
```
