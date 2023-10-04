#include <iostream>

struct Node {
    int data;
    Node* next;
};


void insertAtIndex(Node*& head, int data, int index) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (index < 0) {
        std::cerr << "Invalid index. Index should be non-negative." << std::endl;
        return;
    }

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int currentIndex = 0;

    while (temp != nullptr && currentIndex < index - 1) {
        temp = temp->next;
        currentIndex++;
    }

    if (temp == nullptr) {
        std::cerr << "Invalid index. Index exceeds the length of the list." << std::endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    
    for (int i = 1; i <= 5; ++i) {
        insertAtIndex(head, i, i - 1);
    }

    std::cout << "Linked List after initial insertions: ";
    display(head);

    
    insertAtIndex(head, 10, 2);

    std::cout << "Linked List after inserting at index 2: ";
    display(head);

    
    insertAtIndex(head, 20, 7);

    return 0;
}

