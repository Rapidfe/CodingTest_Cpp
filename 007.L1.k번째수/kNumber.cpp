#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        vector<int> sorting;
        int arrSize = commands[i][1]-commands[i][0]+1;
        int k=commands[i][0]-1;
        for(int j=0; j<arrSize; j++){
            sorting.push_back(array[k++]);
        }
        sort(sorting.begin(), sorting.end());
        answer.push_back(sorting[commands[i][2]-1]);
    }

    return answer;
}

int main(){
    vector<int> array = {1,5,2,6,3,7,4};
    vector<vector<int>> commands {{2,5,3}, {4,4,1}, {1,7,3}};
    vector<int>answer = solution(array, commands);

    cout<<"[";
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i];
        if(i != answer.size()-1)
            cout<<", ";
    }
    cout<<"]";

    return 0;
}
