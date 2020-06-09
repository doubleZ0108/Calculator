//
//  calculator.h
//  Console_Calculator
//  
//  Created by double Z on 2020/06/09 .
//  Copyright © 2020 double Z. All rights reserved.
//

#ifndef CONSOLE_CALCULATOR_CALCULATOR_H
#define CONSOLE_CALCULATOR_CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "calculator_stack.h"

/*============ 优先级 ============*/
/**
 * 栈内优先级
 */
int isp(char ch)
{
    switch (ch)
    {
        case '#':return 0;
        case '(':return 1;
        case '*':case '/':return 5;
        case '+':case '-':return 3;
        case ')':return 6;
    }
}

/**
 * 栈外优先级
 */
int icp(char ch)
{
    switch (ch)
    {
        case '#':return 0;
        case '(':return 6;
        case '*':case '/':return 4;
        case '+':case '-':return 2;
        case ')':return 1;
    }
}


/**
 * Add a '#' as tile for the expression
 */
void addTail(char* exp) {
    int i;
    for (i = 0; i < strlen(exp); ++i);
    exp[i] = ' ';
    exp[i + 1] = '#';
}


/*============ 封装表达式中的项 ============*/
struct Data {
    int data;    //数据本身
    int flag;    //0->char, 1->int
};
int _current = 0;

/**
 * 获取表达式中的下一项
 *  - 操作符
 *  - 操作数
 *      - 正数
 *      - 负数
 *      - 特殊数字
 */
struct Data NextContent(char* exp)
{
    char _next[100] = "\0";
    char ch;
    int index = 0;

    for (int i = _current; i < strlen(exp); ++i)
    {
        ch = exp[i];
        if (ch != ' ')
        {
            _next[index] = ch;
            index++;    //因为不同对象以空格隔开,所以只要不是空格就加到_next
        }
        else
        {
            while (exp[i] == ' ') {
                i++;
            }
            _current = i;    //_current指向下一个位置,结束当前对象的寻找
            break;
        }
    }

    if (isOperator(_next[0])) {
        struct Data d;
        d.data = _next[0];
        d.flag = 0;
        return d;
    }
    else {
        struct Data d;
        d.data = atoi(_next);
        d.flag = 1;
        return d;
    }
}


/*============ 计算任务 ============*/
/**
 * Calculate two numbers based on a single middle operator
 * @param left: left number
 * @param op: middle operator
 * @param right: right number
 * @return: calculation value
 */
int Cal(int left, char op, int right)
{
    switch (op)
    {
        case '+':
            return left + right;
            break;
        case '-':
            return left - right;
            break;
        case '*':
            return left * right;
            break;
        case '/':
            return left / right;
            break;
        default:
            return left + right;
            break;
    }
}

/**
 * Calculate the value of postfix expression
 * @param result: struct data array
 * @param size: length of the items
 * @return: value of the postfix expression
 */
int calResult(struct Data result[], int size)
{
    num_stack_clear();
    for (int i = 0; i < size; ++i) {
        if (result[i].flag == 1) {
            num_stack_push(result[i].data);
        }
        else {
            int right = num_stack_pop();
            int left = num_stack_pop();
            num_stack_push(Cal(left, result[i].data, right));
        }
    }
    return num_stack_pop();
}

/**
 * Show postfix expression
 * @param result
 * @param size
 */
void showPostfix(struct Data result[], int size) {
    printf("The reverse polish notation is: ");
    for (int i = 0; i < size; ++i) {
        if (result[i].flag == 0) {
            printf("%c ", result[i].data);
        }
        else {
            printf("%d ", result[i].data);
        }
    }
    printf("\n");
}

/**
 * Check if buckets match each other in the expression
 * @param exp: input expression
 * @return: whether the buckets match each other or not
 */
bool check_exp_bucket(char* exp) {
    char ch = '\0';

    for (int i = 0; i < strlen(exp); ++i) {
        if (exp[i] == '(') {
            bucket_stack_push('(');
        }
        else if (exp[i] == ')') {
            ch = bucket_stack_pop();
            if (ch == EMPTY_CH || ch != '(') {
                printf("Buckets in the exprssion you input do not match.\n");
                return False;
            }
        }
    }
    return isempty_bucket_stack();
}

/**
 * Check if it contains illegal character in the expression
 * @param exp: input expression
 * @return: whether it contains illegal character or not
 **/
bool check_exp_notion(char* exp) {
    for (int i = 0; i < strlen(exp); ++i) {
        if (isDigit(exp[i]) || isOperator(exp[i]) || exp[i] == ' ') {
            continue;
        }
        else {
            printf("The operator we support: [+-*/()], you have input %c.\n", exp[i]);
            return False;
        }
    }
    return True;
}

/**
 * Beaurify for the origin expression
 * @param origin_exp: origin input expression
 * @param exp: expression after beautify
 */
void beautify(char* origin_exp, char* exp){
    int pos = 0;
    for (int i = 0; i < strlen(origin_exp); ++i) {
        if (isOperator(origin_exp[i])) {
            exp[pos] = ' ';
            ++pos;
            exp[pos] = origin_exp[i];
            ++pos;
            exp[pos] = ' ';
            ++pos;
        }
        else if (isDigit(origin_exp[i])) {
            exp[pos] = origin_exp[i];
            ++pos;
        }
    }
}

/**
 * Main calculation function
 * @param origin_exp: input expression
 * @param if_showrev: whether user want to show reverse the expression
 * @param if_beauty: whether user want to beautify the expression
 * @return
 */
int calculate(char* origin_exp, bool if_showrev, bool if_beauty) {
    char exp[100] = "\0";
    beautify(origin_exp, exp);  // 表达式格式优化

    if (if_beauty) {
        printf("After beautify: %s\n", exp);
    }

    num_stack_clear();  // 初始化操作数栈
    op_stack_clear();   // 初始化操作符栈
    _current = 0;

    struct Data result[100];
    int index = 0;

    addTail(exp); // 在表达式尾部添加结束标识符

    op_stack_push('#');
    struct Data elem = NextContent(exp);
    while (!isempty_op_stack()) {
        char ch = elem.data;

        if (elem.flag == 1) {        //如果是操作数, 直接读入下一个内容
            result[index] = elem;
            index++;
            elem = NextContent(exp);
        }
        else if (elem.flag == 0) {    //如果是操作符,判断ch的优先级icp和当前栈顶操作符的优先级isp
            char topch = op_stack_top();
            if (isp(topch) < icp(ch)) {        //当前操作符优先级大,将ch压栈,读入下一个内容
                op_stack_push(ch);
                elem = NextContent(exp);
            }
            else if (isp(topch) > icp(ch)) {    //当前优先级小,推展并输出到结果中
                struct Data buf;
                buf.data = op_stack_pop();
                buf.flag = 0;
                result[index] = buf;
                index++;
            }
            else {
                if (op_stack_top() == '(') {    //如果退出的是左括号则读入下一个内容
                    elem = NextContent(exp);
                }
                op_stack_pop();
            }
        }
    }

    if (if_showrev) {
        showPostfix(result, index);
    }

    return calResult(result, index);
}

/**
 * Main function for math - manage the user input
 * @param expression
 */
void mathMain(char* expression)
{
    if (!strcmp(expression, "NULL")) {
        printf("Sorry, you should add a math expressioin.\n");
    }
    else {
        char str_list[2][10] = { "-beauty","-rev" };
        int flag[2] = { 1,1 };
        for (int i = 0; i < 2; ++i) {
            int j = 0;
            while (expression[j] != ' ' && expression[j] != '\0') {
                if (expression[j] != str_list[i][j]) {
                    flag[i] = 0;
                    break;
                }
                ++j;
            }
        }

        if (flag[0]) {
            if (strlen(expression) > 8) {
                char* value = expression + 8;

                if (!check_exp_notion(value)) {
                    printf("Please check the expression and try again.\n");
                    printf("\n");
                    return;
                }

                bucket_stack_clear();
                if (!check_exp_bucket(value)) {
                    printf("Please check the expression and try again.\n");
                    printf("\n");
                    return;
                }

                int result = calculate(value, False, True);
                if (result != EMPTY_NUM) {
                    printf("The result is %d\n", result);
                }
                else {
                    printf("You can input [help] to know more.\n");
                }
            }
            else {
                printf("You should add the expression you want to calculate.\n");
                printf("You can input [man cal] to know more.\n");
            }
        }
        else if (flag[1]) {
            if (strlen(expression) > 5) {
                char* value = expression + 5;

                if (!check_exp_notion(value)) {
                    printf("Please check the expression and try again.\n");
                    printf("\n");
                    return;
                }

                bucket_stack_clear();
                if (!check_exp_bucket(value)) {
                    printf("Please check the expression and try again.\n");
                    printf("\n");
                    return;
                }


                int result = calculate(value, True, False);
                if (result != EMPTY_NUM) {
                    printf("The result is %d\n", result);
                }
                else {
                    printf("You can input [help] to know more.\n");
                }
            }
            else {
                printf("You should add the expression you want to calculate.\n");
                printf("You can input [man cal] to know more.\n");
            }
        }
        else {
            if (strlen(expression) > 0) {
                char* value = expression;

                if (!check_exp_notion(value)) {
                    printf("Please check the expression and try again.\n");
                    printf("\n");
                    return;
                }

                bucket_stack_clear();
                if (!check_exp_bucket(value)) {
                    printf("Please check the expression and try again.\n");
                    printf("\n");
                    return;
                }

                int result = calculate(value, False, False);
                if (result != EMPTY_NUM) {
                    printf("The result is %d\n", result);
                }
                else {
                    printf("You can input [help] to know more.\n");
                }
            }
            else {
                printf("You should add at least a expression.\n");
                printf("You can input [help] to know more.\n");
            }
        }
    }

    printf("\n");
}

#endif //CONSOLE_CALCULATOR_CALCULATOR_H
