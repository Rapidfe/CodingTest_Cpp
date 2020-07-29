#include <iostream>
#include <string>
#include <vector>

//vector find -> find(v1.begin(), v1.end(), ??)
//vector erase -> v1.erase(iterator) / v1.erase(start, end)
//시간초과??
//cmp함수를 고치니까 됨
//자주 안쓰이는 연산은 따로 빼자


using namespace std;

int cmp(string a, string b){
    int cnt=0;
    for(int i=0; i<a.length(); i++){
        if(a.substr(i,1) != b.substr(i,1)) cnt++;
        if(cnt>1) return 1;
    }
    if(cnt == 1) return 2;
}

string target_save;
int finding(string a, vector<string> words, int cnt, int res){
    int cmpi;
    string tmp1;
    int tmp2;
    if(res != 0 && cnt >= res) return 0;
    if(a.compare(target_save) == 0) return cnt;
    auto iter = words.begin();
    while(iter != words.end()){
        cmpi = cmp(a,*iter);
        if(cmpi == 1){
            iter++;
        }else if(cmpi == 2){
            tmp1 = *iter;
            words.erase(iter);
            tmp2 = finding(tmp1,words,cnt+1,res);
            if( tmp2!=0 ){
                res=tmp2;
            }
        }
    }
    return res;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    int cmpi = 0;
    for(string i : words){
        int tmp = target.compare(i);
        if( tmp == 0 ) cmpi = 0;
    }
    if( cmpi!=0 ) return 0;

    target_save = target;
    answer = finding(begin, words, 0, 0);

    return answer;
}

int main(){
    string begin = "hdsa";
    string target = "wera";
    vector<string> words = {"wera","wyra","hyra","hysa","hqsa","sdah","qdsa","tgsa","gdsa","hdas","hdfa","hdsg","gdsh"};
    cout<<solution(begin, target, words);
    return 0;
}
