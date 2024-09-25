  /*Taller 3*/
   //Katheryn Guasca
   //Miguel Laiton
   //Natalia Jiménez
   
    #include <iostream>
    #include "ArbolAVL.h"
    #include "Nodo.h"
    #include <fstream>
    #include <sstream>
    #include <string>

    void abrirArchivo(std::string nombreArchivo, ArbolAVL<int>& arbolito);

    int main(){

        ArbolAVL<int> arbolito;
        std::string nombreArchivo;
        char fin;

        std::cout<<"¡Bienvenido a nuestro taller"<<std::endl;
        std::cout<<"Ingrese el nombre del archivo: ";
        std::cin>>nombreArchivo;

        abrirArchivo(nombreArchivo, arbolito);
        
        std::cout<<"\nImpresión preOrden"<<std::endl;
        arbolito.preOrden();

        std::cout<<std::endl;

        std::cout<<"\nImpresión posOrden"<<std::endl;
        arbolito.posOrden();

        std::cout<<std::endl;
        
        std::cout<<"\nImpresión inOrden"<<std::endl;
        arbolito.inOrden();

        std::cout<<std::endl;

        std::cout<<"\nPresione cualquier tecla para cerrar el programa...";
        std::cin.ignore(); 
        std::cin.get();    

    return 0;
    }

    void abrirArchivo(std::string nombreArchivo, ArbolAVL<int>& arbolito){
        /*Se procede a abrir el archivo,
        en cada línea primero se revisa el primer
        carácter para ver si se inserta o elimina
        */

        /*En el caso de que sea A, se llama a la función del árbol AVL
        para insertar el valor*/

        /*En caso de que sea E, se llama a la función del árbol AVL para
        eliminar x valor*/
        
        std::ifstream archivo(nombreArchivo);
        
        if (!archivo.is_open()){
            std::cerr<<"No fue posible abrir el archivo"<<std::endl;
            return;
        }

        std::string linea;

        while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        char letra;
        int valor;

        ss>>letra>>valor;

        if(letra == 'A'){
            std::cout<<"Se ha agregado: "<<valor<<std::endl;
            arbolito.insertar(valor);  
        }else if (letra == 'E'){
            std::cout<<"Ha sido eliminado: "<<valor<<std::endl;
            arbolito.eliminar(valor);  
        }else{
            std::cerr<<"La letra ingresada no es válida: "<<letra<<std::endl;
        }
    }

        archivo.close();
    }