#include <iostream>
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    bool isPalindrome() {
        if (head == NULL) {
            return true; // An empty list is considered a palindrome.
        }

        // Implement a custom stack using a singly linked list
        Node* stackTop = NULL;
        Node* current = head;

       
        int length = 0;
        Node* slow = head;
        while (current) {
            length++;
            current = current->next;
            if (length % 2 == 0) {
               
                if (length > 2) {
                    Node* temp = slow->next;
                    slow->next = stackTop;
                    stackTop = slow;
                    slow = temp;
                }
            }
        }

        // Step 2: Compare the second half with the elements in the stack
        if (length % 2 == 0) {
            slow = slow->next;
        }
        while (slow) {
            if (slow->data != stackTop->data) {
                return false;
            }
            slow = slow->next;
            stackTop = stackTop->next;
        }

        return true;
    }
};

int main() {
    LinkedList ll;
    ll.addNode(1);
    ll.addNode(2);
    ll.addNode(2);
    ll.addNode(1);

    std::cout << "Linked List: ";
    Node* current = ll.head;
    while (current != NULL) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;

    if (ll.isPalindrome()) {
        std::cout << "The linked list is not a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is a palindrome.." << std::endl;
    }

    return 0;
}

