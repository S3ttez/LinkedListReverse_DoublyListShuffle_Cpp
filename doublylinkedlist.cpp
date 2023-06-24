#include <iostream>
#include <cstdlib>
#include <ctime>

// Struct to define an Element
struct Element {
    int data;
    Element* next;
    Element* prev;
};

// Struct to define a List
struct List {
    Element* head;
    int size;
};

// Function to create a new Element
Element* CreateElement(int data) {
    Element* element = new Element();
    element->data = data;
    element->next = nullptr;
    element->prev = nullptr;
    return element;
}

// Function to create a List
List* CreateList() {
    List* list = new List();
    list->head = nullptr;
    list->size = 0;
    return list;
}

// Function to insert an element after another
void InsertElementAfter(Element* prevElement, int data) {
    if (prevElement == nullptr) {
        return;
    }
    Element* newElement = new Element();
    newElement->data = data;
    newElement->next = prevElement->next;
    newElement->prev = prevElement;
    prevElement->next = newElement;
    if (newElement->next != nullptr) {
        newElement->next->prev = newElement;
    }
}

// Function to insert an element before another
void InsertElementBefore(Element** headRef, Element* nextElement, int data) {
    if (nextElement == nullptr) {
        return;
    }
    Element* newElement = new Element();
    newElement->data = data;
    newElement->prev = nextElement->prev;
    newElement->next = nextElement;
    if (nextElement->prev != nullptr) {
        nextElement->prev->next = newElement;
    } else {
        *headRef = newElement;
    }
    nextElement->prev = newElement;
}

// Function to add an element at the head
void PreInsertHead(List* list, int data) {
    Element* element = CreateElement(data);
    element->next = list->head;
    list->head = element;
    list->size++;
}

// Function to remove an element from the list
void RemoveElement(List* list, int data) {
    Element* current_pos = list->head;
    Element* prev = nullptr;

    while (current_pos != nullptr && current_pos->data != data) {
        prev = current_pos;
        current_pos = current_pos->next;
    }

    if (current_pos == nullptr) {
        return;
    }

    if (prev == nullptr) {
        list->head = current_pos->next;
    } else {
        prev->next = current_pos->next;
    }

    delete current_pos;
    list->size--;
}

// Function to shuffle all the elements of the list
void ShuffleList(Element** head) {
    int size = 0;
    Element* current = *head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    std::srand(std::time(nullptr));
    for (int i = 0; i < size - 1; i++) {
        int j = i + std::rand() % (size - i);
        current = *head;
        for (int k = 0; k < i; k++) {
            current = current->next;
        }
        Element* element1 = current;
        for (int k = i; k < j; k++) {
            current = current->next;
        }
        Element* element2 = current;
        int tmp = element1->data;
        element1->data = element2->data;
        element2->data = tmp;
    }
}

// Function to print all the elements of the list
void PrintList(List* list) {
    Element* current_pos = list->head;
    while (current_pos != nullptr) {
        std::cout << current_pos->data << " ";
        current_pos = current_pos->next;
    }
    std::cout << std::endl;
}

int main() {
    List* list = CreateList();

    int elem1 = 1;
    int elem2 = 2;
    int elem3 = 3;
    int elem4 = 4;
    int elem5 = 5;

    PreInsertHead(list, elem1);
    PreInsertHead(list, elem2);
    PreInsertHead(list, elem3);
    PreInsertHead(list, elem4);
    PreInsertHead(list, elem5);

    Element* prevElement = list->head->next;
    InsertElementAfter(prevElement, 6);

    Element** head = &list->head;
    Element* nextElement = list->head;
    InsertElementBefore(head, nextElement, 7);

    std::cout << "Elements added to the list: ";
    PrintList(list);

    RemoveElement(list, elem4);

    std::cout << "Elements still contained after remove function: ";
    PrintList(list);

    std::cout << "Shuffle List: ";
    ShuffleList(head);
    PrintList(list);

    return 0;
}
