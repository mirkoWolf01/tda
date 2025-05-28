#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int l1;
    cin >> l1;
    vector<int> v1(l1);

    for (int i = 0; i < l1; i++)
    {
        cin >> v1[i];
    }

    int l2;
    cin >> l2;
    vector<int> v2(l2);

    for (int i = 0; i < l2; i++)
    {
        cin >> v2[i];
    }

    int i = 0, j = 0, k = 0;
    while (i < l1 && j < l2)
    {
        if (abs(v1[i] - v2[j]) <= 1)
        {
            k++;
            i++;
            j++;
        }
        else if (v1[i] < v2[j])
            i++;
        else
            j++;
    }
    cout << k;
    return 0;
}
