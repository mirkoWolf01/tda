#include <iostream>
#include <vector>
using namespace std;

int n, m;

int pd(vector<vector<int>> &matrix, vector<vector<int>> &memo, int i, int j)
{
    if (i < n - 1 && j < m - 1)
    {
        if (memo[i][j + 1] == -1)
            pd(matrix, memo, i, j + 1);
        if (memo[i + 1][j] == -1)
            pd(matrix, memo, i + 1, j);
        memo[i][j] = min(memo[i + 1][j], memo[i][j + 1]);
    }
    else if (j < m - 1)
    {
        if (memo[i][j + 1] == -1)
            memo[i][j] = pd(matrix, memo, i, j + 1);
        memo[i][j] = memo[i][j + 1];
    }
    else if (i < n - 1)
    {
        if (memo[i + 1][j] == -1)
            memo[i][j] = pd(matrix, memo, i + 1, j);
        memo[i][j] = memo[i + 1][j];
    }

    memo[i][j] = max(1, memo[i][j] - matrix[i][j]);
    return memo[i][j];
}

int main()
{
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m)); // O(n*m)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    vector<vector<int>> memo(n, vector<int>(m, -1));

    int base_val = matrix[n - 1][m - 1];
    memo[n - 1][m - 1] = max(1 - base_val, 1);
    cout << pd(matrix, memo, 0, 0);

    return 0;
}
/*
3 3
-2 -3 3
-5 -10 1
10 30 -5

5 5
-3 27 -10 5 -15
4 -1 9 10 -7 
-1 4 3 -12 -6
10 4 3 2 -1
19 -6 -7 -10 2

*/