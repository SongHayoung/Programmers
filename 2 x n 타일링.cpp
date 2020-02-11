#include <string>
#include <vector>

using namespace std;


int solution(int n) {
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else{
        int dp[3] = {1,1,0};
        for(int i=2;i<=n;i++){
            dp[i%3] = (dp[(i+1)%3] + dp[(i+2)%3]) % 1000000007;
        }
        return dp[n%3];
    }
}
