#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int isEnd;
    for(string i : participant)
    {
        isEnd = 1;
        for(int j=0; j<completion.size(); j++)
        {
            if(i.compare(completion[j]) == 0)
            {
                completion[j] = "";
                isEnd = 0;
                break;
            }
        }
        if(isEnd)
        {
            answer = i;
        }
    }
    return answer;
}

int main()
{
    vector<string> participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
    vector<string> completion = {"josipa", "filipa", "marina", "nikola"};
    cout<<solution(participant, completion);
    return 0;
}
