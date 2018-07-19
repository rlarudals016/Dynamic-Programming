#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXX_N 1000
#define INF 1234567890

int color[MAXX_N+1][4],dp[MAXX_N+1][4],n;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&color[i][j]);
        }
    }
    dp[0][0]=color[0][0];
    dp[0][1]=color[0][1];
    dp[0][2]=color[0][2];
    
    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][1]+color[i][0],dp[i-1][2]+color[i][0]);
        dp[i][1]=min(dp[i-1][0]+color[i][1],dp[i-1][2]+color[i][1]);
        dp[i][2]=min(dp[i-1][0]+color[i][2],dp[i-1][1]+color[i][2]);
    }
    int ans=INF;
    for(int i=0;i<3;i++)
        ans=min(ans,dp[n-1][i]);
    printf("%d",ans);
}
