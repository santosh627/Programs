#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//-----Method 1------------
int countSetBitsUtil (int n)
{
    if (n == 0)
        return 0;
    return ((n%2 == 0 ? 0 : 1) + countSetBitsUtil(n/2));
}
int countSetBits (int n)
{
    int i, sum = 0;
    for (i=n; i>0; i--)
        sum += countSetBitsUtil (i);
    return sum;
}
//----------Method 1 ends here----------


//-------Method 2------------------------
int flipmethod (int n)
{
    int change = 0, i = 0, j = 0, sum = 0;
    int k = 0;

    while ((1 << i) <= n)
    {
        change = 1 << i;
        k = 0;
        for(j=0; j<=n; j++)
        {
            sum += k;

            if (change == 1)
            {
                k = !k;
                change = 1 << i;
            }
            else
                change --;
        }
        i++;
    }
    return sum;
}
//-------Method 2 Ends Here--------------


//-------Method 3 starts here-------------

int getRightmostSetBit(int m)
{
    int count = 0, temp = 1, i = 0;
    while ((temp << i) <= m)
    {
        count ++;
        i++;
    }
    //printf("\n abe count ki value hai = %d", (count-1));
    return (count-1);
}

int _countTotalSetBits(int n, int m)
{
    int a;
    if (n == 0)
        return 0;
    //printf("\n yaha aaya hai");
    if (n == ((1<<(m+1))-1))
    {
       // a= ((1<<(m+1)-1));
        //printf("\n shhh n=%d rrrr=%d m=%d",n,a, m);
        return ((m+1) * (1<<(m)));
    }
        fflush(stdout);

    n = n - (1<<(m));
    return ((n+1) + countTotalSetBits(n) + (m*(1<<(m-1))));

}

int countTotalSetBits(int n)
{
    int m = 0;
    m = getRightmostSetBit(n);
    return _countTotalSetBits(n, m);

}

//-------Method 3 Ends here---------------
int main()
{
    int n = 19;
//  Enable below line for Method 1
//  printf("\n Total no. of set bit upto %d is %d.",n,countSetBits(n));

//  Below is the flip method: Method 2
 //   printf("\n Total no. of set bit upto %d is %d.",n,flipmethod(n));

 // Below is the 3rd Method to count no. of bits
    printf("\n Total no. of set bit upto %d is %d.",n,countTotalSetBits(n));
    return 0;
}
