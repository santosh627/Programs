#include <iostream>

using namespace std;

void towerOfHanoi(int n, char from, char to, char aux)
{
    if(n == 1)
    {
        cout << "moving " << n <<" from " << from <<" to " << to << endl;
        return;
    }

    towerOfHanoi(n-1, from, aux, to);
    cout << "moving " << n <<" from " << from <<" to " << to << endl;
    towerOfHanoi(n-1, aux, to, from);
}

int main()
{
    int n;
    char from = 'a';
    char to = 'c';
    char aux ='b';

    cout << "please input no. of plates: " << endl;
    cin >> n;
    towerOfHanoi(n, from, to, aux);
    return 0;
}
