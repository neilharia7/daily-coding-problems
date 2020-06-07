/*
This problem was asked by Amazon.

Given a linked list and an integer k, 
remove the k-th node from the end of the list and return the head of the list.

k is guaranteed to be smaller than the length of the list.

Do this in one pass.
*/

#include<bits/stdc++.h>
using namespace std;


struct Node {
    int val;
    struct Node *next;
};

void pop(struct Node** head, int pos) {
    if (head == NULL) {
        return;
    }
    
    struct Node *temp = *head;
    
    int i = 1;
    while (i < pos) {
        temp = temp->next;
        i++;
    }
    
    std::cout << temp->val << std::endl;
    
    if (temp->next->next == NULL) {
        temp->next = NULL;
        return;
    } else {
        temp = temp->next->next;
        temp->val = temp->next->val;
        
        std::cout << temp->val << std::endl;
        return;
    }
}


void push(struct Node** head, int val) {
    struct Node* newNode = new Node;
    struct Node *last = *head;
    
    newNode->val = val;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = newNode;
    return;
}

int main() {
    struct Node* head = NULL;
    
    for (int i = 0; i < 7; ++i) {
        push(&head, i + 1);
    }
    
    int k = 4;
    pop(&head, k);
    return 0;
}
