# 42_M02: push_swap

## Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [Implementation](#implementation)
- [Checker implementation](#checker-implementation)

___

## Description

I have 2 stacks named `a` and `b`. At the beginning the stack `a` contains a random number of unique negative and/or positive integers. The stack `b` is empty.

**Goal of this 42 project:** create a `push_swap` program, that is able to sort the numbers in stack `a` in ascending order using defined actions specified below. The instructions sequence should be as short as possible.

```bash
- sa (swap a)			# swap the first 2 elements at the top of stack `a`
- sb (swap b)			# swap the first 2 elements at the top of stack `b`
- ss					# `sa` + `sb` at the same time

- pa (push a)				# take the first element at the top of `b`
							# and put it at the top of `a`
- pb (push b)				# take the first element at the top of `a`
							# and put it at the top of `b`

- ra (rotate a)				# shift up all elements of stack `a` by 1
- rb (rotate b)				# shift up all elements of stack `b` by 1
- rr						# `ra` and `rb` at the same time.

- rra (reverse rotate a)	# shift down all elements of stack `a` by 1
- rrb (reverse rotate b)	# shift down all elements of stack `b` by 1
- rrr						# `rra` and `rrb` at the same time
```
*(Do nothing if the stack is empty or does not contain necessary number of integers.)*

**For maximum project validation (100%)**, my program must:
- Sort **100** random numbers in fewer than **700** operations.
- Sort **500** random numbers in no more than **5500** operations.

*(I hit these benchmarks in most of the cases. Although there are few that are over the benchmark.)*


### Checker:
- My own `checker` program to check if the `push_swap` program sorts the stack properly
- Takes as an argument the `stack a` formatted as a list of integers. If no argument is given, it stops and displays nothing.
- Then it waits and read instructions from the standard input, with each instruction followed by `\n`. Once all the instructions have been read, the program executes them on the stack received as an argument.
- If after executing those instructions, the `stack a` is actually sorted and the `stack b` is empty, the program displays `OK` on the standard output.
- In every other case, it displays `KO` on the standard output.
- In case of error, it displays `Error` on the standard error.

*Errors include: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.*


## Instructions

### Compilation:
```bash
make / make all		# compile the push_swap program
make checker		# compile the checker program
make clean			# delete the temporary files
make fclean			# delete the temporary files + the compiled library
make re				# make fclean and make all together
```

### Execution:
```bash
# execute the sorting program:
ARG="4 67 3 87 23"; ./push_swap $ARG

# check if the stack is sorted correctly:
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# check the number of actions performed:
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

- If no parameters are specified, the program does not display anything and returns to the prompt.
- In case of error, it displays `Error` on the `standard error`.

*(Errors include, for example: some arguments not being integers, some arguments exceeding the integer limits, and/or the presence of duplicates.)*


## Resources
- `man exit()`
- **testing** my program with: [Tester](https://github.com/gemartin99/Push-Swap-Tester), [Visualizer](https://push-swap42-visualizer.vercel.app/)
- discussing sorting algorithms + debugging with LLMs (ChatGPT)


## Implementation

I store the arguments in circular linked lists so the actions are just about switching pointers or changing the head pointer.

### Normalization
For sake of computing efficiency, I assign each number its index in a sorted order. So the program does not have to count with numbers such as `INT_MIN` or `INT_MAX`, but for example with 100 arguments it deals with indexes 0-99.

### Sorting algorithm
- Firstly I check if the `stack a` is already in the correct order. If it is, it can be just rotated to the top with no other moves needed.
- If not, I have special rules for less arguments than 6 defined.
- If there are 6 and more, I implement a **chunk strategy**:
	- I divide the whole stack into smaller portions - **chunks** *(I played with the sizing when testing efficiency of my program)*
	- I move all indexes from the first **chunk** to the `stack b`, but in order in which they **cost** the least actions. It is not a proper "greedy" algorithm, just partial version.
	- I continue with other chunks in order until I have all numbers in `stack b`.
	- Then I find `max` or `second max` index in `stack b` (depends which one has better cost) and return it to `stack a`.
	- If it is `second max`, I add a `swap` action in `stack a` afterwards.


## Checker implementation
It is basically the same code as `push_swap` - taking the arguments, storing them and performing the actions on them (except that `push_swap` prints the instructions and `checker` does not).

I only had to add reading the instructions with which my own `get_next_line()` function really helped me.

I stored the instructions to another linked list, linear this time.

---

## 👤 Author

**Simona Sucha**
*(also known as ssucha or vincent_syma)* <br>
Python & C · Developer, Software Tester · 42 student

🖥️ GitHub: https://github.com/vincent-syma/ <br>
🔗 LinkedIn: https://www.linkedin.com/in/simona-such%C3%A1-5a1b1928b <br>
✉️ Email: vincent.f.syma@email.cz <br>