#include <stdio.h>
#include <stdlib.h>

typedef int Elem_t;

typedef struct Stacks{
    Elem_t* data;
    size_t size;
    size_t capacity;
}Stack;

void StackCtor(Stack* stk, size_t begin_capacity);

void StackPush(Stack* stk, Elem_t in_value);

void StackResizeUp(Stack* stk);

int StackPop(Stack* stk, int* err, Elem_t begin_capacity);

void StackResizeDown(Stack* stk);

void StackDtor(Stack* stk);

