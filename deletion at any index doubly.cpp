#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteAtIndex(Node*& head, int index) {
    if (index < 0) {
        std::cerr << "Invalid index. Index should be non-negative." << std::endl;
        return;
    }

    if (head == nullptr) {
        std::cerr << "Linked list is empty. Cannot delete from an empty list." << std::endl;
        return;
    }

    Node* temp = head;

    for (int i = 0; i < index; ++i) {
        if (temp->next == nullptr) {
            std::cerr << "Invalid index. Index exceeds the length of the list." << std::endl;
            return;
        }
        temp = temp->next;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

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

    for (int i = 1; i <= 5; ++i) {
        insertAtEnd(head, i);
    }

    std::cout << "Doubly Linked List before deletion: ";
    display(head);

    deleteAtIndex(head, 2);

    std::cout << "Doubly Linked List after deletion at index 2: ";
    display(head);

    deleteAtIndex(head, 7);

    return 0;
}

