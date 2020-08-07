#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> gem;
    map<string,int> lists;
    for(string i : gems) gem.insert(i);
    int howMany = gem.size();
    int check = 0;
    for(string i : gem) lists[i] = 0;
    gem.clear();


    answer.push_back(0);
    answer.push_back(100000);
    int st=1, ed=1, len=100000;
    string sst, sed;

    while(ed!=gems.size()+1){
        sst = gems[st-1];
        sed = gems[ed-1];
        cout<<"("<<st<<", "<<ed<<")   ";

        if(len==100000){
            lists[sed]++;
            ed++;
            if( lists[sed]==1 ){
                check++;
            }
        }else if(check < howMany){
            lists[sed]++;
            ed++;
            if( lists[sed]==1 ) check++;
            lists[sst]--;
            st++;
            if( lists[sst]==0 ) check--;
        }
        cout<<check<<endl;
        if(check >= howMany){
            if(ed-st < len){
                answer = {st, ed};
                len = ed-st;
            }
            lists[sst]--;
            st++;
            if( lists[sst]==0 ){
                check--;
            }
        }
    }

    return answer;
}

int main(){
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};

    vector<int> answer = solution(gems);
    cout<<answer[0]<<" "<<answer[1];
    return 0;
}
