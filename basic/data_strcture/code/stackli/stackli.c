#include "stackli.h"
#include "fatal.h"
#include <assert.h>

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int 
IsEmpty( Stack S )
{
    assert( S != NULL );
    return S->Next == NULL;
}

void
MakeEmpty( Stack S )
{
    if( S == NULL )
        Error("Must use CreateStack first");
    else
        while( !IsEmpty( S ) )
            Pop( S );
}

Stack
CreateStack( void )
{
    Stack S;

    S = malloc( sizeof( struct Node ) );
    if( S == NULL )
        FatalError( "out of space!!!" );
    S->Next = NULL;
    MakeEmpty( S );
    return S;
}

void
Push( ElementType X, Stack S )
{
    PtrToNode TmpCell;

    TmpCell = malloc( sizeof( struct Node ) );
    if( TmpCell == NULL )
        FatalError( "Out of space!!!" );
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType
Top( Stack S )
{
    assert( S != NULL );
    if( !IsEmpty( S ) )
        return S->Next->Element;
    Error( "Empty stack" );
    return 0;
}

void 
Pop( Stack S )
{
    PtrToNode FirstCell;

    if( IsEmpty( S ) )
        Error( "Empty stack" );
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

void
DisposeStack( Stack S )
{
    MakeEmpty( S );
    free( S );
}