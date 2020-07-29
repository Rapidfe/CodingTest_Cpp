#include <iostream>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> days2016 = {31,29,31,30,31,30,31,31,30,31,30,31};
    vector<string> weeks = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    int days = 0;
    for(int i=0; i<a-1; i++){
        days+=days2016[i];
    }
    days += b;
    answer = weeks[(days-1)%7];

    return answer;
}

int main(){
    int a=5;
    int b=24;
    cout<<solution(a,b);
    return 0;
}
