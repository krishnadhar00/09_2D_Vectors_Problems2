// Given a positive integer n, generate an n x n matrix filled with elements rom 1 to n^2 in spiral order. Printing the number in spiral order from 1 to n. 
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> spiralMatrix( int n)
{
    vector<vector<int>> vec(n,vector<int>(n));
    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = n-1;
    int direction = 0;
    int value = 1;

    while(left <= right && top <= bottom)
    {
        // Left -> Right
        if(direction == 0)
        {
            for(int col=left; col<=right;col++)
            {
                vec[top][col] = value++;
            }
            top++;
        }
        // top -> bottom
        else if(direction == 1)
        {
            for(int row = top; row<=bottom; row++)
            {
                vec[row][right] = value++;
            }
            right--;
        }
        // right -> left
        else if(direction == 2)
        {
            for(int col = right; col>=left; col--)
            {
                vec[bottom][col] = value++;
            }
            bottom--;
        }
        // bottom -> top
        else
        {
            for(int row = bottom; row >= top; row--)
            {
                vec[row][left] = value++;
            }
            left++;
        }
        direction = (direction+1)%4;
    }
    return vec;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n));

    matrix = spiralMatrix(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}