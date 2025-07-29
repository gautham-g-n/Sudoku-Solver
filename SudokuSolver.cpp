#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool Sudoku(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(Possible(board,c,i,j))
                        {
                            board[i][j]=c;
                            if(Sudoku(board))
                                return true;
                            else
                                board[i][j]='.'; // backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool Possible(vector<vector<char>>& board, char c, int row, int col)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c) return false;
            if(board[i][col]==c) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
};

//for printing a given sudoku board
void printBoard(const vector<vector<char>>& board)
{
    for(int i=0;i<9;i++)
    {
        if(i!=0 && i%3==0) cout << "------+-------+------\n";
        for(int j=0;j<9;j++)
        {
            if(j!=0 && j%3==0) cout<<"| ";
            cout<<board[i][j]<<' ';
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> board=
    {{'5','3','.','.','7','.','.','.','.'},
     {'6','.','.','1','9','5','.','.','.'},
     {'.','9','8','.','.','.','.','6','.'},
     {'8','.','.','.','6','.','.','.','3'},
     {'4','.','.','8','.','3','.','.','1'},
     {'7','.','.','.','2','.','.','.','6'},
     {'.','6','.','.','.','.','2','8','.'},
     {'.','.','.','4','1','9','.','.','5'},
     {'.','.','.','.','8','.','.','7','9'}};

    Solution s1;
    cout << "Original Sudoku Board:"<<endl;
    printBoard(board);
   
    cout<<endl;
    if(s1.Sudoku(board))
    {
        cout<<"Solved Sudoku Board:"<<endl;
        printBoard(board);
    }
    else
    {
        cout<<"No solution exists."<<endl;
    }

    return 0;
}