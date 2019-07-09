#include <iostream>

using namespace std;

void printpath(int ** solution, int n)
{
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++)
                cout <<solution[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        cout << endl;
}

void mazehelper (int maze[][3], int ** solution, int n, int x, int y)
{
    if (x==2 && y == 2)
    {
        solution[x][y] = 1;
        printpath(solution, n);
        solution[x][y] = 0;
        return;
    }
    if(x < 0 || y < 0 || x >=n || y >=n || solution[x][y]==1 || maze[x][y] ==0)
        return;
    solution[x][y]=1;
    mazehelper(maze, solution, n, x-1, y);
    mazehelper(maze, solution, n, x+1, y);
    mazehelper(maze, solution, n, x, y-1);
    mazehelper(maze, solution, n, x, y+1);
    solution[x][y]=0;
}

void mazerunner(int maze[3][3], int n)
{
    int **solution, i , j;
    solution = new int * [n];
    for (i=0; i<n ; i++)
        solution[i]= new int[n];
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        solution[i][j] = 0;
    mazehelper(maze, solution, n, 0, 0);
}
int main()
{
    int maze[3][3]={{1,1,0},{1,1,1},{1,1,1}};

    mazerunner(maze, 3);
    cout << "Hello world!" << endl;
    return 0;
}
