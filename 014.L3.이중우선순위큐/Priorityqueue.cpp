#include <iostream>
#include <vector>
#include <string>
#include <set>

//string[i] 왜 안되지? -> substr(): string / string[i]: char
//set값 참조는 iterator로
//vector의 삽입은 push_back()

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> q;
    for(string i : operations){
        if(i.substr(0,1) == "I"){
            q.insert( stoi(i.substr(2,i.size()-2)) );
        }else if(q.size() != 0){
            if(i.compare("D 1") == 0){
                auto a = q.end();
                a--;
                q.erase(a);
            }else{
                q.erase(q.begin());
            }
        }
    }
    if(q.size() == 0){
        answer = {0,0};
    }else{
        auto a = q.end();
        a--;
        answer.push_back(*a);
        a = q.begin();
        answer.push_back(*a);
    }

    return answer;
}

int main(){
    vector<string> operations = {"I 1","I 5","I 3","D 1"};
    vector<int> answer = solution(operations);
    cout<<"[";
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i];
        if(i != answer.size()-1)
            cout<<", ";
    }
    cout<<"]";

	return 0;
}
