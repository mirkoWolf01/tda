#include <iostream>
#include <vector>
using namespace std;

bool busqueda_bin(vector<int> &arr, int left, int right)
{
    if (left > right)
        return false;

    int mid = (left + right) / 2;

    if (arr[mid] == mid)
        return true;
    else if (arr[mid] > mid)
        return busqueda_bin(arr, left, mid - 1);
    else
        return busqueda_bin(arr, mid + 1, right);
}

int main()
{
    int length;
    cin >> length;
    vector<int> arr(length);

    for (int i = 0; i < length; i++)
        cin >> arr[i];

    if (length == 1)
    {
        cout << (arr[0] == 0);
        return 0;
    }

    cout << busqueda_bin(arr, 0, length - 1);

    return 0;
}