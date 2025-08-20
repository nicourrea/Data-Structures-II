#include <iostream>
#include <string>
#include "tlist.h"

using namespace std;

template <typename T>
void PrintList(const TList<T>& myList, const string& listLabel) {
    cout << listLabel << " size is: " << myList.GetSize() << "\n"
         << listLabel << " = ";
    myList.Print(cout);
    cout << "\n\n";
}

int main() {
    TList<int> intList;      
    TList<double> doubleList;   

    cout << "Int List is empty" << endl;
    PrintList(intList, "Int List");

    cout << "Double List is empty" << endl;
    PrintList(doubleList, "Double List");

    // Adding numbers to intList
    cout << "Add 12 numbers to the back of Int List" << endl;
    for (int i = 0; i < 12; i++)
        intList.InsertBack(i * 2);
    PrintList(intList, "Int List");

    // Adding numbers to intList
    cout << "Add 10 numbers to the front of Int List" << endl;
    for (int i = 0; i < 10; i++)
        intList.InsertFront(i);
    PrintList(intList, "Int List");

    // Removing numbers from intList
    cout << "Remove 12 numbers from the back of Int List" << endl;
    for (int i = 0; i < 12; i++)
        intList.RemoveBack();
    PrintList(intList, "Int List");

    // Removing numbers from intList
    cout << "Remove 10 numbers from the front of Int List" << endl;
    for (int i = 0; i < 10; i++)
        intList.RemoveFront();
    PrintList(intList, "Int List");

    // Adding numbers to doubleList
    cout << "Add 20 numbers to the back of Double List" << endl;
    for (int i = 0; i < 20; i++)
        doubleList.InsertBack(i * 2.0);
    PrintList(doubleList, "Double List");

    // Adding numbers to doubleList
    cout << "Add 20 numbers to the front of Double List" << endl;
    for (int i = 0; i < 20; i++)
        doubleList.InsertFront(i);
    PrintList(doubleList, "Double List");

    // Removing numbers from doubleList
    cout << "Remove 18 numbers from the back of Double List" << endl;
    for (int i = 0; i < 18; i++)
        doubleList.RemoveBack();
    PrintList(doubleList, "Double List");

    // Removing numbers from doubleList
    cout << "Remove 18 numbers from the front of Double List" << endl;
    for (int i = 0; i < 18; i++)
        doubleList.RemoveFront();
    PrintList(doubleList, "Double List");

    TListIterator<int> intListIterator = intList.GetIterator();    
    TListIterator<double> doubleListIterator = doubleList.GetIterator(); 

    // Iterating over intList
    for (int i = 0; i < intList.GetSize(); i++)  
        intListIterator.Next();

    // Iterating over intList
    for (int i = 0; i < intList.GetSize(); i++) 
        intListIterator.Previous();

    // Removing numbers from intList
    for (int i = 0; i < 4; i++)
        intList.RemoveBack();
    cout << "Clear Int List" << endl;
    PrintList(intList, "Int List");

    // Adding numbers to intList
    intList.InsertFront(1);
    intList.InsertFront(2);
    cout << "Insert 2 at the front of Int List" << endl;
    PrintList(intList, "Int List");

    // Adding numbers to intList
    intList.InsertFront(4);
    cout << "Insert 1 at the back of Int List" << endl;
    PrintList(intList, "Int List");

    // Iteratively inserting numbers into intList
    intList.Insert(intListIterator, 100);
    cout << "Iteratively insert 100 into Int List" << endl;
    PrintList(intList, "Int List");

    // Removing a number from the front of intList
    intList.RemoveFront();
    cout << "Remove a number from the front of Int List" << endl;
    PrintList(intList, "Int List");

    // Removing a number from the back of intList
    intList.RemoveBack();
    cout << "Remove a number from the back of Int List" << endl;
    PrintList(intList, "Int List");

    return 0;
}
