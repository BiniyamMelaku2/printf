#include "holberton.h"
/**
 * print_unum - int to char
 * @num: int to print
 * Return: number of digits printed (and -)
 */
int print_unum(unsigned int num)
{
unsigned int m = 1, tmp, c = 0;
tmp = num;
while (tmp / 10 != 0)
{
m = m * 10;
tmp = tmp / 10;
}
while ((num / m != 0) && (m != 1))
{
_putchar((num / m) + 48);
c++;
num = num % m;
if (m > 1)
m = m / 10;
while ((num < m) && (m > 1))
{
_putchar('0');
c++;
m = m / 10;
}
}
_putchar(num + 48);
return (c + 1);
}

/**
 * print_uint - print the int.
 * @valist: valist the argument to print
 * Return: number of digits printed
 **/
int print_uint(va_list valist)
{
unsigned int tmp;
int uint;
tmp = va_arg(valist, unsigned int);
uint = print_unum(tmp);
return (uint);
}
