#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> vec;
    int leader, teammate;

    cin>>n;
    for(int i = 0; i<n; i++){
        int tmp;
        cin>> tmp;
        vec.push_back(tmp);
    }
    cin>> leader >> teammate;

    long long tot = 0;
    for(int j = 0; j<n; j++){
        tot++;
        vec[j]-=leader;
        if(vec[j]<=0) continue;
        tot+=(vec[j]/teammate);
        if(vec[j]%teammate!=0){
            tot++;
        }
    }
    cout<<tot;
    return 0;
}