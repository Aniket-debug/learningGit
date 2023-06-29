#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int f(int l, int r, vector<int> &a, int t, int sc_j)
{
    if (l > r)
        return sc_j;
    if (dp[sc_j] != -1)
        return dp[sc_j];
    return dp[sc_j] = max(f(l, r - 1, a, t ^ 1, sc_j + t * a[r]), f(l + 1, r, a, t ^ 1, sc_j + t * a[l]));
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    memset(dp, -1, sizeof(dp));
    cout << f(0, n - 1, a, 1, 0) << '\n';
    return 0;
}