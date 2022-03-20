#include "list.h"
#include "fatal.h"

struct Node
{
    ElementType Element;
    Position Next;
};

List
MakeEmpty( List L )
{
    if( L != NULL )
        DeleteList(L);
    L = (List)malloc( sizeof( struct Node ) );
    if(NULL == L)
        FatalError("out of space!");
        
    L->Next = NULL;

    return L;
}

int
IsEmpty( List L )
{
    return L->Next == NULL;
}

int
IsLast( Position P, List L )
{
    assert(P != NULL);
    return P->Next == NULL;
}

Position
Find( ElementType X, List L )
{
    Position P;

    P = L->Next;
    while( P != NULL && P->Element != X )
    {
        P = P->Next;
    }

    return P;
}

Position
FindPrevious( ElementType X, List L )
{
    Position P;

    P = L;
    while( P->Next != NULL && P->Next->Element != X )
    {
        P = P->Next;
    }

    return P;
}

void 
Delete( ElementType X, List L )
{
    Position P;
    Position TemCell;

    P = FindPrevious(X, L);
    if( !IsLast( P, L ) )/* 如果是最后一个呢？ */
    {
        TemCell = P->Next;
        P->Next = TemCell->Next;
        free(TemCell);
    }
}

/**
 * @brief 后插
 * 
 */
void 
Insert(ElementType X, List L, Position P)
{
    Position TemCell;

    TemCell = malloc(sizeof(struct Node));
    if( NULL == TemCell )
        FatalError("out of space!!!");

    TemCell->Element = X;
    TemCell->Next = P->Next;
    P->Next = TemCell;
}

void 
DeleteList( List L )
{
    Position P, TemCell;

    P = L->Next; /* Header assumed */
    L->Next = NULL;

    while( P != NULL )
    {
        TemCell = P->Next;
        free( P );
        P = TemCell;
    }
}

Position 
Header( List L )
{
    return L;
}

Position 
First( List L )
{
    return L->Next;
}

Position
Advance( Position P )
{
    assert( P != NULL );
    return P->Next;
}

ElementType
Retrieve( Position P )
{
    assert( P != NULL );
    return P->Element;
}