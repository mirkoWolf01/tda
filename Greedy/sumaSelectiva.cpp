#include <iostream>
#include <vector>
using namespace std;
#include <algorithm> // Necesario para std::sort

// Implementación en O(n log n)

int main(int argc, char const *argv[])
{
    int length, k;
    cin >> length;
    vector<int> vec(length);

    for (int i = 0; i < length; i++)
        cin >> vec[i];

    cin >> k;
    sort(vec.begin(), vec.end(), greater<int>());

    for (int i = 0; i < k; i++)
        cout << vec[i] << " ";
    return 0;
}
