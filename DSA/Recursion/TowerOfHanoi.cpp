//  Tower of hanoi

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void towerofhanoi(int n, char source, char aux, char dest)
{
    if (n == 0)
    {
        return;
    }

    towerofhanoi(n - 1, source, dest, aux); // move n-1 disks from source to aux
    cout << "Move disk " << n << " from " << source << " to " << dest << endl;
    towerofhanoi(n - 1, aux, source, dest); // move n-1 disks from aux to dest
}

int main()
{
    int n = 4;
    char A = 'A', B = 'B', C = 'C';
    towerofhanoi(n, A, B, C);
    return 0;
}