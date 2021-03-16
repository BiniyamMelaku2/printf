#include "holberton.h"
/**
 * conv_bin - convert to binary
 * @num: unsigned int number
 * Return: number of digits printed
 */
int conv_bin(unsigned int num)
{
int c = 0;
if ((num / 2) != 0)
{
c += conv_bin((num / 2));
_putchar((num % 2) + 48);
}
else
_putchar((num % 2) + 48);
c++;
return (c);
}
/**
 * conv_oct - int to binary
 * @num: unsigned int to base 2
 * Return: number of digits printed
 */
int conv_oct(unsigned int num)
{
int c = 0;
if ((num / 8) != 0)
{
c += conv_oct((num / 8));
_putchar((num % 8) + 48);
}
else
_putchar((num % 8) + 48);
c++;
return (c);
}

/**
 * print_bin - print binary
 * @valist: valist argument to print
 * Return: number of printed digits
 */
int print_bin(va_list valist)
{
unsigned int tmp;
int bin;
tmp = va_arg(valist, int);
bin = conv_bin(tmp);
return (bin);
}
/**
 * print_oct - print number
 * @valist: valist argument to print
 * Return: printed digits
 */
int print_oct(va_list valist)
{
unsigned int tmp;
int oct;
tmp = va_arg(valist, unsigned int);
oct = conv_oct(tmp);
return (oct);
}
