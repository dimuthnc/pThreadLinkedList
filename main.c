#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


typedef struct node {
    int value;
    struct node * next;
} node_t;

node_t* createLinkedList(int value){
    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    head->value = value;
    head->next =NULL;
    return head;
}



void insert(node_t* head, int value){
    node_t* current =head;
    while(current->next!=NULL){
        current = current->next;
    }
    node_t* newNode =  malloc(sizeof(node_t));
    current->next = newNode;
    newNode->value = value;
    newNode->next =NULL;
}

void printLinkedList(node_t* head){
    node_t* current =head;
    while(current->next!=NULL){
        printf("%d \n",current->value);
        current = current->next;
    }
    printf("%d \n",current->value);

}

bool member(int value,node_t* head){
    node_t* current =head;
    while(current->value!=value && current->next!=NULL){
        current = current->next;
    }
    if(current->value==value){
        return true;
    }
    return false;

}
bool delete(int value,node_t* head){
    if(head->value==value){
        if(head->next==NULL){
            head->value = NULL;
            return 1;
        }
        else{
            head->value = head->next->value;
            head->next = head->next->next;
            return 1;
        }
    }
    else{
        node_t* current = head->next;
        node_t* previous =head;

        while(current->value!=value && current->next!=NULL){
            current =current->next;
            previous= previous->next;
        }
        if(current->value==value){
            previous->next = current->next;
            return 1;
        }
        else{
            return 0;
        }

    }

}



int main() {


    node_t * head = createLinkedList(1434);

    insert(head,2344);
    insert(head,33434);

    printLinkedList(head);

    printf("%d \n",delete(1434,head));

    printLinkedList(head);


    return 0;
}

