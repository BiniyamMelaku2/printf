#include "holberton.h"
/**
 * print_number - integer to char
 * @num: int to print
 * Return: number of digits printed (and -)
 */
int print_number(int num)
{
int m = 1, tmp, c = 0;
tmp = num;
if (num < 0)
{
_putchar('-');
c++;
}
while (tmp / 10 != 0)
{
m = m * 10;
tmp = tmp / 10;
}
while ((num / m != 0) && (m != 1))
{
_putchar(abs((num / m)) + 48);
c++;
num = num % m;
if (m > 1)
m = m / 10;
while ((abs(num) < m) && (m > 1))
{
_putchar('0');
c++;
m = m / 10;
}
}
_putchar(abs(num) + 48);
return (c + 1);
}
/**
 * print_int - print the int.
 * @valist: valist the argument to print
 * Return: number of digits printed
 **/
int print_int(va_list valist)
{
int tmp, num;
tmp = va_arg(valist, int);
num = print_number(tmp);
return (num);
}
/**
 * print_dec - print decimal integer.
 * @valist: valist argument to print
 * Return: number of digits printed
 **/
int print_dec(va_list valist)
{
int tmp, num;
tmp = va_arg(valist, int);
num = print_number(tmp);
return (num);
}
