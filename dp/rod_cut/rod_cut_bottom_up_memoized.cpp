/**
*   Finds the maximum profit that can be gained by cutting the rod of length n
*   
*   uses:   incremental approach, does not explores all possible combination of
*           cutting a rod. Identifies the solution for smallest subproblems and 
*           builds the solution for bigger subproblems in an incremental 
*           fashion all the way upto the real problem.
*   input:  price of rod p_i of length i, for all i <= n;
*   ouptut: maximum gain for all lengths l_i
*   
*   author: Tariq
*   date:   28/08/2016
*/

#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;

int cut_rod(int* r, int *p, int n) {
    if (n == 0)
        return 0;
    int q = INT_MIN;
    for (int i = 1; i <= n; i++)
        q = max(q, p[i] + r[n - i]);
    r[n] = q; 
    return q;
}

int main() {
    int n;
    cin>>n;
    int p[n + 1];
    int r[n + 1];
    
    
    for (int i = 1; i <= n; ++i)
        r[i] = 0;

    for (int i = 1; i <= n; ++i)
            cin>>p[i];
    
    for (int i = 1; i <= n; ++i)
        cout<<i<<"\t"<<cut_rod(r, p, i)<<endl;

    return 0;
}

