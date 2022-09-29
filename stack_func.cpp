#include "stack_file.h"

void StackCtor(Stack* stk, size_t begin_capacity)
{
    stk->capacity = begin_capacity;
    stk->data = (Elem_t*)calloc(stk->capacity, sizeof(Elem_t));
}

void StackPush(Stack* stk, Elem_t in_value)
{
    if(stk->size >= stk->capacity)
        StackResizeUp(stk);

    stk->data[stk->size] = in_value;
    stk->size++;
}

void StackResizeUp(Stack* stk)
{
    stk->capacity = stk->capacity * 2;

    realloc(stk->data, stk->capacity);
}

int StackPop(Stack* stk, int* err, Elem_t begin_capacity)
{
    stk->size--;
    Elem_t value = stk->data[stk->size];

    if(stk->capacity != begin_capacity)
        StackResizeDown(stk);

    return value;
}

void StackResizeDown(Stack* stk)
{
    if(stk->size == (stk->capacity / 4))
    {
        realloc(stk->data, stk->size);
        stk->capacity = stk->capacity / 4;
    }
}

void StackDtor(Stack* stk)
{
    stk->size = -7777;
    stk->capacity = -7777;
    free(stk->data);
}