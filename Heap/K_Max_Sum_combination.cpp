
/*
________________________________________
----------------------------------------
 Author    :  Niharika Dutta
 Code Link :  https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
 Time Complexity :
________________________________________
----------------------------------------
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int len, int k)
{
    //  Time-Complexity : O(n^2)
    //  Space Complexity :  O(n)
    priority_queue<int, vector<int, int>> maxHeap;
    vector<int> res;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
            maxHeap.push(a[i] + b[j]);
    }

    while (k--)
    {
        int ele = maxHeap.top();
        maxHeap.pop();
        res.push_back(ele);
    }

    return res;
}

// https://placewit.medium.com/k-max-sum-combinations-2c6d67a3acb

// https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/#:~:text=Given%20two%20equally%20sized%20arrays,all%20the%20possible%20sum%20combinations.