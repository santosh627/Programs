#include <iostream>

using namespace std;

void print(int **chessboard, int n)
{
    for (int i =0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            cout << chessboard[i][j] << " ";
        }
        cout << endl;
    }
    cout << "====================" <<endl;
}
int is_safe(int **chessboard, int n, int x, int y)
{
    int i, j;
    for (i =0; i<n; i++)
    {
        if((chessboard[x][i]==1)|| (chessboard[i][y]==1))
            return 0;
    }
    for (i =0; i<n; i++)
    {
        for (j =0; j<n; j++)
        {
            if(((i-j)==(x-y)) || ((i+j)==(x+y)))
                if(chessboard[i][j]==1)
                    return 0;
        }
    }

    return 1;
}

void queenhelper(int **chessboard,int queen_left, int n)
{
    if(queen_left == 0)
    {
        print(chessboard, n);
    }
    else{
/*        for (int i=0; i<n ; i++)
        {
            for (int j=0; j<n; j++)
            {
                if(is_safe(chessboard, n, i, j) && chessboard[i][j] != 1 )
                {
                    chessboard[i][j]=1;
                    cout << "queenhelper called for :" <<i << " "<< j<<" queen left :"<< queen_left<< endl;
                    queenhelper(chessboard,queen_left-1 , n);
                    chessboard[i][j]=0;
                }
            }
        }*/
            for (int j=0; j<n; j++)
            {
                if(is_safe(chessboard, n, queen_left-1, j) && chessboard[queen_left-1][j] != 1 )
                {
                    chessboard[queen_left-1][j]=1;
                    queenhelper(chessboard,queen_left-1 , n);
                    chessboard[queen_left-1][j]=0;
                }
            }
    }
}
void nqueen(int n)
{
    int i, j;
    int **chessboard;

    chessboard = new int * [n];
    for (i=0; i< n; i++)
        chessboard[i] = new int[n];

    for (i=0; i<n ; i++)
        for (j=0; j<n ; j++)
            chessboard[i][j] =0;
    queenhelper(chessboard, n, n);
}

int main()
{
    int n;
    cout << "Please enter no. of queens: ";
    cin >> n;
    cout << endl;
    nqueen(n);
    return 0;
}
