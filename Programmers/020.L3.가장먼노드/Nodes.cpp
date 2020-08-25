#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

//BFS
//재귀함수

using namespace std;

map<int,vector<int>> lists;
vector<int> bfs(unordered_set<int> v, unordered_set<int> done, vector<int> cnt){
    unordered_set<int> next;
    for(int i : v){
        if( !(done.find(i) != done.end()) ){
            done.insert(i);
            auto iter = lists.find(i);
            vector<int> tmp = iter->second;
            for(int j : tmp) next.insert(j);
        }
    }
    for(int i : done) next.erase(i);
    cnt[0]++;
    if(next.size() == 0){
        cnt[1] = v.size();
        return cnt;
    }
    vector<int> tmp = bfs(next, done, cnt);
    if(tmp[0]>cnt[0]) cnt = tmp;
    else if(tmp[0]==cnt[0]) cnt[1]++;
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int a,b;

    for(int i=0; i<edge.size(); i++){
        a = edge[i][0];
        b = edge[i][1];
        lists[a].push_back(b);
        lists[b].push_back(a);
    }
    unordered_set<int> done;
    vector<int> ans = bfs({1}, done, {-1,0});
    answer = ans[1];
    return answer;
}

int main(){
    int n = 6;
    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    cout<<solution(n, edge);
    return 0;
}
