#include <unistd.h>

void reverseString(char *str, int length) {
	for (int i = 0; i < length / 2; ++i) {
		char temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}
}

int intToStr(int num, char* str) {
    int i = 0;
	while (num != 0) {
        str[i++] = '0' + num % 10;
        num /= 10;
    }
    str[i] = '\0';
	reverseString(str, i);
    return i;
}

void printNumber(int n) {
	char str[24];
	int length = intToStr(n, str);
	write(1, str, length);
    write(1, " ", 1);
}

void printPrimeFactors(int n) {
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        printNumber(2);
        n /= 2;
    }

    // n must be odd at this point so a skip of 2 can be used
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            printNumber(i);
            n /= i;
        }
    }

    // This condition is to handle the case when n is a prime number greater than 2
    if (n > 2) printNumber(n);
}

int ft_atoi(char *str) {
	int result = 0;
	while (*str >= '0' && *str <= '9') result = result * 10 + *str++ - '0';
	return result;
}

int main(int argc, char **argv) {
	if (argc != 2) return 0;
	printPrimeFactors(ft_atoi(argv[1]));
}
