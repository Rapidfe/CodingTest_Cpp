#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    answer = triangle.back().front();
    int vSize = triangle.size();
    vector<int> extend;

    for(int i=vSize-2; i>=0; i--){
        for(int j=0; j<vSize-1; j++){
            int a = triangle[i+1][j];
            int b = triangle[i+1][j+1];
            if(a > b){
                triangle[i][j] += a;
            }else triangle[i][j] += b;
        }
    }
    answer = triangle.front().front();
    return answer;
}

int main(){
    vector<vector<int>> triangle = {{7},
                                   {3, 8},
                                  {8, 1, 0},
                                 {2, 7, 4, 4},
                                {4, 5, 2, 6, 5}};

    cout<<solution(triangle)<<endl;

	return 0;
}
