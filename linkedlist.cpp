#include <iostream> 

// Struct to define an Element
struct Element {
    int data;
    Element* next;
};

// Struct to define a List
struct List {
    Element* head;
    int size;
};

// Function to create a new Element
Element* CreateElement(int data) {
    Element* element = new Element;
    element->data = data;
    element->next = nullptr;
    return element;
}

// Function to create a List
List* CreateList() {
    List* list = new List;
    list->head = nullptr;
    list->size = 0;
    return list;
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

// Function to reverse the list
void ReverseList(List* list) {
    Element* current_pos = list->head;
    Element* prev = nullptr;
    Element* next = nullptr;

    while (current_pos != nullptr) {
        next = current_pos->next;
        current_pos->next = prev;
        prev = current_pos;
        current_pos = next;
    }

    list->head = prev;
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

    std::cout << "Elements added to the list: ";
    PrintList(list);

    Element* to_remove = list->head;
    RemoveElement(list, elem4);

    std::cout << "Elements still contained after remove function: ";
    PrintList(list);

    std::cout << "Reverse List: ";
    ReverseList(list);
    PrintList(list);

    delete list;

    return 0;
}
