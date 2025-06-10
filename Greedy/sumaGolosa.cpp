#include <iostream>
#include <vector>
#include <queue> // Max_Heap
using namespace std;

int main()
{
    int length, res = 0;
    cin >> length;
    vector<int> vec(length);

    for (int i = 0; i < length; i++)
        cin >> vec[i];

    priority_queue<int, vector<int>, greater<int>> min_heap;    // Si fuera max_heap, seria con less

    for (int i = 0; i < length; i++)    // O(n log n)
        min_heap.emplace(vec[i]);
    
    while(min_heap.size() > 1){ // O(n)
        int a, b, c = 0;
        a = min_heap.top();
        min_heap.pop();
        b = min_heap.top();
        min_heap.pop();

        c = a + b;
        res += c;
        min_heap.emplace(c);
    }

    cout << res;
    return 0;
}
