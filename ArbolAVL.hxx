#include "ArbolAVL.h"

template<class T>
ArbolAVL<T>::ArbolAVL() : raiz(nullptr) {}

template<class T>
ArbolAVL<T>::~ArbolAVL() {
    // Se asume que el destructor de Nodo maneja su propia memoria
    delete raiz;  
}

template<class T>
int ArbolAVL<T>::obtenerNivel(Nodo<T>* nodo, T valor, int nivel) {
    if (nodo == nullptr) {
        return -1; // Si el nodo no se encuentra, devolvemos -1
    }

    if (nodo->obtenerDato() == valor) {
        return nivel; // Si encontramos el valor, devolvemos el nivel actual
    }

    // Buscamos en el subárbol izquierdo si el valor es menor
    if (valor < nodo->obtenerDato()) {
        return obtenerNivel(nodo->obtenerHijoIzq(), valor, nivel + 1);
    }

    // Buscamos en el subárbol derecho si el valor es mayor
    return obtenerNivel(nodo->obtenerHijoDer(), valor, nivel + 1);
}

template<class T>
int ArbolAVL<T>::obtenerNivel(T valor) {
    return obtenerNivel(raiz, valor, 0);  // Inicia desde la raíz con el nivel 0
}

template <class T>
bool ArbolAVL<T>::esVacio(){
    return raiz == nullptr;
}

template <class T>
T& ArbolAVL<T>::datoRaiz(){
    if (!esVacio()) {
        return raiz->obtenerDato();
    }
    throw std::runtime_error("El árbol está vacío");
}

template <class T>
int ArbolAVL<T>::tamano() {
    return tamano(raiz);
}

template <class T>
int ArbolAVL<T>::tamano(Nodo<T>* nodoActual) {
    if (nodoActual == nullptr) {
        return 0;
    }
    return 1 + tamano(nodoActual->obtenerHijoIzq()) + tamano(nodoActual->obtenerHijoDer());
}

template<class T>
int ArbolAVL<T>::obtenerBalance(Nodo<T>* nodo) {
    if (nodo == nullptr) return 0; // Añadido para evitar acceder a un nodo nulo
    return altura(nodo->obtenerHijoIzq()) - altura(nodo->obtenerHijoDer());
}

template<class T>
Nodo<T>* ArbolAVL<T>::rotarDerecha(Nodo<T>* y) {
    Nodo<T>* x = y->obtenerHijoIzq();
    Nodo<T>* T2 = x->obtenerHijoDer();

    x->fijarHijoDer(y);
    y->fijarHijoIzq(T2);

    y->fijarAltura(std::max(altura(y->obtenerHijoIzq()), altura(y->obtenerHijoDer())) + 1);
    x->fijarAltura(std::max(altura(x->obtenerHijoIzq()), altura(x->obtenerHijoDer())) + 1);

    return x;
}

template <class T>
int ArbolAVL<T>::altura() {
    return altura(raiz); // No es necesario verificar si está vacío aquí
}

template <class T>
int ArbolAVL<T>::altura(Nodo<T>* nodoActual) {
    if (nodoActual == nullptr) {
        return -1; // Devolver -1 para contar la altura de manera correcta
    }
    
    int alturaIzq = altura(nodoActual->obtenerHijoIzq());
    int alturaDer = altura(nodoActual->obtenerHijoDer());

    return 1 + std::max(alturaIzq, alturaDer);
}

template<class T>
Nodo<T>* ArbolAVL<T>::rotarIzquierda(Nodo<T>* x) {
    Nodo<T>* y = x->obtenerHijoDer();
    Nodo<T>* T2 = y->obtenerHijoIzq();

    y->fijarHijoIzq(x);
    x->fijarHijoDer(T2);

    x->fijarAltura(std::max(altura(x->obtenerHijoIzq()), altura(x->obtenerHijoDer())) + 1);
    y->fijarAltura(std::max(altura(y->obtenerHijoIzq()), altura(y->obtenerHijoDer())) + 1);

    return y;
}

template <class T>
bool ArbolAVL<T>::buscar(T& val) {
    Nodo<T>* nodoActual = raiz;
    while (nodoActual != nullptr) {
        if (val < nodoActual->obtenerDato()) {
            nodoActual = nodoActual->obtenerHijoIzq();
        } else if (val > nodoActual->obtenerDato()) {
            nodoActual = nodoActual->obtenerHijoDer();
        } else {
            return true; // Valor encontrado
        }
    }
    return false; // Valor no encontrado
}

template<class T>
Nodo<T>* ArbolAVL<T>::insertar(Nodo<T>* nodo, T& val) {
    if (nodo == nullptr) return new Nodo<T>(val);

    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(insertar(nodo->obtenerHijoIzq(), val));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(insertar(nodo->obtenerHijoDer(), val));
    } else {
        return nodo; // No se permiten duplicados
    }

    nodo->fijarAltura(1 + std::max(altura(nodo->obtenerHijoIzq()), altura(nodo->obtenerHijoDer())));

    int balance = obtenerBalance(nodo);

    // Rotaciones
    if (balance > 1 && val < nodo->obtenerHijoIzq()->obtenerDato()) {
        return rotarDerecha(nodo);
    }
    if (balance < -1 && val > nodo->obtenerHijoDer()->obtenerDato()) {
        return rotarIzquierda(nodo);
    }
    if (balance > 1 && val > nodo->obtenerHijoIzq()->obtenerDato()) {
        nodo->fijarHijoIzq(rotarIzquierda(nodo->obtenerHijoIzq()));
        return rotarDerecha(nodo);
    }
    if (balance < -1 && val < nodo->obtenerHijoDer()->obtenerDato()) {
        nodo->fijarHijoDer(rotarDerecha(nodo->obtenerHijoDer()));
        return rotarIzquierda(nodo);
    }

    return nodo;
}

template <class T>
std::vector<T> ArbolAVL<T>::inOrden() {
    std::vector<T> elementos;
    inOrden(raiz, elementos); // Llama a la función recursiva
    return elementos; // Retorna el vector
}

template <class T>
void ArbolAVL<T>::inOrden(Nodo<T>* nodoActual, std::vector<T>& elementos) {
    if (nodoActual != nullptr) {
        inOrden(nodoActual->obtenerHijoIzq(), elementos);  // Visitar subárbol izquierdo
        elementos.push_back(nodoActual->obtenerDato());     // Agregar dato al vector
        inOrden(nodoActual->obtenerHijoDer(), elementos);   // Visitar subárbol derecho
    }
}

template<class T>
bool ArbolAVL<T>::insertar(T& val) {
    raiz = insertar(raiz, val);
    return true;
}

template<class T>
Nodo<T>* ArbolAVL<T>::encontrarMinimo(Nodo<T>* nodo) {
    while (nodo->obtenerHijoIzq() != nullptr) {
        nodo = nodo->obtenerHijoIzq();
    }
    return nodo;
}

template<class T>
Nodo<T>* ArbolAVL<T>::eliminar(Nodo<T>* nodo, T& val) {
    if (nodo == nullptr) return nodo; // Si el nodo es nulo, devolvemos nulo

    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(eliminar(nodo->obtenerHijoIzq(), val));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(eliminar(nodo->obtenerHijoDer(), val));
    } else {
        // Si el nodo tiene solo un hijo o es hoja
        if ((nodo->obtenerHijoIzq() == nullptr) || (nodo->obtenerHijoDer() == nullptr)) {
            Nodo<T>* temp = nodo->obtenerHijoIzq() ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();

            // No hijo
            if (temp == nullptr) {
                temp = nodo;
                nodo = nullptr; // Eliminar el nodo
            } else {
                *nodo = *temp; // Copiar el contenido del nodo hijo
            }
            delete temp;
        } else {
            // Nodo con dos hijos: obtener el sucesor inorden (el más pequeño del subárbol derecho)
            Nodo<T>* temp = encontrarMinimo(nodo->obtenerHijoDer());
            nodo->fijarDato(temp->obtenerDato()); // Copiar el dato del sucesor inorden
            nodo->fijarHijoDer(eliminar(nodo->obtenerHijoDer(), temp->obtenerDato())); // Eliminar el sucesor
        }
    }

    // Si el árbol tenía solo un nodo
    if (nodo == nullptr) return nodo;

    // Actualizar la altura del nodo actual
    nodo->fijarAltura(1 + std::max(altura(nodo->obtenerHijoIzq()), altura(nodo->obtenerHijoDer())));

    // Obtener el balance
    int balance = obtenerBalance(nodo);

    // Rotaciones
    if (balance > 1 && obtenerBalance(nodo->obtenerHijoIzq()) >= 0) {
        return rotarDerecha(nodo);
    }
    if (balance < -1 && obtenerBalance(nodo->obtenerHijoDer()) <= 0) {
        return rotarIzquierda(nodo);
    }
    if (balance > 1 && obtenerBalance(nodo->obtenerHijoIzq()) < 0) {
        nodo->fijarHijoIzq(rotarIzquierda(nodo->obtenerHijoIzq()));
        return rotarDerecha(nodo);
    }
    if (balance < -1 && obtenerBalance(nodo->obtenerHijoDer()) > 0) {
        nodo->fijarHijoDer(rotarDerecha(nodo->obtenerHijoDer()));
        return rotarIzquierda(nodo);
    }

    return nodo; // Devolver el nodo modificado
}

template<class T>
bool ArbolAVL<T>::eliminar(T& val) {
    raiz = eliminar(raiz, val);
    return true;
}

template<class T>
void ArbolAVL<T>::preOrden() {
    preOrden(raiz);
}

template<class T>
void ArbolAVL<T>::preOrden(Nodo<T>* nodoActual) {
    if (nodoActual != nullptr) {
        std::cout << nodoActual->obtenerDato() << " "; // Visitar nodo
        preOrden(nodoActual->obtenerHijoIzq());        // Visitar subárbol izquierdo
        preOrden(nodoActual->obtenerHijoDer());        // Visitar subárbol derecho
    }
}

template<class T>
void ArbolAVL<T>::posOrden() {
    posOrden(raiz);
}

template<class T>
void ArbolAVL<T>::posOrden(Nodo<T>* nodoActual) {
    if (nodoActual != nullptr) {
        posOrden(nodoActual->obtenerHijoIzq());        
        posOrden(nodoActual->obtenerHijoDer());        
        std::cout << nodoActual->obtenerDato() << " "; 
    }
}
