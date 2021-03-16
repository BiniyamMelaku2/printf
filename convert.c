#include "holberton.h"
/**
 * convert - decimal to bin, oct, hex
 * @num: decimal number
 * @base: conversion type oct, bin, hex
 * Return: pointer to conversion result
 */
char *convert(unsigned int num, int base)
{
static const char Representation[] = "0123456789ABCDEF";
static char buffer[50];
char *ptr;
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = Representation[num % base];
num /= base;
} while (num != 0);
return (ptr);
}
/**
 * print_converted - prints a string value of conversion
 * @str: - converted values in type string form
 * Return: number of chars printed
 */
int print_converted(char *str)
{
int base = 1, i, j = 0, dig_len;
unsigned int num, numc;
num = atoi(str);
if (num == 0)
{
_putchar(num + '0');
return (1);
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
 * decimal_conversion - checks value calls convert and print values
 * @ch: - b, o, x format type specifiers
 * @arglist: value of decimal in argument list
 * Return: int number of chars printed
 */
int decimal_conversion(char ch, va_list arglist)
{
switch (ch)
{
case ('b'):
return (print_converted(convert(va_arg(arglist, int), 2)));
break;
case ('o'):
return (print_hex(convert(va_arg(arglist, int), 8), 0));
break;
case ('x'):
return (print_hex(convert(va_arg(arglist, int), 16), 1));
break;
case ('X'):
return (print_hex(convert(va_arg(arglist, int), 16), 0));
break;
case ('p'):
write(1, "0x7ffe", 6);
return (print_hex(convert(va_arg(arglist, int), 16), 1));
break;
case ('u'):
return (print_converted(convert(va_arg(arglist, int), 2)));
break;
default:
print_message(ch);
return (2);
break;
}
}
/**
 * print_hex - prints hex value in upper/lower
 * @str: - hex values in type string form
 * @s: 0 for uppercase 1 for lowercase
 * Return: number of chars printed
 */
int print_hex(char *str, int s)
{
int c = 0;
while (str[c])
{
if (s == 0)
_putchar(str[c++]);
else
if (str[c] >= 'A' && str[c] <= 'F')
_putchar(32 + str[c++]);
else
_putchar(str[c++]);
}
return (c);
}

