#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int arraySize = board[0].size();
    vector<int> lineEnd;
    for(int i=0; i<arraySize; i++)
    {
        lineEnd.push_back(arraySize);
        for(int j=0; j<arraySize; j++)
        {
            if(board[j][i] != 0)
            {
                lineEnd[i] = j;
                break;
            }
        }
    }


    deque<int> result;
    int in;
    for(int i=0; i<moves.size(); i++)
    {
        if(lineEnd[moves[i]-1] == arraySize)
        {
            continue;
        }
        in = board[lineEnd[moves[i]-1]][moves[i]-1];
        if(result[0] == in)
        {
            result.pop_front();
            answer+=2;
        }
        else
        {
            result.push_front(in);
        }
        lineEnd[moves[i]-1]++;
    }
    return answer;
}

int main()
{
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                   {0, 0, 1, 0, 3},
                                   {0, 2, 5, 0, 1},
                                   {4, 2, 4, 4, 2},
                                   {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    int answer = solution(board, moves);
    cout<<"Answer: "<<answer;
    return 0;
}
