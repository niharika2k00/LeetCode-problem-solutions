
/*
______________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :    https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
 Time Complexity :
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define lli long long int
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

int knapSack(int Capacity, int weight[], int val[], int len)
{
    int consider = 0, notConsider = 0;
    if (len == 0 || Capacity == 0)
        return 0;

    if (weight[len - 1] > Capacity)
        return knapSack(Capacity, weight, val, len - 1);

    else
    {
        consider = val[len - 1] + knapSack(Capacity - weight[len - 1], weight, val, len - 1);
        notConsider = knapSack(Capacity, weight, val, len - 1);

        return max(consider, notConsider);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int Capacity = 35, len = sizeof(val) / sizeof(val[0]);
    cout << knapSack(Capacity, wt, val, len);

    return 0;
}