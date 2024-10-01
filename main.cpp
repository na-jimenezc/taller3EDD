/* Taller 3 */
// Katheryn Guasca
// Miguel Laiton
// Natalia Jiménez

#include <iostream>
#include "ArbolAVL.h"
#include "Nodo.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void abrirArchivo(std::string nombreArchivo, ArbolAVL<int>& arbolito);
void calcularMediana(ArbolAVL<int>& arbolito);

int main() {

    ArbolAVL<int> arbolito;
    std::string nombreArchivo;

    std::cout << "¡Bienvenido a nuestro taller!" << std::endl;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombreArchivo;

    abrirArchivo(nombreArchivo, arbolito);
    
    std::cout << "\nImpresión preOrden" << std::endl;
    arbolito.preOrden();
    std::cout << std::endl;

    std::cout << "\nImpresión posOrden" << std::endl;
    arbolito.posOrden();
    std::cout << std::endl;

    std::cout << "\nImpresión inOrden" << std::endl;
    arbolito.inOrden();
    std::cout << std::endl;

    // Calcular y mostrar la mediana
    calcularMediana(arbolito);

    std::cout << "\nPresione cualquier tecla para cerrar el programa...";
    std::cin.ignore(); 
    std::cin.get();    

    return 0;
}

void abrirArchivo(std::string nombreArchivo, ArbolAVL<int>& arbolito) {
    // Abrir el archivo y procesar las operaciones (A = agregar, E = eliminar)
    std::ifstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        std::cerr << "No fue posible abrir el archivo" << std::endl;
        return;
    }

    std::string linea;

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        char letra;
        int valor;

        ss >> letra >> valor;

        if (letra == 'A') {
            std::cout << "Se ha agregado: " << valor << std::endl;
            arbolito.insertar(valor);  
        } else if (letra == 'E') {
            std::cout << "Ha sido eliminado: " << valor << std::endl;
            arbolito.eliminar(valor);  
        } else {
            std::cerr << "La letra ingresada no es válida: " << letra << std::endl;
        }
    }

    archivo.close();
}

void calcularMediana(ArbolAVL<int>& arbolito) {
    // Obtener el recorrido inOrden para tener los elementos ordenados
    std::vector<int> elementos = arbolito.inOrden();
    int n = elementos.size();

    if (n == 0) {
        std::cout << "El árbol está vacío, no hay elementos para calcular la mediana." << std::endl;
        return;
    }

    std::cout << "\nCálculo de la mediana:" << std::endl;

    // Si la cantidad de elementos es impar
    if (n % 2 != 0) {
        int mediana = elementos[n / 2];
        std::cout << "La mediana es: " << mediana << std::endl;
        std::cout << "El nivel de la mediana (" << mediana << ") es: " << arbolito.obtenerNivel(mediana) << std::endl;
    } else {
        // Si la cantidad de elementos es par
        int valor1 = elementos[(n / 2) - 1];
        int valor2 = elementos[n / 2];
        double mediana = (valor1 + valor2) / 2.0;

        std::cout << "Los dos valores centrales son: " << valor1 << " y " << valor2 << std::endl;
        std::cout << "La mediana es: " << mediana << std::endl;
        std::cout << "El nivel del valor central 1 (" << valor1 << ") es: " << arbolito.obtenerNivel(valor1) << std::endl;
        std::cout << "El nivel del valor central 2 (" << valor2 << ") es: " << arbolito.obtenerNivel(valor2) << std::endl;
    }
}
