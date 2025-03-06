/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct job{
    int p;
    int d;
};
int cmp(const void* x, const void* y){
    struct job* a = (struct job*)x;
    struct job* b = (struct job*)y;
    return b->p > a->p;
}
int main(){
    int n;
    printf("Enter n value:\n");
    scanf("%d", &n);
    struct job jb[n];
    printf("\nEnter profit and deadline for every job:\n");
    for(int i = 0; i < n; i++){
        scanf("%d%d", &jb[i].p, &jb[i].d);
    }
    int maxd = INT_MIN;
    for(int i = 0; i < n; i++){
        if(jb[i].d > maxd){
            maxd = jb[i].d;
        }
    }
    int rq[maxd];
    for(int i = 0; i < maxd; i++){
        rq[i] = 0;
    }
    qsort(jb, n, sizeof(struct job), cmp);
    int profit = 0;
    for(int i = 0; i < n; i++){
        int cur = jb[i].d - 1;
        for(int j = cur; j >= 0; j--){
            if(rq[j] == 0){
                rq[j] =jb[i].p;
                break;
            }
        }
    }
    for(int i = 0; i < maxd; i++){
        if(rq[i] != 0){
            profit += rq[i];
        }
    }
    printf("\n%d", profit);
    return 0;
}
