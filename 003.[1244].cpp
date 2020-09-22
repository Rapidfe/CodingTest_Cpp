#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int a, const int b){
    return a>b;
}

int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
        string num;
        int change;
        cin>>num>>change;
        vector<int> digits;
        vector<int> res;
        int len = num.length();
        int isSame = 0;
        int tmpSame = -1;
        for(int i=0; i<len; i++){
            digits.push_back(num[i]-'0');
            res.push_back(num[i]-'0');
        }
        sort(digits.begin(), digits.end(), cmp);
        int tmp;
        for(int i=0; i<len && change>0; i++){
            if( isSame == 0 && tmpSame != -1 && tmpSame == digits[i] ) isSame = 1;
            tmpSame = digits[i];
            if( res[i] != digits[i] ){
                vector<int>::reverse_iterator iter = find(res.rbegin(), res.rend(), digits[i]);
                tmp = *iter;
                *iter = res[i];
                res[i] = tmp;
                change--;
            }
        }
        if( change > 0 && !isSame && change%2 == 1 ){
            tmp = res[len-2];
            res[len-2] = res[len-1];
            res[len-1] = tmp;
        }
        cout<<"#"<<test_case<<" ";
        for(int i=0; i<len; i++) cout<<res[i];
        cout<<endl;
	}
	return 0;
}
