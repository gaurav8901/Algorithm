//Rod cutting using bottom-up approach

#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

//where rod of length i has a cost price[i-1]
int rod_cut(int price[], int n)
{
    //t[i] stores maxi. profit from rod of length i
    int t[n+1];

    //initialize maxi profit to 0
    for(int i =0; i<=n; i++)
        t[i] = 0;

    //consider rod of length i
    for(int i =1; i<=n; i++)
    {
        //divide rod of length i into two rods of length j and i-j each 
        //and take maxi.
        for(int j = 1; j<=i; j++)
            t[i] = max(t[i], price[j-1] + t[i-j]);      //main formula
    }

    //t[n] stores maxi profit acheived from rod of length n
    return t[n];
}

int main()
{
    // int length[] = {1,2,3,4,5,6,7,8};
    int price[] = {1,5,8,9,10,17,17,20};

    // rod length
    int n = 4;

    cout<<"Profit is " << rod_cut(price, n);

    getch();
}

