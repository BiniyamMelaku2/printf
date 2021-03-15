#include "holberton.h"

char *convert(int num, int base) 
{ 
static char Representation[]= "0123456789ABCDEF";
static char buffer[50]; 
char *ptr; 
ptr = &buffer[49]; 
*ptr = '\0'; 
do
{
/*  print_converted(convert(98, 2));  int print_converted(char *str);  char *convert(int num, int base); */
*--ptr = Representation[num % base]; 
num /= base; 
}while(num != 0);

return(ptr); 
}

/**
 * print_digit - prints char 
 * @arglist - lists inplace format values
 * Return: number of chars printed
 */
int print_converted(char *str)
{
int base = 1, i, j = 0, num, numc, dig_len;
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
