#include <iostream>

struct Node {
    int data;
    Node* next;
};


void deleteAtStart(Node*& head) {
    if (head == nullptr) {
        std::cerr << "Linked list is empty. Cannot delete from an empty list." << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
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

    
    for (int i = 5; i >= 1; --i) {
        Node* newNode = new Node();
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    std::cout << "Linked List before deletion: ";
    display(head);

    
    deleteAtStart(head);

    std::cout << "Linked List after deletion: ";
    display(head);

    return 0;
}

