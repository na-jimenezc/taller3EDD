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

void abrirArchivo(const std::string& nombreArchivo, ArbolAVL<int>& arbolito);
void calcularMediana(ArbolAVL<int>& arbolito, const std::string& archivoMediana);

int main() {
    ArbolAVL<int> arbolito;
    std::string nombreArchivo;

    std::cout << "¡Bienvenido a nuestro taller!" << std::endl;
    std::cout << "Ingrese el nombre del archivo : ";
    std::cin >> nombreArchivo;

    abrirArchivo(nombreArchivo, arbolito);

    // Realiza el recorrido inOrden y almacena los resultados
    std::vector<int> resultadoInorden = arbolito.inOrden(); // Suponiendo que inOrden devuelve un vector
    std::cout << "\nImpresión inOrden:" << std::endl;
    for (int valor : resultadoInorden) {
        std::cout << valor << " ";
    }
    std::cout << std::endl;

    // Realiza el recorrido preOrden y muestra los resultados
    std::cout << "\nImpresión preOrden:" << std::endl;
    arbolito.preOrden(); // Suponiendo que preOrden imprime directamente
    std::cout << std::endl;

    // Realiza el recorrido posOrden y muestra los resultados
    std::cout << "\nImpresión posOrden:" << std::endl;
    arbolito.posOrden(); // Suponiendo que posOrden imprime directamente
    std::cout << std::endl;

    // Determina el nombre del archivo de mediana según el archivo de entrada
    std::string archivoMediana;
    if (nombreArchivo == "in_01.txt") {
        archivoMediana = "median_01.txt";
    } else {
        archivoMediana = "median_00.txt";
    }

    // Calcular y guardar la mediana en el archivo correspondiente
    calcularMediana(arbolito, archivoMediana);

    std::cout << "\nPresione cualquier tecla para cerrar el programa...";
    std::cin.ignore(); 
    std::cin.get();    

    return 0;
}

void abrirArchivo(const std::string& nombreArchivo, ArbolAVL<int>& arbolito) {
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
            arbolito.insertar(valor);  
        } else if (letra == 'E') {
            arbolito.eliminar(valor);  
        } else {
            std::cerr << "La letra ingresada no es válida: " << letra << std::endl;
        }
    }

    archivo.close();
}

void calcularMediana(ArbolAVL<int>& arbolito, const std::string& archivoMediana) {
    // Obtener el recorrido inOrden para tener los elementos ordenados
    std::vector<int> elementos = arbolito.inOrden();
    int n = elementos.size();

    if (n == 0) {
        std::cout << "El árbol está vacío, no hay elementos para calcular la mediana." << std::endl;
        return;
    }

    std::ofstream archivo(archivoMediana);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo de salida: " << archivoMediana << std::endl;
        return;
    }

    std::cout << "\nCálculo de la mediana:" << std::endl;

    // Si la cantidad de elementos es impar
    if (n % 2 != 0) {
        int mediana = elementos[n / 2];
        archivo << "La mediana es: " << mediana << std::endl;
        archivo << "El nivel de la mediana (" << mediana << ") es: " << arbolito.obtenerNivel(mediana) << std::endl;
        std::cout << "La mediana es: " << mediana << std::endl;
    } else {
        // Si la cantidad de elementos es par
        int valor1 = elementos[(n / 2) - 1];
        int valor2 = elementos[n / 2];
        double mediana = (valor1 + valor2) / 2.0;

        archivo << "Los dos valores centrales son: " << valor1 << " y " << valor2 << std::endl;
        archivo << "La mediana es: " << mediana << std::endl;
        archivo << "El nivel del valor central 1 (" << valor1 << ") es: " << arbolito.obtenerNivel(valor1) << std::endl;
        archivo << "El nivel del valor central 2 (" << valor2 << ") es: " << arbolito.obtenerNivel(valor2) << std::endl;
        
        std::cout << "La mediana es: " << mediana << std::endl;
    }

    archivo.close();
}




