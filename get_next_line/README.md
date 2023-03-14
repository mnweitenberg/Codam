# Get Next Line
My implementation of the get_next_line function, similar to the getline from CPP and fgets from C.

### What is Get Next Line?
Get Next Line is an individual project at [Codam](codam.nl) that requires us to create a function similar to the getline from CPP and fgets from C. This function allows a file to be read line after line if called in a loop.

#### Objectives
- Unix logic

#### Skills
- Rigor
- Unix
- Algorithms & AI

#### My grade
<img src="../img/score125.png" width="150" height="150"/>

## Getting started
**Follow the steps below**
```bash
# Clone the project and access the folder
git clone https://github.com/mnweitenberg/codam.git && cd codam/get_next_line

# Create a main file
touch main.c
```

```c
/*
** Example of a main, change "myfile.txt"
** to a file you want to read
*/

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*temp;
	int	fd;

	fd = open("myfile.txt", O_RDONLY);

	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
		break ;
		printf("%s", temp);
		free(temp);
	}
	return (0);
}
```

```bash
# Compile the files, example:
clang get_next_line.c get_next_line.h get_next_line_utils.c main.c

# Execute your program
./a.out

```

Made by Milan Weitenberg. [See my LinkedIn.](https://www.linkedin.com/in/mnweitenberg/)
