#include "Nodo.h"
//Constructor del Nodo
template<class T>
Nodo<T>::Nodo() : hijoIzq(nullptr), hijoDer(nullptr), altura(0) {}

//Cuando recibe un valor tipo T
template<class T>
Nodo<T>::Nodo(T val) : dato(val), hijoIzq(nullptr), hijoDer(nullptr), altura(1) {}

template<class T>
Nodo<T>::~Nodo() {
    if (hijoIzq != nullptr) {
        delete hijoIzq;
    }
    if (hijoDer != nullptr) {
        delete hijoDer;
    }
}

template<class T>
T& Nodo<T>::obtenerDato() {
    return dato;
}

template<class T>
void Nodo<T>::fijarDato(T& val) {
    dato = val;
}

template<class T>
Nodo<T>* Nodo<T>::obtenerHijoIzq() {
    return hijoIzq;
}

template<class T>
void Nodo<T>::fijarHijoIzq(Nodo<T>* hijo) {
    hijoIzq = hijo;
}

template<class T>
Nodo<T>* Nodo<T>::obtenerHijoDer() {
    return hijoDer;
}

template<class T>
void Nodo<T>::fijarHijoDer(Nodo<T>* hijo) {
    hijoDer = hijo;
}

template<class T>
int Nodo<T>::obtenerAltura() {
    return altura;
}

template<class T>
void Nodo<T>::fijarAltura(int nuevaAltura) {
    altura = nuevaAltura;
}
 //Mirar si ese nodo es una hoja 
template<class T>
bool Nodo<T>::esHoja() {
    return (hijoIzq == nullptr && hijoDer == nullptr);
}