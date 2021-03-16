# _printf :page_facing_up:
A formatted output conversion C program. The program is a pseudo-
recreation of the C standard library function, `printf`.

## Dependencies :couple:

The `_printf` function was coded on an Ubuntu 14.04 LTS machine with `gcc` version 4.8.4.

## Usage :running:

To use the `_printf` function, assuming the above dependencies have been installed,
compile all `.c` files in the repository and include the header `holberton.h` with
any main function.

Example `main.c`:
```
#include "holberton.h"

int main(void)
{
    _printf("Hello, World!");

    return (0);
}
```

Compilation:
```
$ gcc *.c -o tester
```

Output:
```
$ ./tester
Hello, World!
$
```

## Description :speech_balloon:

The function `_printf` writes output to standard output. The function writes
under the control of a `format` string that specifies how subsequent arguments
(accessed via the variable-length argument facilities of `stdarg`) are
converted for output.

Prototype: `int _printf(const char *format, ...);`

### Return Value

Upon successful return, `_printf` returns the number of characters printed
(excluding the terminating null byte used to end output to strings). If an
output error is encountered, the function returns `-1`.

### Format of the Argument String

The `format` string argument is a constant character string composed of zero
or more directives: ordinary characters (not `%`) which are copied unchanged
to the output stream; and conversion specifications, each of which results in
fetching zero or more subsequent arguments. Conversion specification is
introduced by the character `%` and ends with a conversion specifier. In
between the `%` character and conversion specifier, there may be (in order)
zero or more _flags_, an optional minimum _field width_, an optional
_precision_ and an optional _length_ modifier. The arguments must correspond
with the conversion specifier, and are used in the order given.

#### Flag Characters

The character `%` may be followed by zero or more of the following flags:

#### #
  * For `o` conversions, the first character of the output string is prefixed
  with `0` if it was not zero already.
  * For `x` converions, `0x` is prepended for non-zero numbers.
  * For `X` conversions, `0X` is prepeneded for non-zero numbers.

Example `main.c`:
```
int main(void)
{
    _printf("%#x\n", 7);
}
```
Output:
```
0x7
```

#### (space)
  * A blank is left before a positive number or empty string produced by a
  signed conversion.

Example `main.c`:
```
int main(void)
{
    _printf("% d\n", 7);
}
```
Output:
```
 7
```

#### +
  * A sign (`+` or `-`) is always placed before a number produced by signed
  conversion.
  * Overrides a space flag.

Example `main.c`:
```
int main(void)
{
    _printf("%+d\n", 7);
}
```
Output:
```
+7
```

#### 0
  * For `d`, `i`, `o`, `u`, `x`, and `X` conversions, the converted value is
  padded on the left with zeroes rather than blanks.
  * If the `0` flag is provided to a numeric conversion with a specified
  precision, it is ignored.

Example `main.c`:
```
int main(void)
{
    _printf("%05d\n", 7);
}
```
Output:
```
00007
```

#### -
  * The converted value is left-justified (padded on the right with blanks
  instead of on the left with blanks or zeroes).
  * Overrides a `0` flag.

Example `main.c`:
```
int main(void)
{
    _printf("%-5d7\n", 7);
}
```
Output:
```
7    7
```
