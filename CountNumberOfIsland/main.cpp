#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// M x N matrix
#define M 10
#define N 10

int row [] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col [] = {-1, 0, 1, -1, 1, -1, 0, 1};

int is_safe(int mat[M][N], bool processed[M][N], int x, int y)
{
    return ((x>=0) && (x<M) && (y>=0) && (y< N) && (mat[x][y]) && !processed[x][y] );
}

void traverse(int mat[M][N], bool processed[M][N], int x ,int y)
{
    int i, j, k;
    queue<pair<int, int> > q;

    q.push(make_pair(x,y));

    while(!q.empty())
    {
        i = q.front().first;
        j = q.front().second;

        q.pop();

        for (k = 0; k< 8; k++)
        {
            if (is_safe(mat, processed, i+ row[k], j+col[k]))
                {
                    q.push(make_pair(i+ row[k], j+col[k]));
                    processed[i+ row[k]][j+col[k]] = true;
                }
        }
    }
}

int main()
{
    int count =0;
	int mat[M][N]=
	{
		{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
		{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
	};

	// stores if cell is processed or not
	bool processed[M][N];

	memset(processed, 0, sizeof(processed));

	for (int i = 0; i< M ; i++)
    {
        for (int j =0; j< N; j++)
        {
            if (mat[i][j] && !processed[i][j])
            {
                traverse(mat, processed, i ,j);
                count++;
            }
        }
    }
    cout << "Mo. of islands are: " << count << endl;
    return 0;
}
