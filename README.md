*This project has been created as part of the 42 curriculum by tchemin, madufeal.*
# push_swap

## Table of Contents

- [Description](#description)

- [Big O Notation](#big-o-notation)

- [Instructions](#instructions)

    - [Compilation](#compilation)

    - [Usage](#usage)

- [Strategies](#strategies)

- [Output Format](#output-format)

- [Error Handling](#error-handling)

- [Benchmark Mode](#benchmark-mode)

- [Algorithmic Choices and Justification](#algorithmic-choices-and-justification)
    - [Min / Max Extraction](#min--max-extraction)
    - [Bucket Sort (Chunk-Based Sorting)](#bucket-sort-chunk-based-sorting)
    - [Radix Sort](#radix-sort)
- [Resources](#resources)

- [Project Constraints](#project-constraints)

- [Summary](#summary)

## Description

**push_swap** is a sorting program that orders a stack of integers using a limited set of predefined operations.
The goal is to sort stack a with the **smallest possible number of moves**, while respecting strict constraints.

The project embeds **four different sorting strategies**, each with a well-defined theoretical complexity, and supports **manual or adaptive strategy selection** based on input disorder.

## Big O Notation

Big O notation describes how the number of operations of an algorithm grows with input size.
It focuses on the order of growth, usually in the worst case, rather than exact execution time.

In this project, Big O notation is used to compare sorting strategies and justify their efficiency for different input sizes.

## Instructions
### Compilation

The project includes a Makefile that compiles all source files into a binary named push_swap.

```bash
make
```

**Requirements**

- No unnecessary relinking

- No global variables

### Usage
```bash
./push_swap [--bench] [strategy] <list of integers>
```

**Stack Format**

- Stack a is passed as command-line arguments

- The first argument represents the top of the stack

**Example**
```bash
./push_swap --adaptive 3 2 5 1 4
```

## Strategies

A strategy can be explicitly selected using one of the following flags:

| Flag      | Description                                        | Complexity |
|-----------|----------------------------------------------------|------------|
|--simple   | Naive sorting algorithm                            | O(n²)      |
|--medium   | Optimized chunk-based approach                     | O(n√n)     |
|--complex  | Advanced algorithm (e.g. radix / divide & conquer) | O(n log n) |
|--adaptive | Chooses the best strategy based on disorder        | Adaptive   |

### Notes

- ```--adaptive``` is the **default behavior**

- All strategies must work for **any input size or disorder**

- The claimed complexity class must be **valid in the push_swap model**

## Output Format

The program outputs only **push_swap operations**

- Operations are:

  - Printed to **stdout**

  - Separated by a single newline (\n)

  - With no **extra characters or spaces**

- After execution:

  - Stack a is sorted in ascending order

  - The smallest value is at the top

  - Stack b is empty

**Example Output**
```bash
pb
ra
pa
```

## Error Handling

If an error occurs, the program prints:
```bash
Error
```
to stderr, followed by a newline.

**Error cases include:**

- Non-integer arguments

- Values outside the integer range

- Duplicate values

**Special Case:**

- If no arguments are provided:

  - The program prints nothing

  - The prompt is immediately returned

## Benchmark Mode

An optional benchmark mode is available:
```bash 
./push_swap --bench [strategy] <list of integers>
```
**Benchmark Output (stderr only)**

After sorting, the following information is displayed:

**- Computed disorder** (percentage, two decimals)

**- Strategy used**

**- Theoretical complexity class**

**- Total number of operations**

**- Count of each operation:**

- ```sa```, ```sb```, ```ss```

- ```pa```, ```pb```

- ```ra```, ```rb```, ```rr```

- ```rra```, ```rrb```, ```rrr```

#### Rules

- Benchmark output appears only when --bench is specified

- All four strategies must be embedded in the binary

- Strategy name and complexity must be available in benchmark mode

#### Algorithms & Complexity
| Strategy | Purpose                                   | Complexity |
|----------|-------------------------------------------|------------|
|Simple    | Straightforward comparison-based sorting  | O(n²)      |
|Medium    | Reduced rotations and chunk optimization  | O(n√n)     |
|Complex   | Efficient large-input sorting             | O(n log n) |
|Adaptive  | Dynamic strategy selection                | Adaptive   |

## Algorithmic Choices and Justification
### Overview

This project relies on several complementary sorting algorithms in order to efficiently handle different input sizes and levels of disorder.
Each algorithm was selected based on its **theoretical complexity, compatibility with push_swap constraints**, and **practical efficiency** when limited to stack operations.

The main algorithms used are:

- **Min/Max extraction**

- **Bucket sort**

- **Radix sort**

#### Min / Max Extraction

**Principle**

Min/Max extraction consists in repeatedly locating the smallest or largest element in stack a, moving it to the top using rotations, and pushing it to stack b.
Once all elements are extracted, they are pushed back to stack a in sorted order.

**Usage in the project**

This approach is mainly used for:

- Very small input sizes

- Nearly sorted stacks

- Simple strategy (O(n²))

**Justification**

- Easy to implement

- Very efficient for small datasets

- Minimal overhead

- Well adapted to push_swap operations (rotations + pushes)

**Complexity**

- Each extraction requires a linear scan → O(n)

- Repeated n times → O(n²)

This makes it unsuitable for large inputs but ideal for small or low-disorder cases.

### Bucket Sort (Chunk-Based Sorting)

**Principle**

Bucket sort divides the input range into several value intervals (buckets or chunks).
Elements are pushed to stack b bucket by bucket, reducing the search space at each step.
Once all elements are distributed, they are reinserted into stack a in the correct order.

**Usage in the project**

Bucket sorting is used for:

- Medium-sized inputs

- Moderate disorder

- Medium strategy (O(n√n))

**Justification**

- Reduces the number of rotations compared to naive approaches

- Limits unnecessary back-and-forth operations

- Allows fine control over operation count by tuning bucket size

**Complexity**

- Dividing the input into √n buckets

- Each element is processed once per bucket pass

- Resulting in an overall complexity of O(n√n), which is a good compromise between simplicity and performance.

### Radix Sort

**Principle**

Radix sort processes numbers digit by digit (or bit by bit), distributing elements between stacks based on the current bit value.
At each iteration, elements are moved according to whether the current bit is set, then reassembled.

**Usage in the project**

Radix sort is used for:

- Large input sizes

- High disorder

- Complex strategy (O(n log n))

**Justification**

- Non-comparative sorting algorithm

- Extremely efficient for integer sorting

- Perfectly compatible with stack-based operations

- Predictable and stable operation count

**Complexity**

- Each bit requires one full pass over the stack → O(n)

- Number of bits proportional to log₂(n)

Overall complexity: **O(n log n)**

This makes radix sort the most efficient strategy for large datasets in push_swap.

### Adaptive Strategy Selection

The adaptive strategy dynamically selects the most appropriate algorithm based on:

- Input size

- Estimated disorder level

**Rationale**

- Small or nearly sorted inputs benefit from simple extraction-based methods

- Medium inputs are best handled with bucket-based approaches

- Large and highly disordered inputs require radix sorting

This adaptive behavior ensures:

- Optimal performance across all cases

- Reduced number of operations

- Compliance with the required complexity guarantees

**Conclusion**

The combination of min/max extraction, bucket sort, and radix sort allows this project to:

- Cover a wide range of input sizes

- Respect strict push_swap constraints

- Achieve strong performance guarantees

- Justify all claimed complexity classes

Each algorithm was selected based on both theoretical soundness and practical efficiency within the push_swap operational model.

## Resources

### References
- 42 documentation on push_swap
- Big-O notation and complexity analysis
- Sorting algorithms (radix sort, bucket sort, MIN MAX extraction)

### Use of Artificial Intelligence
AI tools were used during this project for:
- Generating documentation and improving README structure

All algorithmic decisions, implementation, and testing were performed and validated by the authors.


## Project Constraints

- No global variables

- Only allowed push_swap operations

- Minimal number of moves
    - For **100 random numbers**, your program should use:
        - Less than 2000 operations to pass (minimum requirement)
        - Less than 1500 operations for good performance
        - Less than 700 operations for excellent performance
    - For **500 random numbers**, your program should use:
        - Less than 12000 operations to pass (minimum requirement)
        - Less than 8000 operations for good performance
        - Less than 5500 operations for excellent performance

- Clean and strict output formatting

- Deterministic and robust behavior

## Summary

- Multiple embedded sorting strategies
- Adaptive algorithm selection
- Accurate complexity guarantees
- Detailed benchmark and statistics mode
- Strict error handling and output rules