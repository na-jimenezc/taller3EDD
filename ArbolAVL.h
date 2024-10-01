#ifndef ArbolAVL_h
#define ArbolAVL_h

#include "Nodo.h"
#include <iostream>
#include <queue>
#include <vector>


template<class T>
class ArbolAVL {
protected:
    Nodo<T>* raiz;

    int obtenerBalance(Nodo<T>* nodo);

    Nodo<T>* rotarDerecha(Nodo<T>* y);
    Nodo<T>* rotarIzquierda(Nodo<T>* x);
    Nodo<T>* insertar(Nodo<T>* nodo, T& val);
    Nodo<T>* eliminar(Nodo<T>* nodo, T& val);
    Nodo<T>* encontrarMinimo(Nodo<T>* nodo);

public:
    int obtenerNivel(T valor);
    int obtenerNivel(Nodo<T>* nodo, T valor, int nivel);
    bool esVacio();
    T& datoRaiz();
    int tamano();
    int tamano(Nodo<T> * nodoActual);
    bool insertar(T& val);
    bool eliminar(T& val);
    bool buscar(T& val);
    int altura();
    int altura(Nodo<T> * nodoActual);  

    void inOrden(Nodo<T>* nodo, std::vector<T>& elementos);
    std::vector<T> inOrden();


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