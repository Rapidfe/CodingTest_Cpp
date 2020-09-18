#include <iostream>
#include <string>
#include <vector>

using namespace std;

int convertToNum(string st){
    string hh = "";
    hh += st[0];
    hh += st[1];
    string mm = "";
    mm += st[3];
    mm += st[4];
    string ss = "";
    ss += st[6];
    ss += st[7];
    return stoi(hh)*3600 + stoi(mm)*60 + stoi(ss);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int ptime = convertToNum(play_time);
    int atime = convertToNum(adv_time);

    vector<int> timeline(ptime+1,0);

    for(int i=0; i<logs.size(); i++){
        int st = convertToNum( logs[i].substr(0,8) );
        int ed = convertToNum( logs[i].substr(9,8) );
        for(int j=st; j<=ed; j++){
            timeline[j]++;
        }
    }

    int total=0;
    for(int i=0; i<=atime; i++){
        total += timeline[i];
    }

    int max_total=total;
    int max_i=0;
    for(int i=0; i<=ptime-atime-1; i++){
        total -= timeline[i];
        total += timeline[i+atime+1];
        if( max_total < total ){
            max_total = total;
            max_i = i+1;
            if(max_i > 5450){
                cout<<timeline[i]<<" "<<timeline[i+atime]<<" "<<max_i<<endl;
            }
        }
    }

    cout<<max_i<<endl;
    int hhh = max_i/3600;
    max_i %= 3600;
    int mmm = max_i/60;
    max_i %= 60;
    string hh = to_string(hhh);
    string mm = to_string(mmm);
    string ss = to_string(max_i);
    if(hh.size()==1) hh = "0"+hh;
    if(mm.size()==1) mm = "0"+mm;
    if(ss.size()==1) ss = "0"+ss;

    answer = hh + ":" + mm +":" + ss;
    return answer;
}

int main(){
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};

    cout<<solution(play_time, adv_time, logs);
    return 0;
}
