# Elevator Stop Optimization

A C programming project that explores algorithmic approaches to finding optimal elevator stops while minimizing the total number of floors passengers must walk.

Developed as a university assignment for the **Introduction to Programming** course (2022–2023).

## Problem

An elevator starts at the ground floor (floor 0). Each passenger has a destination floor, but the elevator can make at most a specified number of stops.

Passengers can walk from the ground floor or exit at the elevator stop closest to their destination. Walking up or down one floor costs one unit. The objective is to choose stops that **minimize the sum of walking costs** across all passengers. When multiple solutions have equal cost, lower elevator stops are preferred.

## Implemented approaches

The project contains three C implementations:

| File | Approach | Output |
| --- | --- | --- |
| `liftrec.c` | Recursive search using a cost recurrence | Minimum cost and last stop |
| `liftmem.c` | Recursive search with memoization | Minimum cost and last stop |
| `liftdp.c` | Memoized dynamic-programming recurrence with stop reconstruction | Cost table, chosen stops, and minimum cost |

`lift.c` provides the shared command-line input/output logic, and `solve.h` declares the solver interface.

**Note:** The original assignment also described a brute-force implementation and a bottom-up iterative dynamic-programming implementation. These are **not included** in this repository. Despite its filename, `liftdp.c` uses recursion with memoization rather than a fully iterative bottom-up algorithm.

## Build

A C compiler such as GCC is required. Compile each implementation separately, since each defines its own `solve()` function:

```bash
gcc -std=c11 -O2 lift.c liftrec.c -o liftrec
gcc -std=c11 -O2 lift.c liftmem.c -o liftmem
gcc -std=c11 -O2 lift.c liftdp.c -o liftdp
```

## Run

Run one of the compiled programs, then provide the passenger count, maximum number of stops, and destination floors:

```bash
./liftmem
5 2
11 2 7 13 7
```

Expected output:

```text
Last stop at floor 11
Cost is: 4
```

For the same input, `liftdp` also prints its cost table and the selected stops:

```text
Lift stops are: 7 11
Cost is: 4
```

## What this project demonstrates

- Recursive problem solving and optimization
- Memoization of overlapping subproblems
- Dynamic-programming recurrence relations
- Reconstructing selected stops from stored decisions
- Working with C arrays, pointers, and dynamic memory allocation
