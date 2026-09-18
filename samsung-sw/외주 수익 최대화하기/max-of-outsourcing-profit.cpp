#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t, p;
    cin>>n;
    vector<int> dp(n,0);
    int mx = 0;
    for(int i = 0; i<n; i++){
        cin>>t>>p;
        if(i!=0){
            dp[i] = max(dp[i],dp[i-1]);
        }
        if(i+t-1>=n) continue;
        dp[i+t-1] = max(dp[i+t-1],dp[i-1]+p);
        mx = max(mx,dp[i+t-1]);
    }

    cout<<mx;

    return 0;
}