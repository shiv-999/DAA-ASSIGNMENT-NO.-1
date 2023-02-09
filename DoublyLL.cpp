#include <bits/stdc++.h>
using namespace std;

// structure to define a node of the doubly linked list
struct node{
    
    // part which will store data
    int data;
    // pointer to the previous node
    struct node *prev;
    // pointer to the next node
    struct node *next;
    
};

int main() {
    
    // we will create a doubly linked list of size 2
    
    // create the head node of the doubly linked list
    node* head_node = new node();
    // assign data to the head node
    head_node->data = 5;
    // assign prev pointer to the head node
    head_node->prev = NULL;
    
    // create the second node of the doubly linked list
    node* second_node = new node();
    // assign data to the second node
    second_node->data = 4;
    // assign prev pointer to the second node
    second_node->prev = head_node;
    // assign next pointer to the second node
    second_node->next = NULL;
    
    // assign next pointer to the head node
    head_node->next = second_node;
    
    // print the list
    while(head_node != NULL){
        cout<<head_node->data<<" ";
        head_node = head_node->next;
    }
    
    return 0;
}
