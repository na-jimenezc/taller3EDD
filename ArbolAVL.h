#ifndef ArbolAVL_h
#define ArbolAVL_h

#include "Nodo.h"
#include <iostream>
#include <queue>


template<class T>
class ArbolAVL {
protected:
    Nodo<T>* raiz;

    int altura(Nodo<T>* nodo);
    int obtenerBalance(Nodo<T>* nodo);
    Nodo<T>* rotarDerecha(Nodo<T>* y);
    Nodo<T>* rotarIzquierda(Nodo<T>* x);
    Nodo<T>* insertar(Nodo<T>* nodo, T& val);
    Nodo<T>* eliminar(Nodo<T>* nodo, T& val);
    Nodo<T>* encontrarMinimo(Nodo<T>* nodo);

public:

    bool esVacio();
    T& datoRaiz();
    int altura();  
    int tamano();
    int tamano(Nodo<T> * nodoActual);
    bool insertar(T& val);
    bool eliminar(T& val);
    bool buscar(T& val);
    void inOrden();
    void inOrden(Nodo<T>* nodoActual);
    void preOrden();
    void preOrden(Nodo<T> * nodoActual);
    void posOrden();
    void posOrden(Nodo<T> * nodoActual);
    void nivelOrden(); 
    ArbolAVL();
    ~ArbolAVL();

};

#include "ArbolAVL.hxx"
#endif