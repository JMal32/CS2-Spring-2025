# CS2 — Computer Science II (Spring 2025)

C++ coursework for Computer Science II, covering data structures, algorithm
analysis, sorting, searching, and hashing.

## Course topics

- Object-oriented C++ (classes, inheritance, operator overloading)
- Recursion and complexity analysis
- Linked lists, stacks, queues
- Sorting algorithms (bubble, insertion, quicksort, radix)
- Searching algorithms (binary, sequential)
- Hash tables
- Empirical timing and performance comparison

## Repository layout

| Folder | Topic |
|---|---|
| `classDemos/` | In-class examples and walkthroughs |
| `lab3/` | Stacks |
| `lab4/`, `lab4b/` | Linked lists; radix sort over a stack and a queue |
| `lab5a/`, `lab5b/` | Searching algorithms; hash tables |
| `lab6/`, `lab6b/` | Sorting algorithms and empirical timing |
| `finalExamNotes.md` | Study notes for the final exam |

Each lab folder generally contains source (`*.cpp`, `*.h`), a Makefile or
compiled binary, timing data (`*.csv`), and a lab report.

## Build

Most labs build with a simple `g++` invocation or the provided Makefile:

```sh
cd lab6
make
./sort
```

## Author

Justin Malone — [@JMal32](https://github.com/JMal32)
