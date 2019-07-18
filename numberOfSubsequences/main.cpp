#include <iostream>

using namespace std;

int countNoOfSubsequences(string s)
{
    //collect the count of strings with a
    int aCount = 0;

    //collect the count of strings with b
    int bCount = 0;

    //collect the count of strings with c
    int cCount = 0;

    for (int i =0; i < s.size(); i++)
    {
        if (s[i]== 'a')
        {
            aCount = 1 + 2*aCount;
        }

        if (s[i]== 'b')
        {
            bCount = aCount + 2*bCount;
        }

        if (s[i]== 'c')
        {
            cCount = bCount + 2*cCount;
        }
    }

    return cCount;
}

int main()
{
    string str = "aabbcc";
    cout << "Number of subsequences of the form a^i b^j c^k" << endl;
    cout << "==============================================" << endl;
    cout << "The string is :" << str << endl;
    cout << "count of no. of subsequences: " << countNoOfSubsequences(str) << endl;
    return 0;
}
