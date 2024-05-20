//#include "ArraySequenceTests.hpp"
#include "Sequence.h"
#include "Tests.h"

void ArrSeqGetFirstTest() {
    int a[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int> tmp = ArraySequence<int>(a, 5);
    if (tmp.GetFirst() != 1) {
        printf("Test GetFirst failed\n");
        exit(1);
    }
    printf("All Tests GetFirst passed\n");
}

void ArrSeqGetLastTest() 
{
    int a[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int> tmp = ArraySequence<int>(a, 5);
    if (tmp.GetLast() != 5) 
    {
        printf("Test GetLast failed\n");
        exit(1);
    }
    printf("All Tests GetLast passed\n");
}

void ArrSeqGetTest() 
{
    int a[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    for (int i = 0; i < 5; ++i) {
        if (tmp->Get(i) != i + 1) 
        {
            printf("Test %d Get failed\n", i);
            exit(1);
        }
    }
    printf("All Tests Get passed\n");
}

void ArrSeqAppendTest() {
    int a[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    tmp->Append(6);
    tmp->Append(7);
    if (tmp->GetLength() != 7) {
        printf("Test Append failed\n");
        exit(1);
    }
    for (int i = 0; i < 7; ++i) 
    {
        if (tmp->Get(i) != i + 1) 
        {
            printf("Test %d Append failed\n", i);
            exit(1);
        }
    }
    printf("All Tests Append passed\n");
}

void ArrSeqPrependTest() {
    int a[] = { 2, 3, 4, 5, 6 };
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    tmp->Prepend(1);
    tmp->Prepend(0);
    if (tmp->GetLength() != 7) {
        printf("Test Prepend failed\n");
        exit(1);
    }
    for (int i = 0; i < 7; ++i) {
        if (tmp->Get(i) != i) {
            printf("Test %d Prepend failed\n", i);
            exit(1);
        }
    }
    printf("All Tests with Prepend passed\n");
}

void ArrSeqInsertAtTest() {
    int a[] = { 2, 3, 4, 5, 6 };
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    tmp->InsertAt(7, 3);
    if (tmp->GetLength() != 6) {
        printf("Test InsertAt failed\n");
        exit(1);
    }
    if (tmp->Get(2) != 7) {
        printf("Test InsertAt failed\n");
        exit(1);
    }
    printf("Test InsertAt passed\n");
}

void ArrSeqGetSubsequenceTest()
{
    int a[] = { 2, 3, 4, 5, 6 };
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    ArraySequence<int>* subtmp = tmp->GetSubsequence(1, 3);
    if (subtmp->GetLength() != 3) {
        printf("Test GetSubsequence failed\n");
        exit(1);
    }
    for (int i = 0; i < 3; ++i) {
        if (subtmp->Get(i) != a[i]) {
            printf("Test GetSubsequence failed\n");
            exit(1);
        }
    }
    printf("Test GetSubsequence passed\n");
}

void ArrSeqSetTest()
{
    int a[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    for (int i = 0; i < 5; ++i) 
    {
        tmp->Set( 5 - i, i + 1);
        if (tmp->Get(i) != 5 - i)
        {
            printf("Test %d Set failed\n", i);
            exit(1);
        }
    }
    printf("All Tests Set passed\n");
}

void ArrSeqConcatTest() 
{
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 6, 7, 8, 9, 10 };
    ArraySequence<int>* tmp_a = new ArraySequence<int>(a, 5);
    ArraySequence<int>* tmp_b = new ArraySequence<int>(b, 5);
    tmp_a  = tmp_a->Concat(tmp_b);
    if (tmp_a->GetLength() != 10) 
    {
        printf("Test Concat failed\n");
        exit(1);
    }
    for (int i = 0; i < 10; ++i)
    {
        if (tmp_a->Get(i) != i + 1)
        {
            printf("Test Concat failed\n", i);
            exit(1);
        }
    }
    printf("Test Concat passed\n");
}

void ArrSeqGetLengthTest()
{
    int a[] = { 1, 2, 3, 4, 5 };
    ArraySequence<int>* tmp = new ArraySequence<int>(a, 5);
    if (tmp->GetLength() != 5) {
        printf("Test GetLength failed\n");
        exit(1);
    }
    printf("Test GetLength passed\n");
}


void testsArraySequence() 
{
    ArrSeqGetLengthTest();
    printf("Get\n");
    ArrSeqGetTest();
    printf("GetFirst\n");
    ArrSeqGetFirstTest();
    printf("GetLast\n");
    ArrSeqGetLastTest();
    printf("InsertAt\n");
    ArrSeqInsertAtTest();
    printf("Append\n");
    ArrSeqAppendTest();
    printf("Prepend\n");
    ArrSeqPrependTest();
    printf("GetSubsequence\n");
    ArrSeqGetSubsequenceTest();
    printf("Set\n");
    ArrSeqSetTest();
    printf("Concat\n");
    ArrSeqConcatTest();
}