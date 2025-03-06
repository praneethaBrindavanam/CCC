

Stack


#include <stdio.h>
#include <limits.h>
#define n 5
int s[n];
int top = -1;
void push(int);
int pop();
int peek();
int size();
int isFull();
int isEmpty();
int main(){
    int ch, x;
    char opn;
    do{
        printf("1.Push\n2.Pop\n3.Peek\n4.Size\n5.Full\n6.Emprty\nEnter your choice:\n");
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
            case 5: if(isFull()){
                        printf("\nStack overflow....\n");
                    }
                    else{
                        printf("\nstack is not full...\n");
                    }
                    break;
            case 6: if(isEmpty()){
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
void push(int x){
    if(top >= n-1){
        printf("\nStack overflow, insertion i snot possible...");
    }
    else{
        top++;
        s[top] = x;
    }
}
int pop(){
    int x;
    if(top == -1){
        printf("\nStack underflow, can't delete any element so ");
        x = INT_MIN;
    }
    else{
        x = s[top];
        top--;
    }
    return x;
}
int peek(){
    int x;
    if(top == -1){
        printf("\nStack underflow, no element at the top so ");
        x = INT_MIN;
    }
    else{
        x = s[top];
    }
    return x;
}
int size(){
    return top + 1;
}
int isFull(){
    if(top >= n-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
