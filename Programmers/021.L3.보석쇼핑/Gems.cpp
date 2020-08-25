#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

// 1.�տ������� ù��° �� ã��
// 2.�� �ں��ʹ� (���� ũ��-1)��ŭ��(window) �˻�
// 3.�� �� ������ �װɷ� �ڿ� �˻�
//���̵� ����� ������ ������ �������� �����
//�׳� �����ϰ� ®��
//���� ������ �������� ��������

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

    int st=0, ed=0, state=1;
    string sst, sed;

    while(ed!=gems.size() || state == 2){
        sst = gems[st];
        sed = gems[ed];

        if(state==1){
            lists[sed]++;
            if( lists[sed]==1 ) check++;
        }else if(state==2){
            lists[sst]--;
            if( lists[sst]==0 ) check--;
        }else if(state==3){
            lists[sed]++;
            if( lists[sed]==1 ) check++;
            lists[sst]--;
            if( lists[sst]==0 ) check--;
        }

        if(state==1){
            if(check < howMany){
                ed++;
            }else{
                answer = {st+1, ed+1};
                state = 2;
            }
        }else if(state==2){
            st++;
            if(check < howMany){
                ed++;
                state = 3;
            }
            else answer = {st+1, ed+1};
        }else if(state==3){
            st++;
            if(check >= howMany){
                answer = {st+1, ed+1};
                state = 2;
            }else ed++;
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
