// Flood Fill Algorithm(Leetcode Q.733)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> image)
{
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
            cout << image[i][j] << " ";
        cout << endl;
    }
}
void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int source, int row, int col)
{
    if (sr < 0 || sr >= row || sc < 0 || sc >= col)
        return;
    else if (image[sr][sc] != source)
        return;

    image[sr][sc] = newColor;

    dfs(image, sr - 1, sc, newColor, source, row, col); // Top
    dfs(image, sr + 1, sc, newColor, source, row, col); // Bottom
    dfs(image, sr, sc - 1, newColor, source, row, col); // Left
    dfs(image, sr, sc + 1, newColor, source, row, col); // Right
}
// Time->O(m*n)
// Space->O(1)
vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor)
{
    if (image[sr][sc] == newColor)
        return image;
    int row = image.size();
    int col = image[0].size();
    int source = image[sr][sc];

    dfs(image, sr, sc, newColor, source, row, col);
    return image;
}
int main()
{
    int m, n;
    cout << "Enter the rows and columns: " << endl;
    cin >> m >> n;
    vector<vector<int>> image(m, vector<int>(n));
    cout << "Enter the element: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> image[i][j];
        }
    }
    cout << "The Matrix is: " << endl;
    printArray(image);
    int sr, sc, newColor;
    cout << "Enter sr and sc: " << endl;
    cin >> sr >> sc;
    cout << "Enter new Color: " << endl;
    cin >> newColor;
    vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
    cout << "The Flood Fill is: " << endl;
    printArray(ans);
    return 0;
}