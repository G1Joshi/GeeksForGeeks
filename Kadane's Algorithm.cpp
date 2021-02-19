#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int sum=arr[0], tsum=arr[0];
    for(int i=1; i<n; i++) {
        tsum=max(arr[i], tsum+arr[i]);
        sum=max(sum, tsum);
    }
    return sum;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        cout << maxSubarraySum(a, n) << endl;
    }
}
