#include <iostream>
#include <vector>
using namespace std;

int size_C;

// El -1 representa indeterminado, el 0 falso y el 1 true.
int pd(vector<int> &conj, vector<vector<int>> &memo, int i, int j)
{
    if (j < 0) // Si se pasa, osea no suma lo que  deberia, devuelve 0.
        return 0;

    if (i == -1) // Si no quedan elementos por sumar, comprueba que j sea igual a 0.
        return (bool)j == 0;

    if (memo[i][j] == -1) // Si no esta indeterminado, lo calcula.
        memo[i][j] = pd(conj, memo, i - 1, j) || pd(conj, memo, i - 1, j - conj[i]);

    return memo[i][j];
}

int main()
{
    cin >> size_C;

    vector<int> conj(size_C);
    for (int i = 0; i < size_C; i++)
        cin >> conj[i];

    int k;
    cin >> k;
    vector<vector<int>> memo(size_C + 1, vector<int>(k + 1, -1));

    cout << (pd(conj, memo, size_C - 1, k) ? "true" : "false");
    return 0;
}
