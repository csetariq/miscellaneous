/**
*   Finds the maximum profit that can be gained by cutting the rod of length n
*   
*   uses:   recursive approach, explores all possible combination of cutting arod
*   input:  price of rod p_i of length i, for all i <= n;
*   ouptut: maximum gain for all lengths l_i
*   
*   author: Tariq
*   date:   26/08/2016
*/

#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

int cut_rod(int *p, int n) {
    if (n == 0)
        return 0;
    int q = INT_MIN;
    for (int i = 1; i <= n; i++)
        q = max(q, p[i] + cut_rod(p, n - i));
    
    return q;
}

int main() {
    int n;
    cin>>n;
    int p[n + 1];
    
    for (int i = 1; i <= n; ++i)
            cin>>p[i];
    
    for (int i = 1; i <= n; ++i)
        cout<<i<<"\t"<<cut_rod(p, i)<<endl;

    return 0;
}

