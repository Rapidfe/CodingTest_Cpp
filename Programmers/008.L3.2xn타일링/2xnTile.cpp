#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//�ߺ��� ������ ����
//factorial �ð��� ���� �ɸ���
//factorial modulo�� ��������
//Multipoint evaluation??
//�׳� �Ǻ���ġ

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
