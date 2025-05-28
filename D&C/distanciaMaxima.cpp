#include <iostream>
using namespace std;

struct Nodo
{
    char valor;
    Nodo *izq;
    Nodo *der;
    Nodo(char v) : valor(v), izq(nullptr), der(nullptr) {}
};

int altura(Nodo *ab)
{
    if (ab == nullptr)
        return 0;
    else
        return (1 + max(altura(ab->izq), altura(ab->der)));
}

int max_dist(Nodo *ab)
{
    if (ab == nullptr)
        return -1;

    int hl = altura(ab->izq);
    int hr = altura(ab->der);

    int local_diam = hl + hr;

    return max(max(local_diam, max_dist(ab->izq)), max_dist(ab->der));
}

/* Nodo *ej()
{
    Nodo *A = new Nodo('A');
    Nodo *B = new Nodo('B');
    Nodo *C = new Nodo('C');
    Nodo *D = new Nodo('D');

    A->izq = B;
    A->der = C;
    B->izq = D;

    return A; // raíz del árbol
} */

int main()
{
    cout << max_dist(new Nodo ('B'));
    return 0;
}
