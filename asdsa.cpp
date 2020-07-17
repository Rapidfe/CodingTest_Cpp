#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream readFile;             //읽을 목적의 파일 선언

    readFile.open("C:/Users/LG/Desktop/ok.txt");    //파일 열기

    if(readFile.is_open())    //파일이 열렸는지 확인

    {

        while(!readFile.eof())    //파일 끝까지 읽었는지 확인

        {

            char arr[256];

            readFile.getline(arr, 256);    //한줄씩 읽어오기
            cout<<arr<<endl;
        }

    }

    readFile.close();
    return 0;
}
