#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXX_K 10000
#define MAXX_N 100

int n,k;
int dp[MAXX_K+1],coin[MAXX_N+1];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&coin[i]);
    
    dp[0]=1;
    
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            if(j-coin[i]>=0)
                dp[j]+=dp[j-coin[i]];
        }
    }
    printf("%d",dp[k]);
    
}
