#include "stack_file.h"

int main()
{
    Stack stk1 = {};

    StackCtor(&stk1, 10);

    StackPush(&stk1, 1);

    int err = 0;
    Elem_t value = 0;
    value = StackPop(&stk1, &err, 10);

    StackDtor(&stk1);
    return 0;
}