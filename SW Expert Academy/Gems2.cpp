#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

bool cmp(const vector<int> a, const vector<int> b){
    return a[1]>b[1];
}
bool cmp1(const vector<float> a, const vector<float> b){
    return a[2]>b[2];
}

void solution(vector<vector<int>> raw, int colors, int n){
     unordered_map<int,vector<int>> map1;
     vector<vector<float>> newv;
     for(auto i : raw){
        auto j = map1.find(i[0]);
        if( j == map1.end() ){
            map1[i[0]] = {i[1]};
        }else if( (j->second).size() == 1 ){
            (j->second).push_back(i[1]);
            newv.push_back({i[0], 2, ((j->second)[0]+(j->second)[1])/2.0});
        }else{
            (j->second).push_back(i[1]);
            newv.push_back({(-1)*i[0], 1, i[1]});
        }
     }

     sort(newv.begin(), newv.end(), cmp1);
    /*
     for(auto i : newv){
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
     }
     */
     vector<vector<int>> wii;
     int vsize = newv.size();
     if(raw.size() > 2){
         vector<vector<int>> wi(raw.size()-2, {0});
         vector<int> row1(vsize+1, 0);
         wi[0] = row1;

         vector<int> sizeone(raw.size()-2, 0);
         vector<int> totalw(raw.size()-2,0);
         vector<int> maxIdx(raw.size()-2,-1);


         for(int i=1; i<vsize+1; i++){// sizeone2 업데이트 해야됨
            auto now = newv[i-1];
            int val = now[1]*now[2];
            vector<int> sizeone2(raw.size()-2);
            vector<int> totalw2(raw.size()-2);
            for(int j=1; j<raw.size()-2; j++){
                if( now[1]<=j ){   // 개수가 제한보다 작으면
                    if( wi[j-now[1]][i-1]+val > wi[j][i-1] ){    // 이거 넣는게 가치 가장 큰 경우면
                        if( now[0]>0 ){    // 2개 묶음인 경우 : 남은 자리가 3개인데 2개뿐이면 무시
                            wi[j].push_back(wi[j-now[1]][i-1]+val);
                            sizeone2[j] = sizeone[j-now[1]] + map1[now[0]].size() - 2;
                            maxIdx[j] = i-1;
                            int tmp = map1[now[0]][2];
                            totalw2[j] = totalw[j-now[1]]+now[1];
                        }else if( j-totalw[j]!=1 ){
                            wi[j].push_back(wi[j-now[1]][i-1]+val);
                            maxIdx[j] = i-1;
                            sizeone2[j]--;
                            totalw2[j] = totalw[j-now[1]]+now[1];
                        }else{
                            wi[j].push_back(wi[j][i-1]);
                            sizeone2[j] = sizeone[j];
                            totalw2[j] = totalw[j];
                        }
                    }else{
                        wi[j].push_back(wi[j][i-1]);
                        sizeone2[j] = sizeone[j];
                        totalw2[j] = totalw[j];
                    }
                }else{
                    wi[j].push_back(wi[j][i-1]);
                    sizeone2[j] = sizeone[j];
                    totalw2[j] = totalw[j];
                }
            }
            sizeone = sizeone2;
            totalw = totalw2;
         }
         /*
         for(auto i : wi){
            for(int j : i){
                cout<<j<<" ";
            }
            cout<<endl;
         }
         */
         for(int i=0; i<raw.size()-2; i++){
            int thisw = i+3-totalw[i];
            int thisi = maxIdx[i];
            vector<float> now;
            //cout<<thisw<<endl;
            if( thisw==4 ){
                now = newv[thisi+1];
                if( now[0]<0 ){
                    wi[i][vsize] += now[2];
                    thisi++;
                    thisw--;
                }else{
                    wi[i][vsize] += now[1]*now[2];
                    thisi++;
                    int lastw1=0, lastw2=0;
                    while( thisi != vsize-1 && (lastw1<=0 || lastw2==0) ){
                        now = newv[thisi+1];
                        if( lastw2==0 && now[0]>0 ){ // 2개짜리
                            lastw2 = now[1]*now[2];
                        }
                        if( lastw1<=0 && now[0]<0 ){ // 1개짜리
                            if(lastw1==0) lastw1 = (-1)*now[2];
                            else if(lastw1<0) lastw1 = (-1)*lastw1+now[2];
                        }
                        thisi++;
                    }
                    if(lastw1!=0 || lastw2!=0){
                        if(lastw1 > lastw2) wi[i][vsize] += lastw1;
                        else wi[i][vsize] += lastw2;
                        thisw = 0;
                    }
                }
            }
            if( thisw==3 ){
                unordered_map<int,vector<int>> lastmap;
                while(thisi != vsize-1 && thisw != 0){
                    now = newv[thisi+1];
                    if( now[0]>0 ){ // 2개짜리
                        if( map1[now[0]].size()!=2 || sizeone[i]!=0 ){ // 딱 2개만 있거나, 1개짜리 없으면 패스
                            if( lastmap.find(-1) != lastmap.end() ){
                                wi[i][vsize] += lastmap[-1][1] + now[1]*now[2];
                                thisw = 0;
                            }else lastmap[now[0]] = {2,now[1]*now[2]};
                        }
                    }else{ // 1개짜리
                        if( lastmap.find((-1)*now[0]) != lastmap.end() ){ // 같은색 2개짜리 들어간게 있으면 종료
                            wi[i][vsize] += lastmap[(-1)*now[0]][1] + now[2];
                            thisw = 0;
                        }else if( lastmap.size() != 0 ){
                            auto tmp = lastmap.begin();
                            int minn = 0;
                            for(; tmp!=lastmap.end(); tmp++){
                                if( (tmp->first)<minn ) minn = tmp->first;
                                else if( (tmp->first)>0 && (tmp->second)[0]==2 ) break; // 다른색 2개짜리 들어간게 있으면 종료
                            }
                            if( tmp!=lastmap.end() ){
                                wi[i][vsize] += (tmp->second)[1] + now[2];
                                thisw = 0;
                            }else{  // 1개짜리 끼리 모음
                                if( minn==-2 ){
                                    wi[i][vsize] += lastmap[-2][1] + now[2];
                                    thisw = 0;
                                }else if(minn==-1){
                                    lastmap[-2] = {2,lastmap[-1][1]+now[2]};
                                }
                            }
                        }else lastmap[-1] = {1,now[2]};
                    }
                    thisi++;
                }
            }
            if( thisw>0 ) wi[i][vsize] = -1;
            //cout<<"   "<<wi[i][vsize]<<endl;
         }
         wii = wi;
     }
     cout<<"#"<<n<<" -1 "<<newv[0][1]*newv[0][2];
     if( !wii.empty() ){
         for(int i=0; i<raw.size()-2; i++){
            cout<<" "<<wii[i][vsize];
         }
     }
}

int main()
{
    vector<vector<int>> raw = {{2,19},{1,17},{4,13},{3,11},{1,7},{4,5},{2,3},{3,2}};
    //vector<vector<int>> raw = {{2,5},{2,4},{1,3},{1,2},{1,1}};
    solution(raw, 4, 1);

	return 0;
}
