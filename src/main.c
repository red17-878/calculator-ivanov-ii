// program reads stdin, parses arithmetic expression and prints the result
// supports +, -, *, /, (, ) operators on integers

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aplusb/aplusb.h"

int parse_expression();
char* input;

int parse_number()
{
    int num = 0;
    while (isdigit(*input)) {
        num = num * 10 + (*input - '0');
        input++;
    }
    return num;
}

int parse_factor()
{
    if (*input == '(') {
        input++;
        int result = parse_expression();
        input++; // skip ')'
        return result;
    } else {
        return parse_number();
    }
}

int parse_term()
{
    int result = parse_factor();
    while (*input == '*' || *input == '/') {
        char op = *input;
        input++;
        int factor = parse_factor();
        if (op == '*') {
            result *= factor;
        } else {
            result /= factor;
        }
    }
    return result;
}

int parse_expression()
{
    int result = parse_term();
    while (*input == '+' || *input == '-') {
        char op = *input;
        input++;
        int term = parse_term();
        if (op == '+') {
            result = a_plus_b(result, term);
        } else {
            result -= term;
        }
    }
    return result;
}

#ifndef GTEST
int main()
{
    char buffer[65536];
    size_t len = 0;
    while (fgets(buffer + len, sizeof(buffer) - len, stdin)) {
        len += strlen(buffer + len);
    }

    // clean all spaces
    for (char *p1 = buffer, *p2 = buffer; *p2 != '\0' || (*p1 = '\0'); p2++) {
        if (!isspace(*p2)) {
            *p1++ = *p2;
        }
    }

    input = buffer;
    int result = parse_expression();
    printf("%d", result);
    return 0;
}
#endif
