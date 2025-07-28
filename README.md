# push\_swap

![Language](https://img.shields.io/badge/language-C-blue)
![Status](https://img.shields.io/badge/build-passing-brightgreen)

`push_swap` is a 42 school project that challenges you to sort a list of integers using only a restricted set of stack operations. The main objective is to produce an optimized sequence of operations with the least possible moves.

---

## 📌 Table of Contents

* [About](#about)
* [Features](#features)
* [Project Structure](#project-structure)
* [Algorithm Overview](#algorithm-overview)
* [How to Compile](#how-to-compile)
* [Usage Example](#usage-example)
* [Bonus Part](#bonus-part)
* [📊 Performance & Complexity](#performance--complexity)
* [Code Snippets](#code-snippets)
* [Learnings](#learnings)
* [License](#license)

---

## 📖 About

The goal of this project is to:

* Implement a sorting algorithm with stack-based operations.
* Optimize the number of operations needed to sort.
* Deepen your understanding of data structures, particularly doubly linked lists.
* Implement a robust parsing and validation system.

---

## ✨ Features

### Mandatory:

* Input validation (including duplicates, non-integers, and overflow handling)
* Two stacks (`a` and `b`) represented as doubly linked lists
* Sorting algorithms optimized by input size:

  * 2 or 3 elements: hardcoded optimal strategy
  * > 3 elements: "Turk Sort" strategy (a variant of quicksort)
* Full memory management (no leaks)

### Bonus:

* A `checker` program that reads instructions from `stdin` and applies them to verify sorting correctness
* Own implementation of `get_next_line` used in `checker`

---

## 📁 Project Structure

```bash
.
├── inc/push_swap.h                  # Header for core implementation
├── bonus_inc/checker.h              # Header for bonus checker
├── src/
│   ├── push_swap.c                  # Main logic for push_swap
│   ├── turk_sort.c                  # Sorting algorithm for large inputs
│   ├── move.c                       # Move execution helpers
│   ├── stack_utils.c                # Stack manipulation (add, min, max...)
│   ├── sort_three.c                 # Specific strategy for 3 elements
│   ├── initialize_stack.c           # Stack init and ft_atoi
│   ├── check_validity.c             # Input validation
│   ├── prepare_a_to_b.c             # A -> B transfer planning
│   ├── prepare_b_to_a.c             # B -> A transfer planning
│   ├── swap_operation.c             # sa, sb, ss operations
│   ├── push_operation.c             # pa, pb operations
│   ├── rotate_operation.c           # ra, rb, rr operations
│   ├── reverse_rotate_operation.c   # rra, rrb, rrr operations
│   ├── ft_split.c / ft_substr.c     # Utilities
├── bonus_src/
│   ├── checker.c                    # Bonus program to test correctness
│   ├── checker_utils.c              # Bonus instruction parser
│   ├── get_next_line.c              # Bonus file reader
│   ├── get_next_line_utils.c        # Helpers for gnl
```

---

## 🧠 Algorithm Overview

### Turk Sort Strategy:

1. Push all but 3 smallest values to stack B.
2. Sort remaining 3 elements in A using `sort_three()`.
3. Push back from B to A in optimized positions using minimal operations.
4. Rotate final stack A until smallest number is on top.

### Decision Making:

* Each node in stack A stores:

  * Its index
  * Its target in B
  * A calculated "push price"
  * If it’s the current cheapest

### Bonus: Checker

* Reads commands (`sa`, `pb`, `rrr`, etc.) from stdin.
* Applies them to internal stacks.
* Verifies whether the final result is sorted.

---

## 📅 How to Compile

### Mandatory:

```bash
make
./push_swap 3 2 1 6 5 8
```

### Bonus (Checker):

```bash
make bonus
./push_swap 2 1 3 | ./checker 2 1 3
```

To test manually:

```bash
./checker 2 1 3
pb
ra
pa
<CTRL-D>
```

---

## 🔍 Usage Example

```bash
$ ./push_swap 2 1 3
pb
sa
pa
```

```c
int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    if (argc > 1)
    {
        create_stack(&a, argv + 1, false);
        sort(&a, &b);
        free_stack(&a);
        free_stack(&b);
    }
    return (0);
}
```

---

## 🚀 Bonus Part

### Checker Program

* Reads from standard input using a custom `get_next_line`.
* Applies each command on stacks A and B.
* Outputs `OK` if stack A is sorted and stack B is empty, `KO` otherwise.

---

## 📊 Performance & Complexity

### Benchmarks

| Input Size | Average Moves | Worst Case Moves |
| ---------- | ------------- | ---------------- |
| 3          | ≤ 2           | 2                |
| 5          | ≤ 12          | 12               |
| 100        | \~700         | < 1500           |
| 500        | \~5000        | < 11500          |

### Time Complexity

* Small input (n ≤ 3): `O(1)`
* General case: \~`O(n log n)` in practice
* Worst-case: `O(n^2)` due to multiple rotations and stack state management

### Space Complexity

* `O(n)` for stack structures
* `O(n)` temporary allocations (e.g., ft\_split)
* `O(1)` static buffer in `get_next_line`

---

## 💡 Code Snippets

### Swap Operation

```c
void sa(t_stack **a, bool checker)
{
    if (!a || !*a || stack_len(*a) < 2)
        return;
    // Swap top two nodes
    *a = (*a)->next;
    (*a)->prev->prev = *a;
    (*a)->prev->next = (*a)->next;
    if ((*a)->next)
        (*a)->next->prev = (*a)->prev;
    (*a)->next = (*a)->prev;
    (*a)->prev = NULL;
    if (!checker)
        write(1, "sa\n", 3);
}
```

### Cheapest Move Detection

```c
void update_cheapest(t_stack *stack)
{
    long cheapest = LONG_MAX;
    while (stack)
    {
        if (stack->price < cheapest)
        {
            cheapest = stack->price;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheapest = true;
}
```

---

## 📚 Learnings

* Doubly linked lists (with additional metadata per node)
* Efficient string and memory handling in C
* Handling edge cases: overflows, duplicates, empty args
* Complexity trade-offs in constrained environments
* Robust input parsing and command dispatch

---

## 📄 License

This project is part of the 42 School curriculum and is meant for educational use.

---

## 💬 Questions?

Feel free to fork, open issues, or reach out!
