#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

//stringÀÇ Á¤·Ä?

using namespace std;

bool cmp(const vector<string> a, vector<string> b){
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    multimap<string,string> lists;
    multimap<string,string>::iterator iter;
    multimap<string,string>::iterator tmp;

    sort(tickets.begin(), tickets.end(), cmp);

    for(int i=0; i<tickets.size(); i++){
        lists.insert(make_pair(tickets[i][0], tickets[i][1]));
    }

    iter = lists.find("ICN");
    answer.push_back(iter->first);
    while(lists.size() != 0){
        while(lists.find(iter->second) == lists.end() && lists.size()>1) iter++;
        tmp = iter;
        iter = lists.find(iter->second);
        answer.push_back(tmp->second);
        lists.erase(tmp);
    }

    return answer;
}

int main(){
    vector<vector<string>> tickets = {{"ICN", "BOO"}, {"BOO", "ICN"}, {"BOO", "ICN"}};

    vector<string> answer = solution(tickets);

    for(string i : answer){
        cout<<i<<endl;
    }

	return 0;
}
