#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//중복을 포함한 조합
//factorial 시간이 오래 걸린다
//factorial modulo의 빠른계산법
//Multipoint evaluation??
//그냥 피보나치

int solution(int n) {
    int answer = 0;
    n++;
    int mod = 1000000007;
    int tmp1=1, tmp2=1;
    for(int i=2; i<n; i++){
        if(i%2) tmp2 = (tmp1+tmp2)%mod;
        else tmp1 = (tmp1+tmp2)%mod;
    }
    if(n%2) answer = tmp1;
    else answer = tmp2;

    return answer;
}

int main(){
    cout<<solution(4);
    return 0;
}
