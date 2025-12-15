*This project has been created as part of the 42 curriculum by orhernan*

# Description

The main objective of this project is to reimplement the standard C libary function `printf()` as a custom library function named `ft_printf()`

It sereves as an opportunity to improve my C programming skills and get to know how to use variadic functions (functions that accept a variable number of arguments). Also, it helps develop the skill off designing a well-structured and extensible code.

The `ft_printf()` behaves similar to the original `printf()`. 

Prototype definition: `ft_printf(char const*,...)`

The implementation includes the following conversions: `cspdiuxX%`

|specifier|descrition|
|---------|----------|
|%c|prints a single character.|
|%s|prints a a string of characters.|
|%p|the void pointer argment is printed in hexadecimal format.|
|%d|prints a decimal number (base 10).|
|%i|prints an integer (base10).|
|%u|prints an unsigned decimal number (base 10).|
|%x|prints a hexadeccimal number (base 16) in lowercase.|
|%X|prints a hexadeccimal number (base 16) in uppercase.|
|%%|prints the percent symbol.|


# Instructions
## Requierments
- `make` is used to automate compilation of the source code.
- `cc` is the C compiler used to compile the source files.
- `ar` is the utility used to create static libraries
- `unity` is the framework used to run my custom tests.
## Execution
The project has a `Makefile` with the following rules:
|rule|description|
|-|-|
|`$(NAME)`|compiles the `libftprintf.a`.|
|`all`|compiles the project, creating the `libftprintf.a`.|
|`clean`|removes all object files (`*.o`).|
|`fclean`|removes all files (`*.o`) and the final output file (`libftprintf.a`).|
|`re`|removes all files and rebuilds the library `libftprintf.a`.|
|`test`|compiles and runs a custom testing progrm to verify the library's functionality.|

To compile the library run 
```
make
```
or 
```
make all
```

# Resources

This section lists the references realted to the project:

- C Standard Library `printf()` Man page: the official documentation detailing the function's behavior, flags, and conversions.

    -   https://man7.org/linux/man-pages/man3/printf.3.html

- Tutorials on C Variadic Functions: External videos or articles consulted for implementing the core variable argument functionality.

    -   https://www.youtube.com/watch?v=7Sph8JlRo0g

    -   https://www.youtube.com/watch?v=byRw36Y3Hjs

## AI usage Declaration

AI was used as an intellectual partner to assist in the development. It was specifically used to help design and generate more comprehensive test cases using the `Unity` testing framework. This focused on ensuring edge cases and complex scenarios for the implemented specifiers were covered.
