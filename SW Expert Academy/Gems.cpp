#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool cmp(const vector<int> a, const vector<int> b){
    return a[1]>b[1];
}

void solution(vector<vector<int>> raw){
    int goal,ans,last31_1,last31_2,last32;
    cout<<"# -1";

    for(int j=2; j<=raw.size(); j++){
        vector<int> wait;
        goal = j;
        ans = 0;
        last31_1=0; last31_2=0; last32=0;
        unordered_map<int,vector<int>> map2;
        for(auto i=raw.begin(); i!=raw.end(); i++){
            cout<<(*i)[0]<<" "<<(*i)[1]<<endl;

            auto tmp = map2.find((*i)[0]);
            if(tmp == map2.end()){
                map2[(*i)[0]] = {(*i)[1]};
                cout<<"생성"<<endl;
            }else{
                if((tmp->second).size() == 1){
                    if(goal!=3){
                        (tmp->second).push_back((*i)[1]);
                        ans += (tmp->second)[0] + (*i)[1];
                        goal -= 2;
                        cout<<"추가"<<endl;
                    }else if(last31_1 != 0){
                        ans += last31_1 + (tmp->second)[0] + (*i)[1];
                        goal -= 3;
                        cout<<"끝 1+2"<<endl;
                    }else if(last32 == 0){
                        (tmp->second).push_back((*i)[1]);
                        last32 += (tmp->second)[0] + (*i)[1];
                        cout<<"대기 2"<<endl;
                    }
                }else{
                    if(goal>3){
                        ans += (*i)[1];
                        goal--;
                        cout<<"바로추가"<<endl;
                    }else if(goal==2){
                        if(last31_1 != 0){
                            ans += last31_1 + (*i)[1];
                            goal -= 2;
                            cout<<"끝 1+1"<<endl;
                        }else{
                            last31_1 += (*i)[1];
                            cout<<"대기 1"<<endl;
                        }
                    }else{
                        if(last31_1*last31_2 != 0){
                            ans += last31_1 + last31_2 + (*i)[1];
                            goal -= 3;
                            cout<<"끝 1+1+1"<<endl;
                        }else if(last32 != 0){
                            ans += last32 + (*i)[1];
                            goal -= 3;
                            cout<<"끝 2+1"<<endl;
                        }else if(last31_1 == 0){
                            last31_1 += (*i)[1];
                            cout<<"대기 1"<<endl;
                        }else if(last31_2 == 0){
                            last31_2 += (*i)[1];
                            cout<<"대기 1"<<endl;
                        }
                    }
                }
            }
            if(goal == 0) break;
        }
        if(goal == 0) cout<<" "<<ans;
        else cout<<" -1";
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> raw = {{2,19},{1,17},{4,13},{3,11},{1,7},{4,5},{2,3},{3,2}};
    solution(raw);

	return 0;
}
