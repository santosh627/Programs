#include <iostream>
#include <queue>

using namespace std;

struct queueEntry
{
    int vertex;
    int distance;
};

int getMinDiceThrows(int board[], int N)
{
    struct queueEntry q;
    int i, vertex;
    queue<queueEntry> qe;
    bool * visited = new bool[N];

    for (i =0; i<N; i++)
        visited[i] = false;
    q = {0,0};
    qe.push(q);

    while (!qe.empty())
    {
        q = qe.front();

        if(q.vertex == (N-1))
            break;

        vertex= q.vertex;
        qe.pop();

        for (i= vertex+1; i <= vertex+6; i++)
        {
            if (visited[i]==false)
            {
                struct queueEntry a;
                if ( board[i]==-1)
                    a.vertex = i;
                else
                    a.vertex = board[i];

                a.distance = q.distance +1;
                visited[i] = true;
                qe.push(a);
            }
        }
    }
    return q.distance;
}

int main()
{
    // Let us construct the board given in above diagram
    int N = 30;
    int board[N];
    for (int i = 0; i<N; i++)
        board[i] = -1;

    // Ladders
    board[2] = 21;
    board[4] = 7;
    board[10] = 25;
    board[19] = 28;

    // Snakes
    board[26] = 0;
    board[20] = 8;
    board[16] = 3;
    board[18] = 6;

    cout << "Min Dice throws required is " << getMinDiceThrows(board, N);
    return 0;
}
