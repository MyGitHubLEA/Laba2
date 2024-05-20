
#include "Tests.h"
#include "LinkedList.h"

void ListGetFirstTest() 
{
    int a[] = { 1, 2, 3, 4, 5 };
    LinkedList<int>* tmp = new LinkedList<int>(a, 5);
    if (tmp->GetFirst() != 1)
    {
        printf("Test GetFirst falied\n");
        exit(1);
    }
    printf("Test with GetFirst passed\n");
}

void ListGetLastTest()
{
    int a[] = { 1, 2, 3, 4, 5 };
    LinkedList<int>* tmp = new LinkedList<int>(a, 5);
    if (tmp->GetLast() != 5) 
    {
        printf("Test GetLast falied\n");
        exit(1);
    }
    printf("Test GetLast passed\n");
}

void ListGetLengthTest()
{
    int a[] = { 1, 2, 3, 4, 5 };
    LinkedList<int>* tmp = new LinkedList<int>(a, 5);
    if (tmp->GetLength() != 5) 
    {
        printf("Test GetLength falied\n");
        exit(1);
    }
    printf("Test GetLength passed\n");
}

void ListGetTest()
{
    int a[] = { 1, 2, 3, 4, 5 };
    LinkedList<int>* tmp = new LinkedList<int>(a, 5);
    for (int i = 0; i < 5; ++i) 
    {
        if (tmp->Get(i + 1) != i + 1)
        {
            printf("Test %d with Get failed\n", i);
            exit(1);
        }
    }
    printf("All Tests with Get passed\n");
}

void ListInsertAtTest()
{
    int a[] = { 1, 2, 3, 4, 5, 6 };
    LinkedList<int>* tmp = new LinkedList<int>(a, 6);
    tmp->InsertAt(7, 4);
    if (tmp->Get(4) != 7)
    {
        tmp->Print();
        printf("Test InsertAt failed\n");
        exit(1);
    }
    printf("Test InsertAt passed\n");
}

void ListSubListTest()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    LinkedList<int>* tmp = new LinkedList<int>(a, 10);
    LinkedList<int>* tmp2 = tmp->GetSubList(2, 5);
    for (int i = 0; i < 3; ++i) 
    {
        if (tmp2->Get(i + 1) != i + 2) 
        {
            printf("Test %d with SubList failed\n", i);
            exit(1);
        }
    }
    printf("All Tests with SubList passed\n");
}

void ListConcatTest()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 6, 7, 8, 9, 10 };
    LinkedList<int>* tmp_a = new LinkedList<int>(a, 5);
    LinkedList<int>* tmp_b = new LinkedList<int>(b, 5);
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

void ListAppendTest()
{
    int a[] = { 1, 2, 3, 4, 5, 6 };
    LinkedList<int>* tmp = new LinkedList<int>(a, 6);
    tmp->Append(7);
    tmp->Append(8);
    if (tmp->Get(7) != 7 || tmp->Get(8) != 8)
    {
        printf("Test Append failed\n");
        exit(1);
    }
    printf("Test Append passed\n");
}



void testsLinkedList()
{
    printf("Get\n");
    ListGetTest();
    printf("GetFirst\n");
    ListGetFirstTest();
    printf("GetLast\n");
    ListGetLastTest();
    printf("InsertAt\n");
    ListInsertAtTest();
    printf("GetSize\n");
    ListGetLengthTest();
    printf("GetSubList\n");
    ListSubListTest();
    printf("Append\n");
    ListAppendTest();
    printf("Concat\n");
    ListConcatTest();
}