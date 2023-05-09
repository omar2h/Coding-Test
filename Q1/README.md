## Development Environment:
- Operating System: Windows 10 (64 bit)
- Compiler: gcc (x86_64-posix-seh-rev2, Built by MinGW-W64 project) 12.2.0

## How to compile and run
- Open a terminal and navigate to the directory having the source code
- Run the following command to compile:
  - gcc fib.c -o fib
- Run the following command to execute and run:
  - fib

## Implementation
- Added a parameter (isNode) to the addFun, subFun and mulFun to indicate whether the passed arguments are integers or nodes as C doesn't support function overloading

- makeFunc returns a function pointer to the specified arithmetic operation

