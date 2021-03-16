#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * struct special_chars - defines special characters
 * struct format_chars - defines format types
 * @ch: char specifier i.e. c, s, %
 * @func: pointer to function
 */
typedef struct special_chars
{
char *ch;
int (*func)(va_list);
} format_chars;
int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list);
int print_string(va_list);
int print_digit(va_list);
int print_sign(va_list);
char *convert(unsigned int num, int base);
int print_converted(char *str);
int print_message(char ch);
int decimal_conversion(char ch, va_list arglist);
int print_hex(char *str, int s);
#endif
