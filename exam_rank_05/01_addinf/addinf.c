#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BOTH_POSITIVE 1
#define A_IS_NEGATIVE 2
#define B_IS_NEGATIVE 3
#define BOTH_NEGATIVE 4

#define A_IS_BIGGER 1
#define B_IS_BIGGER 2

int		g_sign;
int		g_size;
int		g_polarity;

int		char_to_digit(char c) 	{ return c - '0'; }
char	digit_to_char(int d) 	{ return d + '0'; }
int		ft_max(int a, int b)	{ return ((a > b) ? a : b); }

int		ft_strlen(char *s) {
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int		ft_strcmp(char *a, char *b) {
	while (*a || *b) {
		if (*a != *b)
			return ((unsigned char)*a - *b);
		a++;
		b++;
	}
	return (0);
}

int		get_sign(char *a, char *b) {
	if (a[0] != '-' && b[0] != '-') return BOTH_POSITIVE;
	if (a[0] == '-' && b[0] != '-') return A_IS_NEGATIVE;
	if (a[0] != '-' && b[0] == '-') return B_IS_NEGATIVE;
	if (a[0] == '-' && b[0] == '-') return BOTH_NEGATIVE;
	return 0;
}

int		get_biggest(char *a, char *b) {
	int len_a = ft_strlen(a);
	int len_b = ft_strlen(b);

	if (len_a > len_b || (len_a == len_b && ft_strcmp(a, b) > 0))
		return A_IS_BIGGER;
	return B_IS_BIGGER;
}

int		get_polarity() {
	if (g_sign == BOTH_NEGATIVE) return -1;
	if (g_size == A_IS_BIGGER && g_sign == A_IS_NEGATIVE) return -1;
	if (g_size == B_IS_BIGGER && g_sign == B_IS_NEGATIVE) return -1;
	return 1;
}

char	sum(char large, char small, int *carry) {
	int sum;
	if (g_sign == BOTH_NEGATIVE || g_sign == BOTH_POSITIVE)
		sum = char_to_digit(large) + char_to_digit(small) + *carry;
	else
		sum = char_to_digit(large) - char_to_digit(small) - *carry;

	*carry = (sum > 9 || sum < 0) ? 1 : 0;

	if (sum < 0) sum += 10;
	if (sum > 9) sum -= 10;

	return digit_to_char(sum);
}

void	get_result(char* result, char *large, char *small) {
	int	len_large = ft_strlen(large);
	int len_small = ft_strlen(small);
	int carry = 0;
	int i = len_large;

	result[i] = 0;
	while(len_small > 0)
		result[i--] = sum(large[--len_large], small[--len_small], &carry);

	while(len_large > 0)
		result[i--] = sum(large[--len_large], '0', &carry);

	result[0] = digit_to_char(carry);
}

int		result_is_zero(char *result, int len_result) {
	while (*result && len_result > 0) {
		if (*result++ != '0')
			return 0;
		len_result--;
	}
	return 1;
}

void	print(char *result, int len_result) {
	if (result_is_zero(result, len_result)) {
		write (1, "0\n", 2);
		return ;
	}

	if (g_polarity == -1)
		write(1, "-", 1);

	int i = 0;
	while (result[i] == '0')
		++i;
	for ( ; i < len_result; ++i)
		write(1, &result[i], 1);
	write(1, "\n", 1);
}

int		main (int argc, char **argv) {
	if (argc != 3)
		return 1;

	char *a = argv[1];
	char *b = argv[2];

	g_sign = get_sign(a, b);

	if (a[0] == '-') a = &a[1];
	if (b[0] == '-') b = &b[1];

	g_size = get_biggest(a, b);
	g_polarity = get_polarity();

	int		len_result = ft_max(ft_strlen(a), ft_strlen(b)) + 1;
	char*	result = (char *)malloc (len_result * sizeof(char));

	if (g_size == A_IS_BIGGER)
		get_result(result, a, b);
	if (g_size == B_IS_BIGGER)
		get_result(result, b, a);

	print(result, len_result);
	free(result);

	return 0;
}
