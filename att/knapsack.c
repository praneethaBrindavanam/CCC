
#include <stdio.h>
struct obj{
    int p;
    int w;
};
int max(int a, int b){
    return (a > b)?a:b;
}

int main(){
    int n;
    printf("\nEnter n value:\n");
    scanf("%d", &n);
    struct obj ob[n];
    printf("\nEnter profits and weights of %d objects:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &ob[i].p, &ob[i].w);
    }
    int m;
    printf("\nEnter capacity of knapsack\n");
    scanf("%d", &m);
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(ob[i-1].w > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(ob[i-1].p + dp[i-1][j-ob[i-1].w], dp[i-1][j]);
        }
    }
    printf("%d\n", dp[n][m]);

    return 0;
}
