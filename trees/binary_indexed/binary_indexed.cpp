#include <iostream>

using namespace std;

long long sum(int *BIT, int n, int index) {
    long long ans = 0;
    index++;
    while (index > 0) {
        ans += BIT[index];
        index = index & (index - 1);
    }
    return ans;
}

void update(int *BIT, int n, int index, int by) {
    index++;
    while (index <= n) {
        BIT[index] += by;
        index += index & -index;
    }
}

int * constructBIT(int *arr, int n) {
    int *BIT = new int[n + 1];

    for (int i = 1; i <= n; ++i)
        BIT[i] = 0;

    for (int i = 0; i < n; ++i)
        update(BIT, n, i, arr[i]);

    return BIT;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(nums) / sizeof(int);

    int *BIT = constructBIT(nums, n);

    cout<<"0 "<<sum(BIT, n, 0)<<endl;
    cout<<"1 "<<sum(BIT, n, 1)<<endl;
    cout<<"2 "<<sum(BIT, n, 2)<<endl;
    cout<<"3 "<<sum(BIT, n, 3)<<endl;
    cout<<"4 "<<sum(BIT, n, 4)<<endl;
    cout<<"5 "<<sum(BIT, n, 5)<<endl;
    cout<<"6 "<<sum(BIT, n, 6)<<endl;
    cout<<"7 "<<sum(BIT, n, 7)<<endl;
    cout<<"8 "<<sum(BIT, n, 8)<<endl;
    cout<<"9 "<<sum(BIT, n, 9)<<endl;

    update(BIT, n, 5, 2);

    cout<<"0 "<<sum(BIT, n, 0)<<endl;
    cout<<"1 "<<sum(BIT, n, 1)<<endl;
    cout<<"2 "<<sum(BIT, n, 2)<<endl;
    cout<<"3 "<<sum(BIT, n, 3)<<endl;
    cout<<"4 "<<sum(BIT, n, 4)<<endl;
    cout<<"5 "<<sum(BIT, n, 5)<<endl;
    cout<<"6 "<<sum(BIT, n, 6)<<endl;
    cout<<"7 "<<sum(BIT, n, 7)<<endl;
    cout<<"8 "<<sum(BIT, n, 8)<<endl;
    cout<<"9 "<<sum(BIT, n, 9)<<endl;

    return 0;
}
