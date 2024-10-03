#ifndef ArbolAVL_h
#define ArbolAVL_h

#include "Nodo.h"
#include <iostream>
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
    ArbolAVL();
    ~ArbolAVL();

    int obtenerNivel(T valor);
    bool esVacio();
    T& datoRaiz();
    int tamano();
    int altura();
    
    bool insertar(T& val);
    bool eliminar(T& val);
    bool buscar(T& val);
    std::vector<T> inOrden(); 
    void preOrden();
    void posOrden();
    
private:
    int obtenerNivel(Nodo<T>* nodo, T valor, int nivel);
    int tamano(Nodo<T>* nodoActual);
    int altura(Nodo<T>* nodoActual);
    
    void inOrden(Nodo<T>* nodoActual, std::vector<T>& elementos);
    void preOrden(Nodo<T>* nodoActual);
    void posOrden(Nodo<T>* nodoActual);
};

#include "ArbolAVL.hxx"
#endif


