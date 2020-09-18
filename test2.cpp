#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

bool cmp1(const pair<string,int> a, const pair<string,int> b){
    return (a.first) < (b.first);
}
bool cmp2(const pair<string,int> a, const pair<string,int> b){
    return (a.second) > (b.second);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    vector<vector<char>> orders2;
    for(int i=0; i<orders.size(); i++){
        vector<char> for_sort;
        for(int j=0; j<orders[i].size(); j++){
            for_sort.push_back(orders[i][j]);
        }
        sort(for_sort.begin(), for_sort.end());
        orders2.push_back(for_sort);
    }

    unordered_map<char,unordered_map<char,int>> map1;
    for(vector<char> i : orders2){
        for(int j=0; j<i.size(); j++){
            auto finding = map1.find(i[j]);
            if( finding == map1.end() ){
                unordered_map<char,int> tmp;
                for(int k=j+1; k<i.size(); k++){
                    if( tmp.find(i[k]) == tmp.end() ){
                        tmp[i[k]] = 1;
                    }else{
                        tmp[i[k]]++;
                    }
                }
                map1[i[j]] = tmp;
            }else{
                for(int k=j+1; k<i.size(); k++){
                    if( (finding->second).find(i[k]) == (finding->second).end() ){
                        (finding->second)[i[k]] = 1;
                    }else{
                        (finding->second)[i[k]]++;
                    }
                }
            }
        }
    }

    vector<pair<string,int>> lastv;
    set<int> set1;
    for(auto i=map1.begin(); i!=map1.end(); i++){
        for(auto j=(i->second).begin(); j!=(i->second).end(); j++){
            char tmp[] = {i->first, j->first};
            string tmp2 = "";
            tmp2 += tmp[0];
            tmp2 += tmp[1];
            lastv.push_back(make_pair(tmp2, j->second));
            set1.insert(j->second);
        }
    }

    sort(lastv.begin(), lastv.end(), cmp1);
    //sort(lastv.begin(), lastv.end(), cmp2);
    for(auto i : lastv){
        cout<<i.first<<" "<<i.second<<endl;
    }


    return answer;
}

int main(){
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2,3,4};

    solution(orders, course);
    return 0;
}
