#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

int thread_count = 5;
pthread_mutex_t mutex;

typedef struct node {
    int value;
    struct node * next;
} node_t;


node_t* head;




node_t* createNewLinkedList(int value){
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

bool member(node_t* head,int value){
    node_t* current =head;
    while(current->value!=value && current->next!=NULL){
        current = current->next;
    }
    if(current->value==value){
        return true;
    }
    return false;

}
bool delete(node_t* head,int value){
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




node_t* createRandomLinkedList(int n){



    int i,j,num;
    time_t t;
    int randomNumbers[n];



    /* Intializes random number generator */
    srand((unsigned) time(&t));

    bool isValueTaken[65535];

    for( j = 0 ; j < 65535 ; j++ ){
        isValueTaken[j]=0;
    }
    i=0;
    while(i<n){
        num =rand() % 65535;
        while(isValueTaken[num]){
            num =rand() % 65535;
        }

        randomNumbers[i] =num;
        i++;
    }

    node_t* head = createNewLinkedList(randomNumbers[0]);

    for(int i=1;i<100;i++){
        insert(head,randomNumbers[i]);
    }
    return head;

}

void operation(int operationID,int value){

    if(operationID==1){
        printf("insert called \n");
        insert(head,value);

    }
    else if(operationID==2){
        printf("member called \n");
        member(head,value);

    }
    else if(operationID==3){
        printf("delete called \n");
        delete(head,value);

    }



}



void* oneMutexForLinkedList(void* rank){
    int my_rank =(int) rank+1;
    int operationID = (my_rank%3)+1;

    pthread_mutex_lock(&mutex);

    operation(operationID,123);



    printf("hello from thread %d of %d \n",my_rank,thread_count);

    pthread_mutex_unlock(&mutex);
    return NULL;
}





int main() {

    head =createRandomLinkedList(1000);
    printLinkedList(head);

    long thread;
    pthread_t* thread_handles;

    thread_handles = malloc(thread_count*sizeof(pthread_t));

    for(thread=0;thread<thread_count;thread++){
        pthread_create(&thread_handles[thread],NULL,oneMutexForLinkedList,(void*) thread);

    }

    printf("Hello from main thread \n");

    for(thread=0;thread<thread_count;thread++){

        printf("trying to join threads %d \n",thread);

        pthread_join(thread_handles[thread],NULL);



    }


    //free(thread_handles);
    system("pause");


    return 0;
}

