#include "holberton.h"
#include <stdio.h>
/**
 * print_char - prints char
 * @arglist: - lists inplace format values
 * Return: number of chars printed
 */
int print_char(va_list arglist)
{
char ch;
ch = va_arg(arglist, int);
if (ch == '\0')
return (0);
_putchar(ch);
return (1);
}
/**
 * print_string - prints char
 * @arglist: - lists inplace format values
 * Return: number of chars printed
 */
int print_string(va_list arglist)
{
char *str;
int c = 0;
str = va_arg(arglist, char *);
if (str == NULL)
{
str = "(null)";
}
while (str[c])
{
_putchar(str[c++]);
}
return (c);
}
/**
 * print_digit - prints char
 * @arglist: - lists inplace format values
 * Return: number of chars printed
 */
int print_digit(va_list arglist)
{
int base = 1, i, j = 0, num, numc, dig_len;
num = va_arg(arglist, int);
if (num == 0)
{
_putchar(num + '0');
return (1);
}
else if (num < 0)
{
_putchar('-');
num = -num;
j++;
}
numc = num;
for (dig_len = 1; numc > 0; dig_len++)
numc /= 10;
for (i = 1; i < dig_len - 1; i++)
base *= 10;
while (base >= 1)
{
_putchar((num / base) % 10 + '0');
base /= 10;
}
return (dig_len + j);
}
/**
 * print_sign - prints % sign
 * @arglist: - lists inplace format values
 * Return: number of chars printed
 */
int print_sign(va_list arglist)
{
if (va_arg(arglist, int))
_putchar(37);
return (1);
}
/**
 * print_message - to print "Unknown:[%r]"
 * @ch: - char value message
 * Return: int number of chars printed
 */
int print_message(char ch)
{
_putchar(37);
write(1, &ch, 1);
return (12);
}
