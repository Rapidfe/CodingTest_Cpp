#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

//다익스트라 응용
//BFS를 base로... queue사용
//다음cost를 업데이트 했다면 업데이트한 node를 queue에 넣음
//다음cost는 첫 업데이트이거나 cost가 더 작은 경우 업데이트함
//최소 cost만 찾으면 되니까 최소가 나왔으면 종료하는 조건 추가
//업데이트 cost는 같은데 거쳐온 경로가 다른 경우(방향이 다른 경우) 다음 경로 방향에 따라 cost가 달라진다
//따라서 cost 같더라도 방향 다르면 둘 다 queue에 넣어야됨
//생각해보니 이전 방향에 따라 다음 cost가 역전 되는 경우도 있음... 너무 복잡하다
//cost를 방향 2가지를 구분해서 저장

using namespace std;

int sero, garo, majimac;
int dijk(vector<vector<int>> board){
    int row, col, pre, nowCost, newCost, nowMin=-1;
    vector<vector<vector<int>>> costs(sero,vector<vector<int>> (garo, {-1,-1}));
    queue<vector<int>> tasks;
    vector<int> now;
    costs[0][0][0] = 0;
    costs[0][0][1] = 0;
    tasks.push({0,0,0});

    while(!tasks.empty()){
        now = tasks.front();
        tasks.pop();
        row = now[0];
        col = now[1];
        pre = now[2];
        if(pre==0) nowCost = 0;
        else nowCost = costs[row][col][pre-1];
        if( row==sero-1 && col==garo-1 ){
            nowMin = nowCost;
            continue;
        }
        if( nowMin==-1 || nowMin>nowCost ){
            if( (row<sero-1) && (board[row+1][col]!=1) ){
                if(pre==0 || pre==1) newCost = nowCost+100;
                else newCost = nowCost+600;
                int* tmp = &costs[row+1][col][0];
                if( (*tmp == -1) || (*tmp!=-1)&&(*tmp>newCost) ){
                    *tmp = newCost;
                    tasks.push({row+1, col, 1, newCost});
                }
            }
            if( (col<garo-1) && (board[row][col+1]!=1) ){
                if(pre==0 || pre==2) newCost = nowCost+100;
                else newCost = nowCost+600;
                int* tmp = &costs[row][col+1][1];
                if( (*tmp == -1) || (*tmp!=-1)&&(*tmp>newCost) ){
                    *tmp = newCost;
                    tasks.push({row, col+1, 2, newCost});
                }
            }
            if( (row>0) && (board[row-1][col]!=1) ){
                if(pre==0 || pre==1) newCost = nowCost+100;
                else newCost = nowCost+600;
                int* tmp = &costs[row-1][col][0];
                if( (*tmp == -1) || (*tmp!=-1)&&(*tmp>newCost) ){
                    *tmp = newCost;
                    tasks.push({row-1, col, 1, newCost});
                }
            }
            if( (col>0) && (board[row][col-1]!=1) ){
                if(pre==0 || pre==2) newCost = nowCost+100;
                else newCost = nowCost+600;
                int* tmp = &costs[row][col-1][1];
                if( (*tmp == -1) || (*tmp!=-1)&&(*tmp>newCost) ){
                    *tmp = newCost;
                    tasks.push({row, col-1, 2, newCost});
                }
            }
        }
    }
    return nowMin;
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    sero = board.size();
    garo = board[0].size();
    majimac = sero*garo-1;

    answer = dijk(board);
    return answer;
}

int main(){
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0}
    };

    cout<<solution(board);
    return 0;
}
