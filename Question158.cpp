//Fractional Knapsack problem
#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
//Time->O(nlogn)
//Space->O(n)
int FractionalKnapsack(int W, int n, Item arr[])
{
    vector<pair<double, int>> v;
    for (int i = 0; i < n; i++)
    {
        double x = (arr[i].value * 1.0) / (arr[i].weight * 1.0);
        v.push_back({x, i});
    }
    sort(v.begin(), v.end(), greater<pair<double, int>>());
    int curr_weight = 0;
    double max_profit = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (curr_weight + arr[v[i].second].weight < W)
        {
            max_profit += arr[v[i].second].value;
            curr_weight += arr[v[i].second].weight;
        }
        else
        {
            double frac = (W - curr_weight) * 1.0;
            max_profit += frac * v[i].first;
            break;
        }
    }
    return max_profit;
}
int main()
{
    int n, W;
    cout << "Enter the number of items: " << endl;
    cin >> n;
    Item arr[n];
    cout << "Enter the values and weigths: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }
    cout << "The Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << arr[i].value << "," << arr[i].weight << "] ";
    }
    cout << "\nEnter the weigth to be accomodate in the knapsack: " << endl;
    cin >> W;
    cout << "The Maximum Profit in Fractional Knapsack is: " << FractionalKnapsack(W, n, arr) << endl;
    return 0;
}