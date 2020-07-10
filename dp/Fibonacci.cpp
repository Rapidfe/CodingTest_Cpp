#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    vector<int> save = {1,1};
    for(int i=2; i<N; i++){
        save.push_back(save[i-2]+save[i-1]);
    }

    if(N==1) answer = 4;
    else answer = 2*(save[save.size()-1]*2 + save[save.size()-2]);
    return answer;
}
int main(){
    int N = 6;
    cout<<solution(N);
    return 0;
}
