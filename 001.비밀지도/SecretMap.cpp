#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> num1(n*n), num2(n*n);

    int k = 0;

    for(int j=0; j<n; j++)
    {
        for(int i=n-1; i>=0; i--)
        {
            if(arr1[j] >= pow(2,i))
            {
                num1[k] = 1;
                arr1[j] -= pow(2,i);
            }
            else
            {
                //cout<<pow(2,i)<<endl;
                num1[k] = 0;
            }

            if(arr2[j] >= pow(2,i))
            {
                //cout<<arr2[j]<<endl;
                num2[k] = 1;
                arr2[j] -= pow(2,i);
            }
            else
            {
                num2[k] = 0;
            }
            k++;
        }
        answer.push_back("");
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(num1[n*i+j]+num2[n*i+j] > 0)
            {
                answer[i].append("#");
            }
            else
            {
                answer[i].append(" ");
            }
        }
    }

    return answer;
}

int main()
{
    //cout<<"n: "<<endl;
    int n = 5;
    vector<int> arr1 = {9,20,28,18,11};
    vector<int> arr2 = {30,1,21,17,28};
    vector<string> answer(5);
    answer = solution(n, arr1, arr2);

    cout<<"Answer is:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<answer[i]<<endl;
    }
    return 0;
}
