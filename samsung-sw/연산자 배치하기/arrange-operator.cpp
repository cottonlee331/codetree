#include <iostream>
#include <vector>
using namespace std;

int n,min_n,max_n,tmp;
vector<int> num;
vector<int> op;

void backtracking(int k,int idx){
    if(op[idx]<=0){
        return;
    }
    int org = tmp;
    op[idx]--;
    switch(idx){
        case 0:
            tmp += num[k];
            break;
        case 1:
            tmp -= num[k];
            break;
        case 2:
            tmp *= num[k];
            break;
        default:
            break;
    }
    if(k+1 == n){
        min_n = min(tmp,min_n);
        max_n = max(tmp,max_n);
    }
    else{
        for(int i = 0; i<3; i++){
            backtracking(k+1,i);
        }
    }
    tmp = org;
    op[idx]++;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    min_n = 1000000000;
    max_n = -1000000000;
    op.assign(3,0);
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>tmp;
        num.push_back(tmp);
    }
    cin>>op[0]>>op[1]>>op[2];

    for(int j = 0; j<3; j++){
        tmp = num[0];
        backtracking(1,j);
    }

    cout<<min_n<<' '<<max_n;

    return 0;
}