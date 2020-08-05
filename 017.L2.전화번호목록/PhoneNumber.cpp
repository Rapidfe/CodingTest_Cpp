#include <iostream>
#include <vector>
#include <algorithm>

//정렬하고 첫번째 번호가 같은것들 모두 비교
//생각해보니 정렬하고 바로 뒤에 꺼랑만 비교하면 됨
//case 3은 번호 1개짜리가 접두가 되는 경우였음
//근데 이건 해쉬 풀이가 아닌데

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    for(int i=0; i<phone_book.size(); i++){
        string::iterator end_pos = remove(phone_book[i].begin(), phone_book[i].end(), ' ');
        phone_book[i].erase(end_pos, phone_book[i].end());
    }
    sort(phone_book.begin(), phone_book.end());

    for(auto i=phone_book.begin(); i!=phone_book.end(); i++){
        auto next = i;
        next++;
        while( next != phone_book.end() && (*next)[0] == (*i)[0] ){
            for(int j=0; j<(*i).length(); j++){
                if((*i)[j] != (*next)[j]) break;
                if(j == (*i).length()-1) answer = false;
            }
            if(answer) next++;
            else break;
        }
        if(!answer) break;
    }

    return answer;
}

int main(){
    vector<string> phone_book = {"12", "88", "123", "567", "1235"};
    if(solution(phone_book)) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
	return 0;
}
