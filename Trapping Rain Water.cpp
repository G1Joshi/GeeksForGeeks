#include <bits/stdc++.h>
using namespace std;

int trappingWater(int arr[], int n)
{
    int m, t = 0;
    int s = INT_MIN;
    int r[n], l[n];
    for (int i = 0; i < n; i++)
    {
        s = max(s, arr[i]);
        l[i] = s;
    }
    s = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        s = max(s, arr[i]);
        r[i] = s;
    }
    for (int i = 0; i < n; i++)
    {
        m = min(r[i], l[i]);
        if (m > arr[i])
            t += (m - arr[i]);
    }
    return t;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << trappingWater(a, n) << endl;
    }
    return 0;
}