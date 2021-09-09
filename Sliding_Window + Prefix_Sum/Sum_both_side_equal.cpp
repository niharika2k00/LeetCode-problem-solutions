/* 
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://leetcode.com/contest/biweekly-contest-60/problems/find-the-middle-index-in-array/  
          https://www.geeksforgeeks.org/find-element-array-sum-left-array-equal-sum-right-array/
 Time Complexity :  
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define loop1(n) for (ll i = 0; i < (n); i++)
#define loop2(n) for (ll i = 1; i <= (n); i++)
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)

int findElement(int arr[], int n)
{
    if (n == 1)
        return 0;

    //  Time Complexity : O(n)
    //  Space Complexity :  O(n)
    /*     int i, bf, af;
    vector<int> prefix(n, 0), suffix(n, 0);
    prefix[0] = arr[0];

    suffix[n - 1] = arr[n - 1];

    for (i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    for (i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + arr[i];

    for (i = 0; i < n; i++)
    {
        bf = (i == 0) ? 0 : prefix[i - 1];
        af = (i == n - 1) ? 0 : suffix[i + 1];
        if (bf == af)
            return i;
    }
    return -1; */

    //  -----------------------------------------------------

    //  Time Complexity : O(n)
    //  Space Complexity :  O(1)
    int sum, i, prefixSum = 0, ans = -1;
    sum = accumulate(arr, arr + n, 0);

    for (i = n - 1; i >= 0; i--)
    {
        if (prefixSum == sum - (arr[i] + prefixSum))
        {
            ans = i;
            break;
        }
        prefixSum += arr[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[] = {2, 3, 4, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findElement(arr, n);

    return 0;
}

/* 
TEST CASES :: 

[0 0 0 0]
ans : 0

[0 4]
ans : 1 

[1 -1 4]
ans : 2 

[2 3 -1 8 4]
ans : 3
 */
