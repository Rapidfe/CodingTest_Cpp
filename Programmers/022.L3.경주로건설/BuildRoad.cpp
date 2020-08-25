#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

//���ͽ�Ʈ�� ����
//BFS�� base��... queue���
//����cost�� ������Ʈ �ߴٸ� ������Ʈ�� node�� queue�� ����
//����cost�� ù ������Ʈ�̰ų� cost�� �� ���� ��� ������Ʈ��
//�ּ� cost�� ã���� �Ǵϱ� �ּҰ� �������� �����ϴ� ���� �߰�
//������Ʈ cost�� ������ ���Ŀ� ��ΰ� �ٸ� ���(������ �ٸ� ���) ���� ��� ���⿡ ���� cost�� �޶�����
//���� cost ������ ���� �ٸ��� �� �� queue�� �־�ߵ�
//�����غ��� ���� ���⿡ ���� ���� cost�� ���� �Ǵ� ��쵵 ����... �ʹ� �����ϴ�
//cost�� ���� 2������ �����ؼ� ����

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
