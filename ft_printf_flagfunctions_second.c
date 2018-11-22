
#include "include/printf.h"
#include <stdlib.h>

void print_address(unsigned long input)
{
	char *result;
	unsigned long number = input;
	int counter = 0;
	char *strBase = "0123456789abcdef";

	ft_putstr("0x");
	while (number >= 16) {
		number = (number - (number % 16)) / 16;
		counter++;
	}
	result = malloc(sizeof(char) * counter + 1 + 1);
	result[counter + 1] = '\0';
	while (input >= 16) {
		result[counter] = strBase[input % 16];
		input = (input - (input % 16)) / 16;
		counter--;
	}
	result[counter] = strBase[input % 16];
	ft_putstr(result);
	free(result);
}

void sharp_octal_converter(int input)
{
	char *result;
	int number = input;
	int counter = 0;
	char *strBase = "01234567";

	while (number >= 8) {
		number = (number - (number % 8)) / 8;
		counter++;
	}
	number = input;
	result = malloc(sizeof(char) * counter + 1 + 1);
	result[counter + 1] = '\0';
	while (input >= 8) {
		result[counter--] = strBase[input % 8];
		input = (input - (input % 8)) / 8;
	}
	result[counter] = strBase[input % 8];
	ft_putchar('0');
	(number == 0) ? 1 : ft_putstr(result);
	free(result);
}

void print_plus(int input)
{
	if (input >= 0)
		ft_putchar('+');
	ft_putnbr(input);
}

void print_space(int input)
{
	if (input >= 0)
		ft_putchar(' ');
	ft_putnbr(input);
}
