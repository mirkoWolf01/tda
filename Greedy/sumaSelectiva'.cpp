#include <iostream>
#include <vector>
using namespace std;
#include <queue> // Max_Heap

// Implementación en O(n log k)

int main()
{
    int length, k;
    cin >> length;
    vector<int> vec(length);

    for (int i = 0; i < length; i++)
        cin >> vec[i];

    cin >> k;

    priority_queue<int, vector<int>, greater<int>> min_heap;    // Si fuera max_heap, seria con less

    for (int i = 0; i < length; i++)
    {
        int elem = vec[i];
        if (min_heap.size() < k)
            min_heap.emplace(elem);
        else if (min_heap.top() < elem)
        {
            min_heap.pop();
            min_heap.emplace(elem);
        }
    }

    while (min_heap.size() != 0)
    {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
    return 0;
}
