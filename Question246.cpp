// Ninjas's Training(Coding Ninjas)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> points)
{
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = 0; j < 3; j++)
            cout << points[i][j] << " ";
        cout << endl;
    }
}
// Approach-I(Simple Recurssion)
// Time->O(2^n)
// Space->O(n)
int fun1(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + fun1(day - 1, i, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}
// Approach-II(Memoization)
// Time->O(n*4*3)
// Space->O(n)+O(n*4)
int fun2(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + fun1(day - 1, i, points);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return fun2(n - 1, 3, points, dp);
}
// Approach-III(Tabulation)
// Time->O(n*4*3)
// Space->O(n*4)
int fun3(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int point = points[day][i] + dp[day - 1][i];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}
// Approach-IV(Space Optimization)
// Time->O(n*4*3)
// Space->O(1)
int fun4(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int point = points[day][i] + prev[i];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
int main()
{
    int n;
    cout << "Enter the number of days: " << endl;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> points[i][j];
    }
    cout << "The Matrix is: " << endl;
    printArray(points);
    cout << "Maximum points of training is: " << fun4(n, points) << endl;
    return 0;
}