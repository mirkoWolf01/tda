#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int length, C;
    cin >> length;
    vector<int> vec(length), res = {};

    for (int i = 0; i < length; i++)
        cin >> vec[i];

    cin >> C;

    int i = 0, fillups = 0;
    while (i < length - 1)
    {
        res.push_back(vec[i]);
        fillups++;

        int km_actual = vec[i];
        int j = i + 1;

        while (vec[j] - vec[i] <= C)
        {
            j++;
            if (j >= length)
                break;
        }

        if (j == i + 1)
        {
            cout << "No se puede llegar al destino";
            return 0;
        }
        i = j - 1;
    }
    cout << fillups << endl;
    for (int elem : res)
        cout << elem << " ";
    return 0;
}
