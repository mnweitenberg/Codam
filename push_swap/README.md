# Push_swap
This project involves sorting data on a [stack](https://www.geeksforgeeks.org/stack-data-structure-introduction-program/), with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

### What is Push_swap?
Push_swap is an individual project at [Codam](codam.nl) that requires us to create a program that sorts a stack(a) using an auxiliary stack(b) using specific commands: [sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb and rrr](#game-rules). The challenge is to implement an algorithm that sorts with the least amount of operations possible, for example an entry of [100 numbers](https://numbergenerator.org/#!numbers=100&low=1&high=100&unique=true&csv=&oddeven=&oddqty=0&sorted=false&addfilters=) should not exceed 700 operations to reach the maximum score and for [500 random numbers](https://numbergenerator.org/#!numbers=500&low=0&high=499&unique=true&csv=&oddeven=&oddqty=0&sorted=false&addfilters=) the maximum is 5500 operations.
As a bonus we must create a program that validates if the operations that the main program (push_swap) printed, orders stack(a) and checks if stack(b) remains empty at the end.

*Check the operations [table](#game-rules) for a complete description of each operation or the [mini game](https://phemsi-a.itch.io/push-swap) by [phemsi-a](https://github.com/paulahemsi).

#### Objectives
- Sorting algorithms
- Battery concept and handling elements
- Algorithm implementation

#### Skills
- Imperative programming
- Unix
- Rigor
- Algorithms & AI

#### My grade
<img src="../img/score125.png" width="150" height="150"/>

## Getting started
**Follow the steps below**
```bash
# Clone the project and access the folder
git clone https://github.com/mnweitenberg/codam.git && cd codam/push_swap/

# Compile push_swap and checker with
make && make checker
```

```bash
# Running push_swap
./push_swap 1 3 2 5 4

# Will output
pb
ra
pb
ra
sa
pa
pa
```

```bash
# Running checker
./checker 1 3 2 5 4

# Type each operation followed by enter
# and at the end press control + D to finish reading commands
pb
ra
pb
ra
sa
pa
pa

# Will output
OK
```

```bash
# Running push_swap with the checker (doesn't work on zsh)
ARG="1 3 2 5 4"; ./push_swap $ARG | ./checker $ARG

# Running push_swap with the checker (works on zsh)
./push_swap 1 3 2 5 4 | ./checker 1 3 2 5 4

# Will output
OK
```

```bash
# Clean output files with
make fclean

```

## Game rules
* The game is composed of 2 stacks named a and b.
* To start with:
a contains a random number of either positive or negative numbers without
any duplicates.
b is empty
* The goal is to sort in ascending order numbers into stack a.
* To do this you have the following operations at your disposal:

<table>
	<thead>
		<tr>
			<th colspan=3><h4>Operations</h4></th>
		</tr>
		<tr>
			<th>op</th>
			<th>description</th>
		</tr>
	</thead>
	<tbody>
	</thead>
		<tr>
			<td align="center">sa</td>
			<td>swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.</td>
		</tr>
		<tr>
			<td align="center">sb</td>
			<td>swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.</td>
		</tr>
		<tr>
			<td align="center">ss</td>
			<td>sa and sb at the same time.</td>
		</tr>
		<tr>
			<td align="center">pa</td>
			<td>push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.</td>
		</tr>
		<tr>
			<td align="center">pb</td>
			<td>push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.</td>
		</tr>
		<tr>
			<td align="center">ra</td>
			<td>rotate a - shift up all elements of stack a by 1. The first element becomes the last one.</td>
		</tr>
		<tr>
			<td align="center">rb</td>
			<td>rotate b - shift up all elements of stack b by 1. The first element becomes the last one.</td>
		</tr>
		<tr>
			<td align="center">rr</td>
			<td>ra and rb at the same time.</td>
		</tr>
		<tr>
			<td align="center">rra</td>
			<td>reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.</td>
		</tr>
		<tr>
			<td align="center">rrb</td>
			<td>reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.</td>
		</tr>
	</tbody>
</table>

---

Made by Milan Weitenberg. [See my LinkedIn.](https://www.linkedin.com/in/mnweitenberg/)
