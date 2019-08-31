#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
} * inicio, *fin;

class Cola
{
public:
    Cola()
    {
        inicio = nullptr;
        fin = nullptr;
    }

    Nodo *crearNodo(int dato)
    {
        Nodo *n = new Nodo;
        n->dato = dato;
        n->sig = nullptr;
        return n;
    }

    void push(int dato)
    {
        Nodo *n = crearNodo(dato);
        if (!inicio)
        {
            inicio = n;
        }
        else
        {
            fin->sig = n;
        }
        fin = n;
    }
    void pop()
    {
        Nodo *temp = inicio;
        inicio = inicio->sig;
        free(temp);
    }
    void mostrarCola()
    {
        Nodo *temp = inicio;
        if (!inicio)
            cout << "Cola vacía" << endl;
        else
            while (temp)
            {
                cout << temp->dato << " ";
                temp = temp->sig;
            }
            
        cout << endl;
    }

    void mostrarRecur()
    {
        cout << "Los elementos son" << endl;
        showRecursivo(inicio);
    }

    void showRecursivo(Nodo *p)
    {
        if (p)
        {
            cout << p->dato << endl;
            ;
            showRecursivo(p->sig);
        }
    }
};

class Pila
{
public:
    Pila()
    {
        inicio = nullptr;
    }

    Nodo *crearNodo(int dato)
    {
        Nodo *n = new Nodo;
        n->dato = dato;
        n->sig = nullptr;
        return n;
    }

    void push(int dato)
    {
        Nodo *n = crearNodo(dato);
        n->sig = inicio;
        inicio = n;
    }
    void pop()
    {
        Nodo *temp = inicio;
        inicio = inicio->sig;
        free(temp);
    }
    void mostrarPila()
    {
        Nodo *temp = inicio;
        if (!inicio)
            cout << "Cola vacía" << endl;
        else
            while (temp)
            {
                cout << temp->dato << " ";
                temp = temp->sig;
            }
    }
};

int main()
{

    Cola cola;
    cola.push(1);
    cola.push(2);
    cola.push(3);
    cola.push(5);
    //Mostrando elementos
    cola.mostrarCola();
    //cola.mostrarRecur();

    cout << endl;

    Pila pila;
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(5);
    //Mostrando elementos
    pila.mostrarPila();

    return 0;
}