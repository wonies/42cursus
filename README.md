
# 42cursus Projects Overview

This repository contains summaries of the projects I completed as part of the 42 Seoul curriculum.
Each project helped me build a strong foundation in C programming, Unix systems, algorithms, and object-oriented programming in C++.

---

## 📚 Project Overview (Table)

| Project | Description | Language | Key Features | 🔗 Link |
|--------|-------------|----------|--------------|--------|
| 🧱 **Libft** | Custom implementation of the C standard library functions | C | Memory manipulation, string handling, linked list | [View Project](https://github.com/wonies/42cursus/tree/main/01.libft) |
| 🖨️ **ft_printf** | Reimplementation of the standard `printf` function | C | Variadic functions, format parsing | [View Project](https://github.com/wonies/42cursus/tree/main/02.PRINTF) |
| 📖 **get_next_line** | Read one line at a time from a file descriptor | C | Static buffer, file I/O | [View Project](https://github.com/wonies/42cursus/tree/main/03.GnL) |
| 🧮 **push_swap** | Sorting algorithm with stack operations | C | Greedy logic, custom sort strategy | [View Project](https://github.com/wonies/42cursus/tree/main/04.push_swap) |
| 🎮 **so_long** | Simple 2D game using MiniLibX | C | Map parsing, player movement | [View Project](https://github.com/wonies/42cursus/tree/main/05.solong) |
| 🧩 **pipex** | Shell-like command piping project | C | File redirection, process management | [View Project](https://github.com/wonies/42cursus/tree/main/06.pipe_x) |
| 🐚 **minishell** | Shell interpreter with built-in commands | C | Signals, quotes, pipes, redirection | [View Project](https://github.com/wonies/42cursus/tree/main/07.minishell) |
| 🧘‍♂️ **philo** | Dining philosophers problem (multithreading) | C | Mutexes, thread sync | [View Project](https://github.com/wonies/42cursus/tree/main/08.philo) |
| 🌄 **miniRT** | Basic ray tracing renderer | C | Vector math, lighting, intersections | [View Project](https://github.com/wonies/42cursus/tree/main/09.minirt) |
| 🧠 **C++ Modules** | Object-oriented design and STL | C++ | Inheritance, templates, STL | [View Project](https://github.com/wonies/42cursus/tree/main/10.cpp) |


---

## 📝 Project Overview (Text Style)

# 🧱 Libft
: Custom implementation of the C standard library functions.

🗝️ Key Features: Memory manipulation, string handling, linked list

### 📝 This project is a custom implementation of essential C standard library functions. It serves as the foundation for future C projects at 42.

🚀 Features

- Memory functions (e.g. memset, memcpy, calloc)
  
- String functions (e.g. strdup, strjoin, split)

- Character checks (e.g. isalpha, isdigit)

- Linked list operations

### 🛠️ Language & Tools
- C
- Makefile

### ▶️ How to Run

`make`

⸻

# 🖨️ ft_printf
: Reimplementation of the standard printf function.

🗝️ Key Features: Variadic functions, format parsing, buffer management

### 📝 A reproduction of the standard printf function that handles various format specifiers.

🚀 Features

- Handles %c %s %p %d %i %u %x %X %%

- Manages variadic arguments

- Writes to standard output

### 🛠️ Language & Tools
- C
- Makefile


### ▶️ How to Run
`make`

⸻

# 📖 get_next_line
: Read a line from a file descriptor one line at a time.

🗝️ Key Concepts: File I/O, static buffer, memory management

### 📝 Reads a line from a file descriptor efficiently, handling memory and buffers properly.

🚀 Features

- Handles multiple file descriptors

- Works with any buffer size

- Returns one line at a time

### 🛠️ Language & Tools
- C
- Makefile

### ▶️ How to Run

`make`

⸻

# 🧮 push_swap
: Sorting algorithm using stack operations.

🗝️ Key Features: Stack A/B logic, greedy strategy

### 📝 Sorts a stack of integers using the smallest number of operations.

🚀 Features

- Custom sorting algorithm using 2 stacks (A and B)

- Implemented allowed operations: sa, pb, ra, etc.

- Optimized for minimal operation count

### 🛠️ Language & Tools
- C
- Makefile

### ▶️ How to Run

`make`
`./push_swap "3 2 1"`

⸻

# 🎮 so_long
: A 2D game with player and map logic using MiniLibX.

🗝️ Key Features: Map parsing, collision, collectibles

### 📝 A simple 2D game using a tile-based map, made with the MiniLibX graphics library.

🚀 Features

- Player movement, collectible items, and exit

- Map parsing with validation

- Basic game loop and event handling

### 🛠️ Language & Tools
- C
- MiniLibX

### ▶️ How to Run

`make`
`./so_long maps/map.ber`


⸻

# 🧩 pipex
: Simulates UNIX piping behavior in C.

🗝️ Key Features: Pipe, fork, dup2, redirection

### 📝 A project to simulate shell piping between commands.

🚀 Features

- Executes commands connected via pipes

- Supports input/output redirection

- Mimics shell behavior like < infile cmd1 | cmd2 > outfile

### 🛠️ Language & Tools
- C

### ▶️ How to Run

`make`
`./pipex infile "cmd1" "cmd2" outfile`


⸻

# 🐚 minishell
: Mini shell built from scratch.

🗝️ Key Features: Built-ins, redirection, pipes, signals

### 📝 A small shell program that interprets and executes user commands.

🚀 Features

- Built-in commands: cd, echo, export, etc.

- Handles quotes, redirection, pipes, environment

- Uses execve and signal handling

### 🛠️ Language & Tools
- C
- Bash, Unix

### ▶️ How to Run

`make`
`./minishell`

Team with @Dongwookhong

⸻

# 🧘‍♂️ philo
: Dining philosophers concurrency problem.

🗝️ Key Features: Threads, mutexes, deadlock avoidance

### 📝 The classic Dining Philosophers problem using multithreading.

🚀 Features

- Thread-safe resource management

- Mutex locks for forks

- Avoids deadlock with precise timing

### 🛠️ Language & Tools
- C
- pthread

### ▶️ How to Run

`make`
`./philo 5 800 200 200`


⸻

# 🌄 miniRT
: Mini ray tracer with real-time rendering.

🗝️ Key Features: Vectors, lights, shapes, BMP export

### 📝 A basic raytracer that renders 3D scenes with spheres, planes, and cylinders.

🚀 Features

- Ray-object intersection

- Vector math & lighting

- BMP export

### 🛠️ Language & Tools
- C
- MiniLibX

### ▶️ How to Run

`make`
`./miniRT scenes/sample.rt`


⸻

# 🧠 C++ Modules
: C++ OOP and STL practice (cpp00 ~ cpp09).

🗝️ Key Features: Classes, inheritance, operator overloading, templates

### 📝 A series of projects to build object-oriented design and C++ standard library understanding.

🚀 Topics Covered

- Classes and inheritance

- Operator overloading

- Templates and exceptions

- STL containers: vector, map, etc.

### 🛠️ Language & Tools
- C++

### ▶️ How to Run
Each module contains its own Makefile and main.cpp. Run individually:

cd cpp_module_01
`make`
`./module01`

🔗 Go to Repository

