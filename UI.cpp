#include "Sequence.h"
#include "UI.h"
#include <iostream>
#include <limits>

int user_seq = 0;


bool isCorrectIndex(int index, Sequence<int>* seq)
{
    bool res = index > seq->GetLength() || index < 1;
    if (res)
    {
        printf("Index is not correct. Try again\n");
    }
    return res;
}


void input(Sequence<int>* seq)
{
    int value;
    int size;
    printf("Specify the size of the sequence: \n");
    scanf_s("%d", &size);
    printf("Input values: \n");
    for (int i = 0; i < size; ++i)
    {
        scanf_s("%d", &value);
        seq->Append(value);
    }
}

void print_menu(Sequence<int>* seq)
{
    std::cout << "Sequence: ";
    seq->Print();
}

void set_menu(Sequence<int>* seq) 
{
    printf ("Set sequence's value");
    std::cout << std::endl;
    std::cout << "index: ";
    int index;
    std::cin >> index;
    if (!isCorrectIndex(index, seq)) set_menu(seq);
    std::cout << "value: ";
    int value;
    scanf_s("%d", &value);
    seq->Set(value, index);
}

void append_menu(Sequence<int>* seq) {
    printf("Append value");
    std::cout << std::endl;
    std::cout << "value: ";
    int value;
    scanf_s("%d", &value);
    seq->Append(value);
}

void prepend_menu(Sequence<int>* seq)
{
    printf("Prepend value");
    std::cout << std::endl;
    std::cout << "value: ";
    int value;
    scanf_s("%d", &value);
    seq->Prepend(value);
}

void insertat_menu (Sequence<int>* seq) {
    printf("Insert value");
    std::cout << std::endl;
    std::cout << "index: ";
    int index;
    scanf_s("%d", &index);
    if (!isCorrectIndex(index, seq)) insertat_menu(seq);
    std::cout << "value: ";
    int value;
    scanf_s("%d", &value);
    seq->InsertAt(index, value);
}

void concatenate_menu(Sequence<int>* seq) {
    printf("Concatenate sequences");
    std::cout << std::endl;
    Sequence<int>* anotherSeq = nullptr;
    switch (user_seq)
    {
    case 1:
        anotherSeq = new ArraySequence<int>();
        break;
    case 2:
        anotherSeq = new ListSequence<int>();
        break;
    }
    input(anotherSeq);

    Sequence<int>* concatenation = seq->Concat(anotherSeq);

    std::cout << "Concatenation: " << std::endl;
    concatenation->Print();
    delete concatenation;
    delete anotherSeq;
}

void subsequence_menu(Sequence<int>* seq) {
    printf("Get subsequence");
    std::cout << std::endl;

    std::cout << "start index: ";
    int start_index;
    scanf_s("%d", &start_index);
    if (!isCorrectIndex(start_index, seq)) insertat_menu(seq);
    std::cout << "end index: ";
    int end_index;
    scanf_s("%d", &end_index);
    if (!isCorrectIndex(end_index, seq)) insertat_menu(seq);
    Sequence<int>* sub_seq = seq->GetSubsequence(start_index, end_index);
    std::cout << "Subsequence: " << std::endl;
    sub_seq->Print();
    delete sub_seq;
}

void length_menu(Sequence<int>* seq)
{
    printf("Get length: ");
    std::cout << std::endl;
    std::cout << "Length: " << seq->GetLength() << std::endl << std::endl;
}

void remove_menu(Sequence<int>* seq)
{
    delete seq;
    printf("Sequence was removed\n");
}


void select_action_menu(Sequence<int>* seq)
{
    while (1) {
        printf("Select action: ");
        std::cout << std::endl;
        std::cout << "1 - remove" << std::endl;
        std::cout << "2 - set" << std::endl;
        std::cout << "3 - append" << std::endl;
        std::cout << "4 - prepend" << std::endl;
        std::cout << "5 - insert" << std::endl;
        std::cout << "6 - concatenate" << std::endl;
        std::cout << "7 - print subsequence" << std::endl;
        std::cout << "8 - print sequence" << std::endl;
        std::cout << "9 - get length" << std::endl;
        std::cout << "10 - create a new sequence" << std::endl;

        int user_input;
        std::cout << ">>> ";
        scanf_s("%d", &user_input);
        //  panic_if_invalid_input("action");

        switch (user_input) {
        case 1:
            remove_menu(seq);
            break;
        case 2:
            set_menu(seq);
            break;
        case 3:
            append_menu(seq);
            break;
        case 4:
            prepend_menu(seq);
            break;
        case 5:
            insertat_menu(seq);
            break;
        case 6:
            concatenate_menu(seq);
            break;
        case 7:
            subsequence_menu(seq);
            break;
        case 8:
            print_menu(seq);
            break;
        case 9:
            length_menu(seq);
            break;
        case 10:
            remove_menu(seq);
            start();
            break;
        }
    }
}

void start()
{
    printf("Create new Sequence!\n");
    printf("Select the sequence structure\n");
    std::cout << "1 - DynamicArray" << std::endl;
    std::cout << "2 - LinkedList" << std::endl;
    scanf_s("%d", &user_seq);
    Sequence<int>* seq = nullptr;
    switch (user_seq)
    {
    case(1):
        seq = new ArraySequence<int>();
        break;
    case(2):
        seq = new ListSequence<int>();
        break;
    }
    input(seq);
    printf("A sequence was created\n");
    select_action_menu(seq);
}
