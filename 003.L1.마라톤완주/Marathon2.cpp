#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //map<string, int>
    multiset<string> comp;
    for(string i : completion)
    {
        comp.insert(i);
    }
    for(string i : participant)
    {
        if(comp.find(i) == comp.end())
        {
            answer = i;
        }
        else
        {
            comp.erase(comp.find(i));
        }
    }
    return answer;
}

int main()
{
    vector<string> participant = {"marina", "josipa", "nikola", "marina", "filipa"};
    vector<string> completion = {"josipa", "filipa", "marina", "marina"};

    cout<<solution(participant, completion);
    return 0;
}
