## Development Environment:

- Operating System: Windows 10 (64bit)
- Compiler: gcc (x86_64-posix-seh-rev2, Built by MinGW-W64 project) 12.2.0

## How to compile and run

- Open a terminal and navigate to the directory having the source code
- Run the following command to compile:
  - gcc q2.c -o q2
- Run the following command to execute and run:
  - q2

## Differences

### Recursive Approach f1

- Time Complexity: O(2^n)
- Space Complexity: O(2^n)
- Advantages:
  - Simple
- Disadvantages:
  - Slow and inefficient and causes overflow for large values of n

### Iterative approach f2

- Time Complexity: O(n)
- Space Complexity: O(1)
- Advantages:
  - more efficient
  - O(1) space complexity, uses less memory
- Disadvantages:
  - maybe less elegamt than the recursive

### Dynamic programming memoization f3

- Time Complexity: O(n)
- Space Complexity: O(n)
- Advantages:
  - less calculation than the iterative as it stores the past results
- Disadvantages:
  - uses more memory than the iterative
  - require large amount of memory for large values of n
