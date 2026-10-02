#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> r = {-1,1,0,0};
vector<int> c = {0,0,-1,1};
vector<vector<bool>> ride;

int count_empty(int a, int b){
    int n = ride.size();
    int cnt = 0;
    for(int i = 0; i<4; i++){
        if(a+r[i]<0||a+r[i]>=n||b+c[i]<0||b+c[i]>=n)continue;
        if(!ride[a+r[i]][b+c[i]]) cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; 
    cin>>n;
    vector<pair<int,int>> vec(n*n+1,{-1,-1});
    vector<vector<int>> like(n*n+1,vector<int>(4));
    ride.assign(n,vector<bool>(n,false));
    vector<vector<int>> priority(n,vector<int>(n,0));


    for(int i = 0; i<n*n; i++){
        int idx;
        cin>>idx;
        cin>>like[idx][0]>>like[idx][1]>>like[idx][2]>>like[idx][3];

        int max_p = 0;
        pair<int,int> coor = {-1,-1};
        for(int j:like[idx]){
            if(vec[j].first<0) continue;    // 아직 배치 전이면 스킵
            int tmp_r = vec[j].first;
            int tmp_c = vec[j].second;

            for(int k = 0; k<4; k++){
                int new_r = tmp_r+r[k];
                int new_c = tmp_c+c[k];
                
                if(new_r<0 || new_r>=n || new_c<0 || new_c>=n ) continue;   // 놀이기구 범위를 벗어나는 경우 스킵
                if(ride[new_r][new_c]) continue;    // 칸이 비어 있지 않은 경우 스킵

                priority[new_r][new_c]++;
                if(priority[new_r][new_c]>max_p){   // 조건1 우선순위가 높음
                    max_p = priority[new_r][new_c];
                    coor = {new_r,new_c};
                }
                else if(priority[new_r][new_c]==max_p){
                    int cnt = count_empty(new_r,new_c)-count_empty(coor.first,coor.second);
                    if(cnt>0) coor = {new_r,new_c}; // 조건2 주변 빈칸이 많음
                    else if(cnt == 0){  // 조건3,4 좌표가 낮음
                        if(coor.first>new_r) coor = {new_r,new_c};
                        else if(coor.first==new_r) coor.second = min(new_c,coor.second);
                    }
                }
            }
        }

        if(max_p == 0){
            int cnt2 = -1;
            for(int x = 0; x<n; x++){
                if(cnt2==4) break;
                for(int y = 0; y<n; y++){
                    if(ride[x][y]) continue;
                    if(cnt2 == 4) break;
                    int cnt3 = count_empty(x,y);
                    if(cnt3>cnt2){
                        cnt2 = cnt3;
                        coor = {x,y};
                    }
                }
            }
        }
        ride[coor.first][coor.second] = true;
        vec[idx] = {coor.first,coor.second};
        priority.assign(n,vector<int>(n,0));
    }

    int ans = 0;
    for(int a = 1; a<=n*n; a++){ // 점수 계산
        int tmp_sum = 0;
        for(int b : like[a]){
            int sub_r = abs(vec[a].first - vec[b].first);
            int sub_c = abs(vec[a].second - vec[b].second);
            if(sub_r+sub_c == 1){
                if(tmp_sum==0) tmp_sum++;
                else tmp_sum*=10;
            }
        }
        ans+=tmp_sum;
    }

    cout<<ans;

    return 0;
}