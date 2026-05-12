# 🧮 Arbitrary Precision Calculator

> A command-line Arbitrary Precision Calculator written in pure C using **doubly linked lists** to perform arithmetic on extremely large integers beyond native data type limits.

![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Build](https://img.shields.io/badge/Build-GCC-A42E2B?style=for-the-badge&logo=gnu&logoColor=white)
![DSA](https://img.shields.io/badge/Concept-Big_Integer-blue?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

---

# 📌 What is an Arbitrary Precision Calculator?

Built-in data types like:

```c
int
long
long long
```

have storage limits.

For example:

```text
9223372036854775807
```

is the maximum value for a signed 64-bit integer.

Anything beyond that causes overflow.

This project solves the problem by representing numbers using **doubly linked lists**, allowing arithmetic operations on integers with virtually unlimited size.

---

# 🧠 How It Works

Each digit of a number is stored inside a node:

```text
123456789
```

becomes:

```text
1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 ⇄ 6 ⇄ 7 ⇄ 8 ⇄ 9
```

Arithmetic operations are performed manually digit-by-digit just like traditional mathematical calculations.

---

# 🗂️ Project Structure

```text
arbitrary-precision-calculator/
├── main.c          # Main driver and CLI handling
├── apc.c           # Linked list utility functions
├── apc.h           # Structures, macros, declarations
├── add.c           # Addition logic
├── sub.c           # Subtraction logic
├── mul.c           # Multiplication logic
├── div.c           # Division logic
├── utils.c         # UI and helper functions
├── Makefile        # Build automation
├── .gitignore
├── README.md
└── screenshots/
```

---

# ⚙️ Features

## Supported Operations

| Operator | Operation |
|---|---|
| `+` | Addition |
| `-` | Subtraction |
| `x` / `X` | Multiplication |
| `/` | Division |

---

## Key Functionalities

- Arbitrary precision arithmetic
- Doubly linked list representation
- Large integer support
- Carry and borrow handling
- Dynamic memory allocation
- Division with remainder
- Execution time benchmarking
- Command-line interface
- Memory cleanup

---

# 🔄 Arithmetic Flow

## Addition

```text
99999
+    1
------
100000
```

### Process

```text
Start from tail nodes
      ↓
Add digits
      ↓
Handle carry
      ↓
Insert result at front
```

---

## Subtraction

```text
1000
-999
----
1
```

### Process

```text
Start from tail nodes
      ↓
Subtract digits
      ↓
Handle borrow
      ↓
Insert result at front
```

---

## Multiplication

```text
123
× 45
-----
615
4920
-----
5535
```

### Process

```text
Multiply digit-by-digit
       ↓
Generate partial products
       ↓
Shift using zeros
       ↓
Add intermediate results
```

---

## Division

```text
99999 / 25
```

### Process

```text
Repeated subtraction
       ↓
Track quotient count
       ↓
Generate remainder
```

---

# 🚀 Getting Started

## Prerequisites

- GCC Compiler
- Linux / Unix Environment

---

# ⚒️ Build Project

## Using Makefile

```bash
make
```

---

## Manual Compilation

```bash
gcc *.c -Wall -Wextra -Werror -std=c11 -o apc
```

---

# ▶️ Run the Calculator

---

## Addition

```bash
./apc 999999999999999 + 1
```

### Output

```text
999999999999999 + 1 = 1000000000000000
```

---

## Subtraction

```bash
./apc 1000000000000 - 999999999999
```

---

## Multiplication

```bash
./apc 123456789 x 987654321
```

---

## Division

```bash
./apc 999999999 / 25
```

---

# 📖 Help Menu

```bash
./apc -help
```

### Output

```text
Usage:
./apc <operand1> <operator> <operand2>

Supported Operators:
+  Addition
-  Subtraction
x  Multiplication
/  Division
```

---

# 📦 Data Structure Design

## Node Structure

```c
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;

} node;
```

---

# 🔍 Core Algorithms Used

| Operation | Technique |
|---|---|
| Addition | Carry propagation |
| Subtraction | Borrow handling |
| Multiplication | Partial product accumulation |
| Division | Repeated subtraction |
| Storage | Doubly linked lists |

---

# 📊 Time Complexity

| Operation | Complexity |
|---|---|
| Addition | O(n) |
| Subtraction | O(n) |
| Multiplication | O(n²) |
| Division | O(n²) Approx |

---

# 📋 Core Concepts Demonstrated

| Concept | Usage |
|---|---|
| Doubly Linked Lists | Number representation |
| Dynamic Memory Allocation | Node creation |
| Big Integer Arithmetic | Arbitrary precision |
| Carry/Borrow Logic | Arithmetic operations |
| File Separation | Modular architecture |
| Command-Line Arguments | CLI interaction |
| Memory Management | Cleanup operations |
| DSA Implementation | Efficient digit operations |

---

# ⚠️ Limitations

- Integer arithmetic only
- No floating-point support
- Division uses repeated subtraction
- No negative operand support yet
- Terminal-only interface

---

# 🚀 Future Improvements

- Negative number support
- Decimal arithmetic
- Modulo operation
- Exponentiation
- Factorial support
- Scientific notation
- Expression parser
- Interactive shell mode
- Optimized long division
- GMP-style optimization

---

# 👨‍💻 Author

**Santhosh Pandian SG**  
Embedded Systems Engineer | Emertxe ECEP Trainee

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0077B5?style=flat&logo=linkedin)](https://linkedin.com/in/santhoshpandian06)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-181717?style=flat&logo=github)](https://github.com/santhoshpandiansg)

---

# 📄 License

This project is licensed under the MIT License.
