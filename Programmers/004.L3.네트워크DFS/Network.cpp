#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> dfs(int now, vector<int> isEnd, vector<vector<int>> computers){
    if(isEnd[now] != 0){
        isEnd[now] = 0;
        cout<<now;
        for(int i=0; i<isEnd.size(); i++){
            if(i != now && computers[now][i] == 1){
                isEnd = dfs(i, isEnd, computers);
            }
        }
    }
    return isEnd;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> isEnd;
    for(int i = 0; i<n; i++){
        isEnd.push_back(1);
    }
    for(int i = 0; i<n; i++){
        if(isEnd[i] == 1){
            answer++;
            isEnd = dfs(i, isEnd, computers);
            cout<<endl;
        }
    }

    return answer;
}


int main(){
    int n = 3;
    vector<vector<int>> computers = {{1,1,0},
                                        {1,1,0},
                                        {0,0,1}};
    cout<<solution(n, computers);
    return 0;
}
