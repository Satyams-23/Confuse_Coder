// Input:

// The first line contains an integer, n, denoting the maximum possible value in the arrays.
// The next line contains an integer, k, denoting the length of the arrays.
// Input	Output	Output Description
// 2
// 1	2	The required length is 1, so there are only two possible arrays: [1] and [2].

// //Your birthday is coming soon and one of your friends, Alex, is thinking about a gift for you. He knows that you really like integer arrays with interesting properties.

// He selected two numbers, N and K and decided to write down on paper all integer arrays of length K (in form a[1], a[2], …, a[K]), where every number a[i] is in range from 1 to N, and, moreover, a[i+1] is divisible by a[i] (where 1 < i <= K), and give you this paper as a birthday present.

// Alex is very patient, so he managed to do this. Now you’re wondering, how many different arrays are written down on this paper?

// Since the answer can be really large, print it modulo 10000

// Input

// The first line contains an integer, N, denoting the maximum possible value in the arrays.
// All possible arrays are [1, 1], [1, 2], [1, 3], [2, 2], [3, 3].

#include <iostream>
using namespace std;

const int MOD = 10000;

int countArray(int n, int k)
{
    int dp[n + 1][k + 1];
    for (int i = 1; i <= n; ++i)
    {
        dp[i][1] = 1; // Only one element in the array
    }

    for (int i = 1; i <= n; ++i) // Number of elements in the array (1 to n)
    {
        for (int j = 2; j <= k; ++j) // Length of the array (2 to k)
        {
            dp[i][j] = 0;
            for (int x = 1; x <= i; ++x)
            {
                dp[i][j] += dp[x][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i)
    {
        result += dp[i][k];
        result %= MOD;
    }

    return result;
}

int main()
{
    int n, k;
    cout << "Enter the maximum possible value in the arrays: ";
    cin >> n;
    cout << "Enter the length of the arrays: ";
    cin >> k;

    cout << countArray(n, k);

    return 0;
}