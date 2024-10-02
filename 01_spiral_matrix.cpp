// Given an n x m matrix 'a', return all elements of the matrix in spiral order.
#include<iostream>
#include<vector>
using namespace std;

void spiralMatrix(vector<vector<int>>&vec)
{
    int top = 0;
    int bottom = vec.size()-1;
    int left = 0;
    int right = vec[0].size()-1;
    int direction = 0;

    while(left <= right && top <= bottom)
    {
        // Left -> Right
        if(direction == 0)
        {
            for(int col=left; col<=right;col++)
            {
                cout<<vec[top][col]<<" ";
            }
            top++;
        }
        // top -> bottom
        else if(direction == 1)
        {
            for(int row = top; row<=bottom; row++)
            {
                cout<<vec[row][right]<<" ";
            }
            right--;
        }
        // right -> left
        else if(direction == 2)
        {
            for(int col = right; col>=left; col--)
            {
                cout<<vec[bottom][col]<<" ";
            }
            bottom--;
        }
        // bottom -> top
        else
        {
            for(int row = bottom; row >= top; row--)
            {
                cout<<vec[row][left]<<" ";
            }
            left++;
        }
        direction = (direction+1)%4;

    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    spiralMatrix(matrix);
}