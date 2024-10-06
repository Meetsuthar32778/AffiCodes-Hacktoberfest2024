#include <stdio.h>
#include <stdlib.h>
#define max 10

struct Queue{
    int *p;
    int fp;
    int rp;
};

void enqueue(struct Queue *queue){
    if(queue->fp == -1 && queue->rp == -1){
        queue->fp =0;
        queue->rp =0;
    }
    if (queue->rp > max-2 ){
        printf("Your Queue is full !\n");
    }
    else{
        int x;
        queue->rp +=1;
        printf("Enter the integer : ");
        scanf("%d",&x);
        *(queue->p + queue->rp) = x;
        printf("Your value has been added Successfully.\n");
    }
};

void dequeue(struct Queue *queue,int x){
    for(int i=0;i<x;i++){
        if((queue->fp > queue->rp-1) || (queue->fp == -1) ){
            printf("Your Queue is empty !\n");
            break;
        }
        else{
            printf("Value %d from Queue has been deleted.\n",*(queue->p+queue->fp+1));
            queue->fp +=1;
        }
    }
};

void display(struct Queue *queue){
    if(queue->fp == -1 && queue->rp == -1){
        printf("Queue is empty !\n");
    }
    else{
        printf("Elements = ");
        for(int i = queue->fp+1 ; i <= queue->rp ; i++){
            printf(" %d ",*(queue->p+i));
        }
        printf("\n");
    }
};

int main(){
    struct Queue queue;

    queue.p = (int *)malloc(sizeof(int)*max);
    queue.fp=-1;
    queue.rp=-1;

    int select =0,delete;
    while ( select !=4){
        printf("1.To Add Integer in queue\n2.To Delete From queue\n3.To Display queue\n4.Exit\nAns : ");
        scanf("%d",&select);
        switch (select)
        {
        case 1:
            enqueue(&queue);
            break;
        case 2:
            printf("Enter the No.of element to delete : ");
            scanf("%d",&delete);
            dequeue(&queue,delete);
            break;
        case 3:
            display(&queue);
            break;
        case 4:
            printf("Exit successfully");
            break;
        default:
            printf("You entered worng number!\nEnter valid number\n");
            break;
        }
    }
    return 0;
}
