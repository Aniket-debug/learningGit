#include <bits/stdc++.h>
using namespace std;

void left_right_smaller(vector<int> &a)
{
    int n = a.size();
    stack<int> s;
    s.push(-1);
    vector<int> left_smaller(n, -1), right_smaller(n, n);
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && a[s.top()] > a[i])
        {
            right_smaller[s.top()] = i;
            s.pop();
        }

        if (s.top() != -1)
        {
            if (a[s.top()] < a[i])
                left_smaller[i] = s.top();
            else
                left_smaller[i] = left_smaller[s.top()];
        }

        s.push(i);
    }
    
    for (int i : left_smaller)
        cout << i << " ";
    cout << '\n';

    for (int i : right_smaller)
        cout << i << " ";
    cout << '\n';
}

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    left_right_smaller(a);
    return 0;
}