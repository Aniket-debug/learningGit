#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
#define int long long int
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vs vector<string>
#define vii vector<pair<int, int>>
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define F first
#define S second
#define pi acos(-1)
#define bits __builtin_popcountll
#define add accumulate
#define prefix partial_sum
#define lsb(n) (n & (-n))

long long countSubarray(int N, vector<int> &arr, int X, int k)
{
    unordered_map<int, vector<int>> m;
    vector<int> pre(N);
    long long mod = 1e9 + 7, ans = 0, cntx = 0;

    for (int i = 0; i < N; i++)
        if (arr[i] != X)
            m[arr[i]].push_back(i);

    pre[0] = (arr[0] == X);
    for (int i = 1; i < N; i++)
        pre[i] += pre[i - 1] + (arr[i] == X);

    for (int i : arr)
        cntx += (i == X);

    ans += max(0LL, cntx - (k - 1));

    for (auto i : m)
    {
        unordered_map<int, long long> freq;
        for (int j : i.second)
            freq[pre[j]]++;
        for (auto ii : freq)
            if (freq.find(ii.first + k) != freq.end())
                ans += (freq[ii.first] * freq[ii.first + k]) % mod;
    }

    return ans % mod;
}

void solve()
{
    int n, x, k;
    cin >> n >> x >> k;
    vi a(n);
    cin >> a;
    cout << countSubarray(n, a, x, k);
}

signed main()
{
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
