#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int Length(Node* head) {
    Node* current(head);
    int length(0);

    while(current != nullptr) {
        current = current->next;
        length++;
    }

    return length;
}

void Insert(Node** head, int data, int position) {
    Node* p(*head);
    Node* q;
    Node* node = (Node*) malloc(sizeof(Node));

    node->data = data;
    
    if (position == 0) {
        node->next = p;
        *head = node;
    } else {
        int i(0);

        while (p != nullptr && i < position) {
            i++;
            q = p;
            p = p->next;
        }
        
        q->next = node;
        
        if (p == nullptr) {
            node->next = nullptr;
        } else {
            node->next = p;
        }
    }
}

void Delete(Node** head, int position) {
    Node* p;
    Node* q;

    if (*head == nullptr) {
        return;
    }

    p = *head;

    if (position == 0) {
        *head = (*head)->next;
        free(p);
    } else {
        int i(0);

        while (p != nullptr && i < position) {
            i++;
            q = p;
            p = p->next;
        }

        if (p != nullptr) {
            q->next = p->next;
            free(p);
        }
    }
}

void Delete(Node** head) {
    Node* auxilary;
    Node* iterator(*head);

    while (iterator != nullptr) {
        auxilary = iterator->next;
        free(iterator);
        iterator = auxilary;
    }
    
    *head = nullptr;
}
