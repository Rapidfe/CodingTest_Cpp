#include <iostream>
#include <vector>

//중학교식 최단경로 개수 구하기
//오른쪽, 아래쪽 이동만 고려
//원래는 왼쪽, 위쪽도 고려해야 할듯

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    int modulo = 1000000007;
    vector<vector<int>> arr(n);
    vector<int> water(m*n,0);
    for(auto i : puddles){
        water[ (i[1]-1)*m+i[0]-1 ] = 1;
    }
    arr[0].push_back(1);
    for(int i=1; i<n; i++){
        if(water[i*m]==1) arr[i].push_back(0);
        else arr[i].push_back(arr[i-1][0]);
    }
    for(int i=1; i<m; i++){
        if(water[i]==1) arr[0].push_back(0);
        else arr[0].push_back(arr[0][i-1]);
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(water[j*m+i] == 1) arr[j].push_back(0);
            else arr[j].push_back( (arr[j-1][i]+arr[j][i-1])%modulo );
        }
    }
    answer = *((*(arr.end()-1)).end()-1);
    return answer;
}

int main(){
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {{2,2}};

    cout<<solution(m,n,puddles);
    return 0;
}
