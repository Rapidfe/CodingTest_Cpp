#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

//stringstream
//����,�ʱ�ȭ,����+�ʱ�ȭ
//�ѹ� ���� �ʱ�ȭ�Ϸ��� clear�ؾ���
//vector ������ �� ũ��� �Ұ�ȣ. vector<> v(2)
//cout�� ��� �ڸ��� ������������
//cout.precision()
//�ݺ������� map�� begin ����� �ڵ� ++ �ȵǳ�??

using namespace std;

vector<float> toFloat(string st){
    int a[2];
    vector<float> af(2);
    stringstream ss(st.substr(11,2));
    ss>>a[0];
    ss.clear();
    ss.str(st.substr(14,2));
    ss>>a[1];
    af[1] = stof(st.substr(17,6));
    int j=1;
    while(st.substr(24+j,1) != "s") j++;
    af[0] = stof(st.substr(24,j));
    af[1] = af[1]+a[1]*60+a[0]*3600;
    af[0] = af[1]-af[0]-0.999;

    return af;
}

int solution(vector<string> lines) {
    int answer = 0;

    vector<float> times;

    multimap<float,int> timeEvent;
    int res=0;

    for(int i=0; i<lines.size(); i++){
        times = toFloat(lines[i]);
        //cout<<times[0];
        timeEvent.insert(make_pair(times[0],0));
        timeEvent.insert(make_pair(times[1],1));
        //timeSt.insert(make_pair(times[0],i));
        //timeEd.insert(make_pair(times[1],i));
    }
    cout.precision(8);
    cout<<"timeEvent: "<<endl;
    for(auto i=timeEvent.begin(); i!=timeEvent.end(); i++){
        cout<<i->second<<": "<<i->first<<endl;
    }

    for(auto i=timeEvent.begin(); i!=timeEvent.end(); i++){
        if(i->second == 0) res++;
        if(answer < res) answer = res;
        if(i->second == 1) res--;
        if(answer < res) answer = res;
    }
    /*int sectionSt = timeSt.begin()->first;
    int sectionEd = sectionSt+1;
    int ending = (--timeEd.end())->first;*/



    return answer;
}

int main(){
    vector<string> lines = {"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"};
    cout<<solution(lines)<<endl;
    return 0;
}
