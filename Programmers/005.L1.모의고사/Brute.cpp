#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> types = {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    vector<int> threeRes(3);
    for(int i=0; i<answers.size(); i++){
        for(int j=0; j<types.size(); j++){
            if(answers[i] == types[j][i%types[j].size()]){
                threeRes[j]++;
            }
        }
    }
    for(int i=0; i<threeRes.size(); i++){
        if(threeRes[i] == *max_element(threeRes.begin(), threeRes.end())){
            answer.push_back(i+1);
        }
    }
    return answer;
}

int main(){
    vector<int> answers = {1,3,2,4,2};
    vector<int> answer = solution(answers);

    cout<<"[";
    for(int i : answer){
        cout<<i;
        if(i != answer[answer.size()-1]) cout<<",";
    }
    cout<<"]";
    return 0;
}
