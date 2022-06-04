# Pipex
This project consists of reproducing the behavior of the [shell pipe](https://www.geeksforgeeks.org/piping-in-unix-or-linux/), redirecting STDIN and STDOUT using [pipes](https://www.geeksforgeeks.org/pipe-system-call/).

### What is Pipex?
Pipex is an individual project at [Codam](codam.nl) that requires us to create a program that simulates the behavior of the [shell pipe](https://www.geeksforgeeks.org/piping-in-unix-or-linux/), receiving a file or reading from the [STDIN](https://en.wikipedia.org/wiki/Standard_streams) and redirecting to a sequence of commands that will be written to the output file. To build the program it is necessary to create child processes using [fork()](https://www.geeksforgeeks.org/fork-system-call/) communicating with the parent process through [pipe()](https://www.geeksforgeeks.org/pipe-system-call/), manipulating the environment variable, testing if the command exists or has execution permission, for example, printing errors to [STDERR](https://en.wikipedia.org/wiki/Standard_streams) when necessary.

#### Objectives
- Unix logic

#### Skills
- Imperative programming
- Unix

#### My grade
<img src="../img/score125.png" width="150" height="150"/>

## Getting started
**Follow the steps below**
```bash
# Clone the project and access the folder
git clone https://github.com/mnweitenberg/codam.git && cd codam/pipex/

# Run make so you can build the program with the mandatory part
make

# Create a file to use in program input
echo "aaaaaaaaaaaaaaaaaaaaaaa" > input_file

# Run the program like the example
./pipex "input_file" "tr a b" "tr b c" "output_file"

# Check the output file
cat output_file

# or

# Run make bonus so you can build the program with the bonus part
make bonus

# Run the program like the example
./pipex "here_doc" "END" "tr a b" "tr b c" "tr c d" "output_file"

# Check the output file
cat output_file

# Clean output files with
make fclean

```

## Comparison of commands pipex vs shell
You can run any command that works in the shell and is in the PATH environment variable as in the examples below:

<table>
	<thead>
		<tr>
			<th colspan=3><h4>Examples (bonus)</h4></th>
		</tr>
		<tr>
			<th>run on</th>
			<th>command</th>
		</tr>
	</thead>
	<tbody>
	</thead>
		<tr>
			<td align="center">pipex</td>
			<td><code>./pipex "input_file" "tr a b" "tr b c" "output_file"</code></td>
		</tr>
		<tr>
			<td align="center">shell</td>
			<td><code>< input_file tr a b | tr b c > output_file</code></td>
		</tr>
		<tr>
			<td><br></td>
		</tr>
		 <tr>
			<td align="center">pipex</td>
			<td><code>./pipex "input_file" "ls -l" "wc -l" "output_file"</code></td>
		</tr>
		<tr>
			<td align="center">shell</td>
			<td><code>< input_file ls -l | wc -l > output_file</code></td>
		</tr>
		<tr>
			<td><br></td>
		</tr>
		 <tr>
			<td align="center">pipex</td>
			<td><code>./pipex "here_doc" "END" "rev" "sort -r" "tr '\n' ' '" "output_file"</code></td>
		</tr>
		<tr>
			<td align="center">shell</td>
			<td><code><< END rev | sort -r | tr '\n' ' ' >> output_file</code></td>
		</tr>
	</tbody>
</table>


---

Made by Milan Weitenberg. [See my linkedin.](https://www.linkedin.com/in/mnweitenberg/)
