//
//  util.h
//  Console_Calculator
//  
//  Created by 1754060 张喆 on 2020/06/09 .
//  Copyright © 2020 double Z. All rights reserved.
//

#ifndef CONSOLE_CALCULATOR_UTIL_H
#define CONSOLE_CALCULATOR_UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

typedef int bool;
typedef int DATA;
#define False 0
#define True 1
#define EMPTY_CH '\0'
#define EMPTY_NUM -999999

/**
 * My personal implementation for standard library strncpy
 * @param dest: destination string address
 * @param src: source string address
 * @param len: length for the string
 */
void mystrncpy(char* dest, char* src, int len)
{
//    assert(dest != NULL && src != NULL);      // macOS平台不支持assert

    char* temp = dest;
    int i = 0;
    while (i++ < len && (*temp++ = *src++) != '\0');

    if (*(temp) != '\0') {
        *temp = '\0';
    }
}


/**
 * Judge the character is an operator or not
 * @param ch: input character
 * @return: whether it is an operator or not
 */
bool isOperator(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '#':
            return True;
        default:
            return False;
    }
}

/**
 * Judge the character is an digit or not
 * @param ch: input character
 * @return: whether it is an opetator or not
 */
bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

/**
 * Judge the expression is a number or not
 * Number include(positive negative & some spetical number like +3 etc.)
 * @param exp: input expression
 * @return: whether it is a number of not
 */
bool isNum(char* exp)
{
    char ch = exp[0];
    if (ch == '+' && strlen(exp) > 1) // 如 +3 储存为 3
    {
        exp = exp + 1;    //把+删除
        ch = exp[0];        //更新一下ch
    }

    if (isDigit(ch) || (ch == '-' && strlen(exp) > 1)) //储存各种数字, 包括正数,负数,浮点数
    {
        return True;
    }

    return False;
}


#endif //CONSOLE_CALCULATOR_UTIL_H
