#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAXSIZE 102400

void dfs(char *map, int i, char count, int width, int totalSize) {
    if (i < 0 || i >= totalSize || map[i] != 'X') return;

    map[i] = count;

    dfs(map, i - width, count, width, totalSize);
    dfs(map, i + width, count, width, totalSize);
    dfs(map, i - 1, count, width, totalSize);
    dfs(map, i + 1, count, width, totalSize);
}

bool replaceIslands(char *map, int width, int totalSize) {
    char count = '0';
    for (int i = 0; i < totalSize; i++) {
        if (map[i] == 'X') {
            if (count > '9') return false;
            dfs(map, i, count++, width, totalSize);
        }
    }
    return true;
}

int getWidth(char *map) {
	int width = 0;
	while (map[width] && map[width] != '\n') width++;
	return width + 1;
}

bool isValidChar(char c) {
	return (c == 'X' || c == '.' || c == '\n' || c == '\0');
}

bool isValidMap(char *map, int width, int totalSize) {
	int height = 0;
	for (int i = 0; i < totalSize; i++) {
		if (!isValidChar(map[i])) return false;
		if (map[i] == '\n') {
			if ((i + 1) % width != 0) return false;
			height++;
		}
	}
	if (height * width != totalSize) return false;
	return true;
}

int ft_exit() {
	write(1, "\n", 1);
	return 0;
}

int	main(int argc, char **argv) {
	if (argc != 2) return ft_exit();

	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) return ft_exit();

	char map[MAXSIZE] = {0};
	int totalSize = read(fd, map, MAXSIZE);
	if (totalSize <= 0) return ft_exit();

	int width = getWidth(map);
	if (!isValidMap(map, width, totalSize)) return ft_exit();
	if (!replaceIslands(map, width, totalSize)) return ft_exit();

	write(1, map, totalSize);
}
