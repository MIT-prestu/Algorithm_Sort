#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int STDatatype;

typedef struct Stack {
	STDatatype* arr;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);

void StackDestroy(Stack* ps);

void StackPush(Stack* ps, STDatatype x);

void StackPop(Stack* ps);

STDatatype StackTop(Stack* ps);

int StackSize(Stack* ps);

void StackPrint(Stack* ps);
