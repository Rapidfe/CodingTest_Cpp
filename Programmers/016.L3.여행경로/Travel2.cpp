#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

//string 정렬?
//A < a < B < b   + 짧다 < 길다
//시간 단축을 위해 다음 티켓을 map find
//지금은 아니지만 나중에 쓸 수 있으니까 skip도 해야함
//근데 map을 쓰니까 skip한 티켓/사용한 티켓 구분이 힘들다
//skip은 출발공항 티켓 내에서 iter++로 처리했는데 end()가 되었을 경우를 생각 안해서 에러남
//다른 코드 보니까 그냥 처음부터 끝까지 단순 for문으로 다음 티켓 찾음 (skip필요없음)
//tickets 크기가 별로 안커서 큰 차이 없는듯
//재귀는 조건이 맞는 경우만 잡아내서 파고들게 하고, 종료조건 만들고, 그 외는 그냥 보내면 되겠다
//굳이 모든 경우에 return만들어줄 필요 x

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
