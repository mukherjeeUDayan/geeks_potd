/*
You are given an array arr of size n. The elements of the array represent n coin of values v1, v2, ....vn. You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example 1:

Input:
n = 4
arr[] = {5, 3, 7, 10}
Output: 
15
Explanation: The user collects maximum
value as 15(10 + 5)
Example 2:

Input:
n = 4
arr[] = {8, 15, 3, 7}
Output: 
22
Explanation: The user collects maximum
value as 22(7 + 15)
*/
class Solution{
    public:
    int help(int arr[], int start, int end, vector<vector<int>> &dp)
    {
        if(end == start) return arr[start];
        if(start>end) return 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int l = arr[start] + min( help(arr, start+1, end-1, dp), help(arr, start+2, end, dp) );
        int r = arr[end] + min( help(arr, start, end-2, dp), help(arr, start+1, end-1, dp) );
        
        return dp[start][end] = max(l, r);
    } 

    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return help(arr, 0, n-1, dp);
    }
};
