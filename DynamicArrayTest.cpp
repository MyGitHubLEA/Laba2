#include "DynamicArray.h"
#include "Tests.h"

void ArrGetTest() 
{
    int a[] = { 1, 2, 3, 4, 5 };
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 5);
    for (int i = 0; i < 5; ++i) 
    {
        if (tmp->Get(i) != a[i]) 
        {
            printf("Test %d Get failed\n", i);
            exit(1);
        }
    }
    printf("All tests Get passed\n");
}

void ArrGetLengthTest()
{
    int a[] = { 1, 1, 1, 1, 1 };
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 5);
    if (tmp->GetLength() != 5) 
    {
        printf("Test GetLength failed\n");
        exit(1);
    }
    printf("Test GetLength passed\n");
}

void ArrSetTest()
{
    int a[] = { 1, 2, 3, 4, 5 };
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 5);
    for (int i = 0; i < 5; ++i) 
    {
        tmp->Set(5 - i, i);
    }
    for (int i = 0; i < 5; ++i) 
    {
        if (tmp->Get(i) != 5 - i) 
        {
            printf("Test %d with Set falied\n", i);
            exit(1);
        }
    }
    printf("All Tests with Set passed\n");
}

void ArrResizeTest()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    DynamicArray<int>* tmp = new DynamicArray<int>(a, 10);
    tmp->Resize(4);
    if (tmp->GetLength() != 4) 
    {
        printf("Test Resize failed\n");
        exit(1);
    }
    for (int i = 0; i < 4; ++i) 
    {
        if (tmp->Get(i) != i + 1)
        {
            printf("Test Resize failed\n");
            exit(1);
        }
    }
    printf("All Tests Resize passed\n");
    return;
}

void testsDynamicArray()
{
    printf("Get\n");
    ArrGetTest();
    printf("Resize\n");
    ArrResizeTest();
    printf("Set\n");
    ArrSetTest();
    printf("GetLength\n");
    ArrGetLengthTest();
}