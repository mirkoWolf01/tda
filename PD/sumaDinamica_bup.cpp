#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, k;
    cin >> n;

    vector<int> conj(n);
    for (int i = 0; i < n; i++)
        cin >> conj[i];

    cin >> k;
    vector<bool> memo(k+1, false); // Creo un vector de tamaño k+1, osea de 0 a k y a cada valor le asigno false
    memo[0] = true;

    for (int c : conj){
        for(int j = k; j >= c; j--){
            memo[j] = memo[j] || memo[j - c];
        }
    }
    cout << memo[k];
    return 0;
}
