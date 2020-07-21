#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//���� �ִµ� ���� ���Ҽ��� �ִ�... ���� �� ����
//�ٸ�Ǯ��: 0�ʱ�ȭ -> ������+1 -> ������-1 -> ������ ���ջ�

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    answer = n-lost.size();
    for(int j=0; j<2; j++){
        for(auto i=lost.begin(); i!=lost.end();){
            int now = *i;

            if(j==0){
                if(find(reserve.begin(),reserve.end(),now) != reserve.end()){
                    reserve.erase(find(reserve.begin(),reserve.end(),now));
                    lost.erase(i);
                    answer++;
                }else i++;
            }else{
                if(find(reserve.begin(),reserve.end(),now-1) != reserve.end()){
                    reserve.erase(find(reserve.begin(),reserve.end(),now-1));
                    answer++;
                }else if(find(reserve.begin(),reserve.end(),now+1) != reserve.end()){
                    reserve.erase(find(reserve.begin(),reserve.end(),now+1));
                    answer++;
                }
                i++;
            }
        }
    }
    return answer;
}

int main(){
    int n = 5;
    vector<int> lost = {2,3};
    vector<int> reserve = {1,3,5};
    cout<<solution(n,lost,reserve);
    return 0;
}
