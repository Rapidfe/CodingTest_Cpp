#include <iostream>
#include <vector>
#include <set>

using namespace std;

int sero, garo, majimac;
int dfs(vector<vector<int>> board, int a, int b, int c, int d){ // abcd: (행, 렬, 전 방향, 누적비용)
    set<int> ans;
    int save_c=c, save_d=d, tmp;
    int door = 0;
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    board[a][b] = 1;
    if(a*garo + b == majimac){
        return d;
    }
    if( (a < sero-1) && (board[a+1][b] == 0) ){
        //cout<<board[a+1][b]<<endl;
        if(c == 0){
            c = 1;
            d += 100;
        }
        else if(c == 1) d += 100;
        else{
            c = 1;
            d += 600;
        }
        tmp = dfs(board, a+1, b, c, d);
        if( tmp != -1 ) ans.insert( tmp );
        //cout<<"insert: "<<tmp<<endl;
        door = 1;
        //cout<<"door case 1"<<endl;
    }
    c=save_c;
    d=save_d;
    if( (b < garo-1) && (board[a][b+1] == 0) ){
        if(c == 0){
            c = 2;
            d += 100;
        }
        else if(c == 2) d += 100;
        else{
            c = 2;
            d += 600;
        }
        tmp = dfs(board, a, b+1, c, d);
        if( tmp != -1 ) ans.insert( tmp );
        //cout<<"insert: "<<tmp<<endl;
        door = 1;
        //cout<<"door case 2"<<endl;
    }
    if( (a > 0) && (board[a-1][b] == 0) ){
        if(c == 0){
            c = 1;
            d += 100;
        }
        else if(c == 1) d += 100;
        else{
            c = 1;
            d += 600;
        }
        tmp = dfs(board, a-1, b, c, d);
        if( tmp != -1 ) ans.insert( tmp );
        //cout<<"insert: "<<tmp<<endl;
        door = 1;
        //cout<<"door case 3"<<endl;
    }
    if( (b > 0) && (board[a][b-1] == 0) ){
        if(c == 0){
            c = 2;
            d += 100;
        }
        else if(c == 2) d += 100;
        else{
            c = 2;
            d += 600;
        }
        tmp = dfs(board, a, b-1, c, d);
        if( tmp != -1 ) ans.insert( tmp );
        //cout<<"insert: "<<tmp<<endl;
        door = 1;
        //cout<<"door case 4"<<endl;
    }
    if(door && !ans.empty()) return *(ans.begin());
    return -1;
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    sero = board.size();
    garo = board[0].size();
    majimac = sero*garo-1;

    answer = dfs(board, 0, 0, 0, 0);
    return answer;
}

int main(){
    vector<vector<int>> board = {{0,0,0,0,0,0,0,1},
                                 {0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,1,0,0},
                                 {0,0,0,0,1,0,0,0},
                                 {0,0,0,1,0,0,0,1},
                                 {0,0,1,0,0,0,1,0},
                                 {0,1,0,0,0,1,0,0},
                                 {1,0,0,0,0,0,0,0}};

    cout<<solution(board);
    return 0;
}
