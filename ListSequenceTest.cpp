#include "Sequence.h"
#include "Tests.h"

void ListSeqGetFirstTest() 
{
    int a[] = { 1, 2, 3, 4, 5 };
    ListSequence<int>* tmp = new ListSequence<int>(a, 5);
    if (tmp->GetFirst() != 1) 
    {
        printf("Test GetFrist failed\n");
        exit(1);
    }
    printf("Test GetFirst passed\n");
}

void ListSeqGetLastTest()
{
    int a[] = { 1, 2, 3, 4, 5 };
    ListSequence<int>* tmp = new ListSequence<int>(a, 5);
    if (tmp->GetLast() != 5) 
    {
        printf("Test GetLast failed\n");
        exit(1);
    }
    printf("Test GetLast passed\n");
}

void ListSeqGetTest()
{
    int a[] = { 1, 2, 3, 4, 5 };
    ListSequence<int>* tmp = new ListSequence<int>(a, 5);
    if (tmp->Get(2) != 2 || tmp->Get(4) != 4)
    {
        printf("Test Get failed\n");
        exit(1);
    }
    printf("Test Get passed\n");
}

void ListSeqPrependTest()
{
    int a[] = { 1, 2, 3, 4, 5, 6 };
    ListSequence<int>* tmp = new ListSequence<int>(a, 6);
    tmp->Prepend(7);
    tmp->Prepend(8);
    if (tmp->Get(1) != 8 || tmp->Get(2) != 7) 
    {
        printf("Test Prepend failed\n");
        exit(1);
    }
    printf("Test Prepend passed\n");
}

void ListSeqAppendTest()
{
    int a[] = { 1, 2, 3, 4, 5, 6 };
    ListSequence<int>* tmp = new ListSequence<int>(a, 6);
    tmp->Append(7);
    tmp->Append(8);
    if (tmp->Get(7) != 7 || tmp->Get(8) != 8) 
    {
        printf("Test Append failed\n");
        exit(1);
    }
    printf("Test Append passed\n");
}

void ListSeqGetLengthTest()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7 };
    ListSequence<int>* tmp = new ListSequence<int>(a, 7);
    if (tmp->GetLength() != 7) 
    {
        printf("Test with GetLength failed\n");
        exit(1);
    }
    printf("Test with GetLength passed\n");
}

void ListSeqInsertAtTest()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7 };
    ListSequence<int>* tmp = new ListSequence<int>(a, 7);
    tmp->InsertAt(10, 3);
    if (tmp->Get(3) != 10)
    {
        printf("Test with InsertAt failed\n");
        exit(1);
    }
    printf("Test with InsertAt passed\n");
}

void ListSeqConcatTest()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 6, 7, 8, 9, 10 };
    ListSequence<int>* tmp_a = new ListSequence<int>(a, 5);
    ListSequence<int>* tmp_b = new ListSequence<int>(b, 5);
    tmp_a = tmp_a->Concat(tmp_b);
    if (tmp_a->GetLength() != 10)
    {
        printf("Test Concat failed\n");
        exit(1);
    }
    for (int i = 0; i < 10; ++i)
    {
        if (tmp_a->Get(i + 1) != i + 1)
        {
            printf("Test Concat failed\n", i);
            exit(1);
        }
    }
    printf("Test Concat passed\n");
}

void ListSeqGetSubsequenceTest()
{
    int a[] = { 2, 3, 4, 5, 6 };
    ListSequence<int>* tmp = new ListSequence<int>(a, 5);
    ListSequence<int>* subtmp = tmp->GetSubsequence(1, 3);
    if (subtmp->GetLength() != 3) 
    {
        printf("Test GetSubsequence failed\n");
        exit(1);
    }
    for (int i = 0; i < 3; ++i) 
    {
        if (subtmp->Get(i + 1) != a[i]) 
        {
            printf("Test GetSubsequence failed\n");
            exit(1);
        }
    }
    printf("Test GetSubsequence passed\n");
}


void testsListSequence()
{
    printf("Get\n");
    ListSeqGetTest();
    printf("GetFirst\n");
    ListSeqGetFirstTest();
    printf("GetLast\n");
    ListSeqGetLastTest();
    printf("GetLength\n");
    ListSeqGetLengthTest();
    printf("Append\n");
    ListSeqAppendTest();
    printf("Prepend\n");
    ListSeqPrependTest();
    printf("InsertAt\n");
    ListSeqInsertAtTest();
    printf("Concat\n");
    ListSeqConcatTest();
    printf("GetSubsequence\n");
    ListSeqGetSubsequenceTest();
}