#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

//stringstream
//선언,초기화,선언+초기화

using namespace std;

vector<float> toFloat(string st){
    int a[2];
    vector<float> af[2];
    stringstream ss(st.substr(11,2));
    ss>>a[0];
    ss.str(st.substr(14,2));
    ss>>a[1];
    af.push_back(0);
    af.push_back(stof(st.substr(17,6)));
    int j=1;
    while(st.substr(24+j,1) != "s") j++;
    af[0] = stof(st.substr(24,j));
    af[1] = af[1]+a[1]*60+a[0]*3600;
    af[0] = af[1]-af[0];

    return af;
}

int solution(vector<string> lines) {
    int answer = 0;

    vector<float> times;

    multimap<float,int> timeSt, timeEd;
    map<int,int> res;

    for(int i=0; i<lines.size(); i++){
        times = toFloat(lines[i]);
        //cout<<times[0];
        timeSt.insert(make_pair(times[0],i));
        timeEd.insert(make_pair(times[1],i));
    }

    int sectionSt = timeSt.begin()->first;
    int sectionEd = sectionSt+1;

    while(sectionSt > (--timeEd.end())->first){
        for(auto i=timeSt.begin(); i!=timeSt.end();){
            if(i->first <= sectionEd){
                res.insert(make_pair(i->second,1));
                timeSt.erase(i);
            }else break;
        }
        for(auto i=timeEd.begin(); i!=timeEd.end();){
            if(i->first <= sectionSt){
                res.erase(i->second);
                timeEd.erase(i);
            }else break;
        }
        if(res.size()>answer) answer=res.size();
        sectionSt++;
        sectionEd++;
    }

    return answer;
}

int main(){
    vector<string> lines = {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};
    cout<<solution(lines)<<endl;
    return 0;
}
