#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

//priority_queue에 구조체를 넣고 정렬 정하는 방법
//정렬 함수를 struct cmp 안에 operator로 오버라이드

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

bool cmp2(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue< vector<int>, vector< vector<int> >, cmp > q;
    int endTime = 0;
    int requestTime = 0;
    int isEnd = 0;
    vector<int> tmp;

    sort(jobs.begin(), jobs.end(), cmp2);
    answer = jobs[0][1];
    endTime = jobs[0][1];
    auto iter = jobs.begin()+1;
    requestTime = (*iter)[0];

    while(iter!=jobs.end() || !q.empty()){
        while( (requestTime <= endTime) && iter!=jobs.end() ){
            q.push({(*iter)[0], (*iter)[1]+endTime-(*iter)[0], endTime, (*iter)[1]});
            iter++;
            if(iter == jobs.end()) break;
            requestTime = (*iter)[0];
        }
        if(!q.empty()){
            while(q.top()[2] != endTime){
                tmp = q.top();
                tmp[1] += endTime-tmp[2];
                tmp[2] = endTime;
                q.pop();
                q.push(tmp);
            }
            answer += q.top()[1];
            endTime += q.top()[3];
            q.pop();
        }else if(iter != jobs.end()){
            endTime = (*iter)[0];
        }
    }
    answer /= jobs.size();

    return answer;
}

int main(){
    vector<vector<int>> jobs = {{0,3},{1,9},{2,6}};

    //solution(jobs);
    cout<<solution(jobs)<<endl;

    return 0;
}
