#include "holberton.h"
/**
 * conv_2HEX - conversion to upper hex
 * @num: unsigned int number
 * Return: number of digits printed
 */
int conv_2HEX(unsigned int num)
{
int c = 0;
if ((num / 16) != 0)
{
c += conv_2HEX((num / 16));
if ((num % 16) <= 9)
_putchar((num % 16) + 48);
else
_putchar((num % 16) + 48 + 7);
}
else
{
if ((num % 16) <= 9)
_putchar((num % 16) + 48);
else
_putchar((num % 16) + 48 + 7);
}
c++;
return (c);
}
/**
 * conv_2hex - convert to lower hex
 * @num: unsigned int 
 * Return: number of digits printed
 */
int conv_2hex(unsigned int num)
{
int c = 0;
if ((num / 16) != 0)
{
c += conv_2HEX((num / 16));
if ((num % 16) <= 9)
_putchar((num % 16) + 48);
else
_putchar((num % 16) + 48 + 39);
}
else
{
if ((num % 16) <= 9)
_putchar((num % 16) + 48);
else
_putchar((num % 16) + 48 + 39);
}
c++;
return (c);
}

/**
 * print_HEX - print upper hex
 * @valist: valist argument to print
 * Return: number of printed digits
 */
int print_HEX(va_list valist)
{
unsigned int tmp;
int hex;
tmp = va_arg(valist, int);
hex = conv_2HEX(tmp);
return (hex);
}
/**
 * print_hex - print hex lowercase
 * @valist: valist argument to print
 * Return: printed number of digits
 */
int print_hex(va_list valist)
{
unsigned int tmp;
int hex;
tmp = va_arg(valist, unsigned int);
hex = conv_2hex(tmp);
return (hex);
}
