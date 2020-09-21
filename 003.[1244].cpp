#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
        for(int i=0; i<num.length(); i++){
            digits.push_back(num[i]-'0');
        }
        sort(digits.begin(), digits.end(), cmp);


	}

	return 0;
}
