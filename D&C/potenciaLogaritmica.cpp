#include <iostream>
#include <vector>
using namespace std;

int prod(int base, int exp)
{
    int res_prod;
    if (exp == 0){
        return 1;
    }else if(exp % 2 == 0){
        res_prod = prod(base, exp/2);
        return res_prod * res_prod;
    }else{
        res_prod = prod(base, (exp - 1)/2);
        return base * res_prod * res_prod;
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << prod(a,b);
    return 0;
}
