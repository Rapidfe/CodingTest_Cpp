#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream readFile;             //���� ������ ���� ����

    readFile.open("C:/Users/LG/Desktop/ok.txt");    //���� ����

    if(readFile.is_open())    //������ ���ȴ��� Ȯ��

    {

        while(!readFile.eof())    //���� ������ �о����� Ȯ��

        {

            char arr[256];

            readFile.getline(arr, 256);    //���پ� �о����
            cout<<arr<<endl;
        }

    }

    readFile.close();
    return 0;
}
