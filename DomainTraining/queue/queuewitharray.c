#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front=-1, rear=-1;
int isEmpty(){
    return (front==-1 || front>rear); 
}
int isFull(){
    return (rear==SIZE-1);
}

void enqueue(int x){
    if(isFull()){
        printf("queue overflow\n");
        return;
    }
    if(front==-1) front=0;
    queue[++rear]=x;
    printf
}