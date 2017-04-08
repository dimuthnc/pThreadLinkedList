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



void addNode(node_t* head, int value){
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

int main() {


    node_t * head = createLinkedList(1434);

    addNode(head,2344);
    addNode(head,33434);

    printLinkedList(head);

    printf("%d \n",member(231,head));
    printf("%d \n",member(33434,head));


    return 0;
}

