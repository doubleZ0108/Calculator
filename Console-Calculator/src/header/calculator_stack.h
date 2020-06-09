//
//  calculator_stack.h
//  Console_Calculator
//  
//  Created by 1754060 张喆 on 2020/06/09 .
//  Copyright © 2020 double Z. All rights reserved.
//

#ifndef CONSOLE_CALCULATOR_CALCULATOR_STACK_H
#define CONSOLE_CALCULATOR_CALCULATOR_STACK_H
#include "util.h"

/**
 * 注: 由于C并没有原生stack库，所以这里使用简易方法模拟栈
 */

/*============ 括号栈 ============*/
char bucket_stack[100] = "\0";
int bucket_stack_index = -1;

bool isempty_bucket_stack() {
    return bucket_stack_index == -1;
}

void bucket_stack_push(char ch) {
    bucket_stack_index++;
    bucket_stack[bucket_stack_index] = ch;
}

char bucket_stack_pop(void) {
    if (isempty_bucket_stack()) {
        return EMPTY_CH;
    }
    char ch = bucket_stack[bucket_stack_index];
    bucket_stack_index--;
    return ch;
}

void bucket_stack_clear(void) {
    memset(bucket_stack, '\0', sizeof(bucket_stack));
    bucket_stack_index = -1;
}


/*============ 操作数栈 ============*/
int num_stack[100] = { 0 };
int num_stack_index = -1;

bool isempty_num_stack() {
    return num_stack_index == -1;
}

void num_stack_push(int num) {
    num_stack_index++;
    num_stack[num_stack_index] = num;
}

int num_stack_pop(void) {
    if (isempty_num_stack()) {
        return EMPTY_NUM;
    }
    int num = num_stack[num_stack_index];
    num_stack[num_stack_index] = 0;
    num_stack_index--;
    return num;
}

void num_stack_clear(void) {
    memset(num_stack, 0, sizeof(num_stack));
    num_stack_index = -1;
}


/*============ 操作符栈 ============*/
char op_stack[100] = "\0";
int op_stack_index = -1;

bool isempty_op_stack() {
    return op_stack_index == -1;
}

void op_stack_push(char ch) {
    op_stack_index++;
    op_stack[op_stack_index] = ch;
}

char op_stack_pop(void) {
    if (isempty_op_stack()) {
        return EMPTY_CH;
    }
    char ch = op_stack[op_stack_index];
    op_stack[op_stack_index] = '\0';
    op_stack_index--;
    return ch;
}

char op_stack_top(void) {
    if (isempty_op_stack()) {
        return EMPTY_CH;
    }
    return op_stack[op_stack_index];
}

void op_stack_clear(void) {
    memset(op_stack, '\0', sizeof(op_stack));
    op_stack_index = -1;
}

#endif //CONSOLE_CALCULATOR_CALCULATOR_STACK_H
