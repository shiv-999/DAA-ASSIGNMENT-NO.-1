#include <iostream>

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        this->head = nullptr;
    }

    void addNode(int data) {
        Node *newNode = new Node(data);
        if (this->head == nullptr) {
            this->head = newNode;
        } else {
            Node *temp = this->head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() {
        Node *temp = this->head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList *list = new LinkedList();
    list->addNode(1);
    list->addNode(2);
    list->addNode(3);
    list->addNode(4);
    list->printList();
    return 0;
}
