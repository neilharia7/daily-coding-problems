/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.
*/

#include<bits/stdc++.h>
using namespace std;


struct Node {
    int value;
    Node *next;
    
    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

struct comparator {
    bool operator()(const Node *left, const Node *right) const {
        return left->value > right->value;
    }
};

Node *merge_k_sorted_lists(Node *array_list[], int k) {
    // creating a priority std::queue<T> ;
    priority_queue<Node*, std::vector<Node*>, comparator> pq;
    
    for (int i = 0; i < k; ++i)
        pq.push(array_list[i]);
        
    Node *head = nullptr, *last = nullptr;
    
    while(!pq.empty()) {
        Node *min = pq.top();
        pq.pop();
        
        if (head == nullptr) {
            head = last = min;
        } else {
            last->next = min;
            last = min;
        }
        
        if (min->next != nullptr)
            pq.push(min->next);
    }
    
    return head;
}

int main() {
    
    int k = 4;
    Node *array_list[k];
    
    array_list[0] = new Node(1);
    array_list[0]->next = new Node(4);
    array_list[0]->next->next = new Node(5);
    
    array_list[1] = new Node(2);
    array_list[1]->next = new Node(4);
    array_list[1]->next->next = new Node(5);
    
    array_list[2] = new Node(3);
    array_list[2]->next = new Node(4);
    array_list[2]->next->next = new Node(5);
    
    array_list[3] = new Node(4);
    array_list[3]->next = new Node(5);
    array_list[3]->next->next = new Node(6);
    
    Node *head = merge_k_sorted_lists(array_list, k);
    
    while(head != nullptr) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    
    return 0;
}
