#include<stdio.h>
#include<conio.h>
#define SIZE 100
int stack[SIZE];
int top=-1;

void push(int val){
    if(top==SIZE-1) printf("Stack Overflow");
    else stack[++top]=val;
};

void pop(){
    if(top==-1) printf("Stack Underflow");
    top--;
}
void isEmpty(){
    if(top==-1) printf("its empty");
    else printf("its not empty");
}
void peek(){
    if(top==-1) printf("stack is empty");
    else printf("peek is %d",stack[top]);
}

void display(){
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
}

int precedence(char c){
    if(c=="^") return 3;
    if(c=="*" || c=="/") return 2;
    else return 1;
}

void infixToPrefix(char* exp){
    char postfix[SIZE];
    int i,k=0;
    for(int i=0;exp[i]!='/0';i++){
        char c=exp[i];
        
    }
}
int main(){
    push(10);
    char s="(a+(b*c))";
}