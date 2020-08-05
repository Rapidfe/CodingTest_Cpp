#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

//string ����?
//A < a < B < b   + ª�� < ���
//�ð� ������ ���� ���� Ƽ���� map find
//������ �ƴ����� ���߿� �� �� �����ϱ� skip�� �ؾ���
//�ٵ� map�� ���ϱ� skip�� Ƽ��/����� Ƽ�� ������ �����
//skip�� ��߰��� Ƽ�� ������ iter++�� ó���ߴµ� end()�� �Ǿ��� ��츦 ���� ���ؼ� ������
//�ٸ� �ڵ� ���ϱ� �׳� ó������ ������ �ܼ� for������ ���� Ƽ�� ã�� (skip�ʿ����)
//tickets ũ�Ⱑ ���� ��Ŀ�� ū ���� ���µ�
//��ʹ� ������ �´� ��츸 ��Ƴ��� �İ��� �ϰ�, �������� �����, �� �ܴ� �׳� ������ �ǰڴ�
//���� ��� ��쿡 return������� �ʿ� x

using namespace std;

bool cmp(const vector<string> a, vector<string> b){
    return a[1] < b[1];
}

vector<string> answer_1;
bool dfs(string nowName, multimap<string,string>::iterator pre, multimap<string,string> lists){
    multimap<string,string>::iterator now;
    multimap<string,string>::iterator next;
    multimap<string,string>::iterator del = lists.find(pre->first);
    while(del->second != pre->second) del++;
    lists.erase(del);
    now = lists.find(pre->second);
    if(lists.size() == 1){
        answer_1.push_back(now->second);
        return true;
    }
    while(now->first == nowName){
        next = lists.find(now->second);
        if(next == lists.end()) now++;
        else{
            if(dfs(now->second, now, lists)){
                answer_1.push_back(now->second);
                return true;
            }else now++;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    multimap<string,string> lists;

    sort(tickets.begin(), tickets.end(), cmp);

    for(int i=0; i<tickets.size(); i++){
        lists.insert(make_pair(tickets[i][0], tickets[i][1]));
    }

    multimap<string,string>::iterator start = lists.find("ICN");
    while(start->first == "ICN"){
        if( dfs(start->second, start, lists) ){
            answer.push_back(start->first);
            answer.push_back(start->second);
            break;
        }else start++;
    }
    for(int i=answer_1.size()-1; i>=0; i--){
        answer.push_back(answer_1[i]);
    }

    return answer;
}

int main(){
    vector<vector<string>> tickets = {{"ICN","C"},{"ICN","B"},{"C","ICN"},{"B","D"}};

    vector<string> answer = solution(tickets);

    //solution(tickets);
    for(string i : answer){
        cout<<i<<endl;
    }

	return 0;
}
