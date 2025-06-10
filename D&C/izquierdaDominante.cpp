#include <iostream>
#include <vector>
using namespace std;


int sum(vector<int> arr)
{
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        res += arr[i];
    }
    return res;
}

bool bigger_left(vector<int> arr)
{
    int length = arr.size();
    if (length == 2)
    {
        return arr[0] > arr[1];
    }

    vector<int> left(arr.begin(), arr.begin() + length / 2);
    vector<int> right(arr.begin() + length / 2, arr.end());

    if (!(sum(left) > sum(right)))
    {
        return false;
    }

    return bigger_left(left) && bigger_left(right);
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
        cout << (bool)true;
        return 0;
    }

    vector<int> left(arr.begin(), arr.begin() + length / 2);
    vector<int> right(arr.begin() + length / 2, arr.end());

    bool res;
    if (!(sum(left) > sum(right)))
    {
        res = false;
    }
    else if (length / 2 == 1)
    {
        res = true;
    }
    else
    {
        res = bigger_left(left) && bigger_left(right);
    }
    cout << (bool)res;
    return 0;
}
