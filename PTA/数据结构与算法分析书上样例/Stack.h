#pragma once
#ifndef _Stack_H
struct Node;
typedef

//Operations:
int  IsEmpty(Stack S);
Stack CreateStack();
DisposeStack(Stack S);
MakeEmpty(Stack S);
Push(ElementType X, Stack S);
ElementType  Top(Stack S);
Pop(Stack S);

#endif // !_Stack_H
