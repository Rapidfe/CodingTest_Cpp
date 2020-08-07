#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

//BFS
//¹Ýº¹¹®

using namespace std;

map<int,vector<int>> lists;
int bfs(unordered_set<int> v){
    unordered_set<int> next;
    unordered_set<int> done;
    int ans;
    while(v.size()!=0){
        for(int i : v){
            if( !(done.find(i) != done.end()) ){
                done.insert(i);
                auto iter = lists.find(i);
                vector<int> tmp = iter->second;
                for(int j : tmp) next.insert(j);
            }
        }
        for(int i : done) next.erase(i);
        ans = v.size();
        v = next;
    }
    return ans;
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
    answer = bfs({1});
    return answer;
}

int main(){
    int n = 6;
    vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    cout<<solution(n, edge);
    return 0;
}
