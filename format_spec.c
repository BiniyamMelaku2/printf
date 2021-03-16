#include "holberton.h"
/**
 * format_spec - check for valid args.
 * @format: the char * to check
 * @valist: argument list
 * Return: void
 **/
int format_spec(const char **format, va_list valist)
{
int c, pr;

op_t ops[] = {
{"c", print_char},
{"s", print_str},
{"i", print_int},
{"d", print_dec},
{"b", print_bin},
{"u", print_uint},
{"o", print_oct},
{"x", print_hex},
{"X", print_HEX},
{NULL, NULL}
};
pr = 0;
for (c = 0; *(ops[c].f) != NULL; c++)
{
if (*format[0] == '%')
{
_putchar('%');
pr++;
break;
}
else if (*format[0] == *(ops[c].op))
{
pr += ops[c].f(valist);
break;
}
}
if (*(ops[c].f) == NULL)
{
_putchar('%');
_putchar(*format[0]);
pr += 2;
}
return (pr);
}
