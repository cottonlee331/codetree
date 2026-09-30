#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<vector<int>> P;
vector<bool> Pb;

long long ans = 4000000;

void backtracking(int k, int idx){
    Pb[idx] = true;
    if(k<n/2){
        for(int i = idx+1; i<n; i++){
            backtracking(k+1,i);
        }
    }
    else{
        long long a, b;
        a = b = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(Pb[i] && Pb[j]){
                    a+=P[i][j];
                }
                else if(!Pb[i] && !Pb[j]){
                    b+=P[i][j];
                }
            }
        }
        ans = min(ans,abs(a-b));
    }
    Pb[idx] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int i,j;
    i = j = 0;
    P.assign(n,vector<int>(n,0));
    Pb.assign(n,false);
    

    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            cin>>P[i][j];
        }
    }

    for(i = 0; i<=n/2; i++){
        backtracking(1,i);
    }

    cout<<ans;
    return 0;
}