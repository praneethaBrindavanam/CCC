/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

stack using linked list



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node{
    int d;
    struct node* next;
};
struct node* top = NULL;
int c = 0;
struct node* push(int);
int pop();
int peek();
int size();
int isFull();
int isEmpty();
int main(){
    int ch, x;
    char opn;
    do{
        printf("1.Push\n2.Pop\n3.Peek\n4.Size\n5.Emprty\nEnter your choice:\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("\nEter element to be pushed:\n");
                    scanf("%d", &x);
                    push(x);
                    break;
            case 2: printf("\nThe popped element from stack is %d\n", pop());
                    break;
            case 3: printf("\nThe element at the top of the stack is %d\n", peek());
                    break;
            case 4: printf("\nThere are %d elements in the stack\n", size());
                    break;
            case 5: if(isEmpty()){
                        printf("\nStack underflow....\n");
                    }
                    else{
                        printf("\nstack is not empty...\n");
                    }
                    break;
            default: printf("\nInvalid choice..."); 
        }
        printf("\nDo you want to continue?(y/n)");
        scanf(" %c", &opn);
    }while(opn == 'Y' || opn == 'y');
    return 0;
}
struct node* push(int x){
    c++;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->d = x;
    newNode->next = NULL;
    if(top == NULL){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
    return top;
}
int pop(){
    int x;
    if(top == NULL){
        printf("\nStack underflow, can't delete any element so ");
        x = INT_MIN;
    }
    else{
        x = top->d;
        struct node* temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
    }
    c--;
    return x;
}
int peek(){
    int x;
    if(top == NULL){
        printf("\nStack underflow, no element at the top so ");
        x = INT_MIN;
    }
    else{
        x = top->d;
    }
    return x;
}
int size(){
    return c;
}

int isEmpty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
