#include <stdio.h>
#include <malloc.h>


typedef struct node {
    int value;
    struct node * next;
} node_t;

int main() {


    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }

    head->value = 1;
    head->next = malloc(sizeof(node_t));
    head->next->value = 2;
    head->next->next = NULL;

    printf("%d \n",head->value);

    node_t* current = head->next;
    printf("%d \n",current->value);

    return 0;
}