#ifndef Nodo_h
#define Nodo_h

template<class T>
class Nodo {
protected:
    T dato;
    Nodo<T>* hijoIzq;
    Nodo<T>* hijoDer;
    int altura;

public:
    Nodo();
    Nodo(T val);
    ~Nodo();

    T& obtenerDato();
    void fijarDato(T& val);
    Nodo<T>* obtenerHijoIzq();
    void fijarHijoIzq(Nodo<T>* hijo);
    Nodo<T>* obtenerHijoDer();
    void fijarHijoDer(Nodo<T>* hijo);
    int obtenerAltura();
    void fijarAltura(int altura);

    bool esHoja();
};

#include "Nodo.hxx"
#endif