#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//priority_queue�� ����ü�� �ְ� ���� ���ϴ� ���
//���� �Լ��� struct cmp �ȿ� operator�� �������̵�
//����� ã�� ��Ģ���� Ȯ���� ����
//�׳� �ҿ�ð� ���� �����ź��� ������ ��
//�ʱⰪ�� ���������� �� �����ؼ� ���� �ȳ���
//�Է��� 1���� ���� ��� (�ʱⰪ=��������)

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

    sort(jobs.begin(), jobs.end(), cmp2);
    auto iter = jobs.begin();
    requestTime = (*iter)[0];
    endTime = (*iter)[0];

    while(iter!=jobs.end() || !q.empty()){
        while( (requestTime <= endTime) && iter!=jobs.end() || iter == jobs.begin()){
            q.push(*iter);
            iter++;
            if(iter == jobs.end()) break;
            requestTime = (*iter)[0];
        }
        if(!q.empty()){
            answer += q.top()[1] + endTime - q.top()[0];
            endTime += q.top()[1];
            q.pop();
        }else{
            endTime = (*iter)[0];
        }
    }
    answer /= jobs.size();

    return answer;
}

int main(){
    vector<vector<int>> jobs = {{0,9},{0,4},{0,5},{0,7},{0,3}};

    //solution(jobs);
    cout<<solution(jobs)<<endl;

    return 0;
}
