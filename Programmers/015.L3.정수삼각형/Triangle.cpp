#include <iostream>
#include <vector>

using namespace std;

int nextAnswer(int answer, vector<int> extend){
    int a = answer + extend.back();
    int b=0;
    for(int i : extend){
        b += i;
    }
    if(a<b) return b;
    else return a;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;


    answer = triangle.back().front();
    int vSize = triangle.size();
    vector<int> extend;

    for(int i=1; i<vSize; i++){
        int k = i;
        for(int j=vSize-1; j>=vSize-i-1; j--){
            cout<<"new "<<triangle[j][k]<<endl;
            extend.push_back(triangle[j][k]);
            k--;
        }
        cout<<answer<<endl;
        answer = nextAnswer(answer, extend);
        extend.clear();
    }
    return answer;
}

int main(){
    vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};

    cout<<solution(triangle)<<endl;

	return 0;
}
