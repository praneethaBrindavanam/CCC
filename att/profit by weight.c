/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct obj{
    int p;
    int w;
    double r;
};
int cmp(const void* x, const void* y){
    struct obj* p = (struct obj*)x;
    struct obj* q = (struct obj*)y;
    return q->r > p->r;
}
int main(){
    int n;
    printf("Enter n value:\n");
    scanf("%d", &n);
    struct obj ob[n];
    printf("\nEnter profit and weight for every object:\n");
    for(int i = 0; i < n; i++){
        scanf("%d%d", &ob[i].p, &ob[i].w);
    }
    for(int i = 0; i < n; i++){
        ob[i].r = (double)ob[i].p/ob[i].w;
    }
    qsort(ob, n, sizeof(struct obj), cmp);
    int m, i;
    printf("\nEnter capacity of Knapsack:\n");
    scanf("%d", &m);
    double profit = 0;
    for(i = 0; i < n; i++){
        if(ob[i].w > m) break;
        m -= ob[i].w;
        profit += ob[i].p;
    }
    if(i != n){
        profit += (m*ob[i].r);
    }
    printf("\n%lf", profit);
    return 0;
}
