#include <bits/stdc++.h>
using namespace std;



    bool check(vector<vector<int>> &ans, int row, int col, int num)
    {

        for (int i = 0; i < 9; i++)
        {
            if (ans[row][i] == num)
                return 0;
            if (ans[i][col] == num)
                return 0;
        }

        int R = row / 3;
        int C = col / 3;
        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; j++)
            {
                if (ans[3 * R + i][3 * C + j] == num)
                    return 0;
            }
        }

        return 1;
    }

    bool recur(vector<vector<int>> &ans, int index)
    {

        if (index >= 9)
        {

            return 1;
        }

        for (int i = 0; i < 9; i++)
        {

            if (ans[index][i] == 0)
            {

                for (int j = 1; j <= 9; j++)
                {

                    if (check(ans, index, i, j) == 1)
                    {
                        ans[index][i] = j;
                        if (recur(ans, index) == 1)
                        {
                            return 1;
                        }
                        else
                        {
                            ans[index][i] = 0;
                        }
                    }
                }

                return 0;
            }
        }

        if (recur(ans, index + 1) == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void solveSudoku(vector<vector<char>> &board)
    {

        vector<vector<int>> ans;

        for (int i = 0; i < 9; i++)
        {

            vector<int> temp;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    temp.push_back(board[i][j] - '0');
                }
                else
                {
                    temp.push_back(0);
                }
            }

            ans.push_back(temp);
        }

        int possible;
        possible = recur(ans, 0);

        for (int i = 0; i < 9; i++)
        {

            vector<char> temp;
            for (int j = 0; j < 9; j++)
            {
                if (ans[i][j] != 0)
                {
                    temp.push_back(char(int('0') + ans[i][j]));
                }
                else
                {
                    temp.push_back('.');
                }
            }

            board[i] = temp;
        }
    }


int main()
{
//char are inputs.
//give '.' as input in placve of vacant places
//please enter valid input
//i.e character ranging from '1' to '9' including '.';
//atleast 17 elements are required to generate unique solution
//less than 17 elements leads to multiple solutions
//in such case, the code is intended to give any one of the valid solution.
vector<vector<char>> board;

for(int i=0;i<9;i++)
{
vector<char> temp;

for(int j=0;j<9;j++)
{

char x;
cin>>x;
temp.push_back(x);


}
board.push_back(temp);

}


solveSudoku(board);

for(int i=0;i<9;i++)
{

for(int j=0;j<9;j++)
{

    cout<<board[i][j]<<" ";
}

cout<<endl;

}



}