// C++ Program to solve Sudoku problem
#include <iostream>
#include <vector>
using namespace std;

bool isSafe( vector<vector<int>>&mat,int row, int col ,int num)
{
  for(int i=0;i<9;i++)
    if(mat[row][i]==num)
      return false;

    for(int i=0;i<9;i++)
    if(mat[i][col]==num)
      return false;

    int startRow=row-(row%3);
    int startCol=col-(col%3);
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
        if(mat[i+startRow][j+startCol]==num)
          return false;
    }

return true;
}

bool solveSudokuRec(vector<vector<int>>&mat,int row ,int col)
{
  if(row==8&&col==9)
    return true;
  if(col==9)
  {
    row++;
    col=0;
  }
  if(mat[row][col]!=0)
    return solveSudokuRec(mat,row,col+1);
  for(int i=1;i<10;i++)
  {
    if(isSafe(mat,row,col,i))
    {
      mat[row][col]=i;
      if(solveSudokuRec(mat,row,col+1))
        return true;
       mat[row][col]=0;
    }
  }
  return false;
}



void solveSudoku(vector<vector<int>> &mat) {
    solveSudokuRec(mat, 0, 0);
}

int main() {
    vector<vector<int>> mat = {
        {9, 0, 0, 1, 0, 2, 0, 0, 0}, 
        {0, 2, 0, 8, 5, 0, 0, 0, 0}, 
        {7, 5, 0, 0, 0, 0, 3, 8, 0},
        {0, 0, 0, 0, 4, 0, 1, 0, 0}, 
        {2, 0, 8, 0, 0, 0, 0, 9, 3}, 
        {0, 0, 0, 2, 8, 6, 0, 0, 7},
        {0, 0, 0, 0, 9, 8, 0, 0, 4}, 
        {0, 6, 7, 0, 0, 0, 0, 5, 0}, 
        {1, 0, 4, 5, 0, 0, 0, 3, 0}};

  solveSudoku(mat);
    
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}