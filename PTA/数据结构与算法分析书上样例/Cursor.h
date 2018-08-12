#pragma once
#ifndef _Cursor_H
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
void InitializeCursorSpace(void);
List MakeEmpty(List L);
//bool IsEmpty(const List L);
//bool IsLast(const Position P, const List L);

#endif // !_Cursor_H
