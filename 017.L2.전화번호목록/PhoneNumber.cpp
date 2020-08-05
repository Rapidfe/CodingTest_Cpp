#include <iostream>
#include <vector>
#include <algorithm>

//�����ϰ� ù��° ��ȣ�� �����͵� ��� ��
//�����غ��� �����ϰ� �ٷ� �ڿ� ������ ���ϸ� ��
//case 3�� ��ȣ 1��¥���� ���ΰ� �Ǵ� ��쿴��
//�ٵ� �̰� �ؽ� Ǯ�̰� �ƴѵ�

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
