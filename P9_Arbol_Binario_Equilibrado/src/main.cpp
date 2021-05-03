#include <iostream>

#include "nodobinario.hpp"
#include "arbolbinario.hpp"

#define INFINITO 999999
#define RESET "\033[0m"
#define BOLD "\033[1m"

int RecogerCantidadPositiva(int cantidad_max = INFINITO, int cantidad_min = 0) {
	int cantidad = 0;
	do {
		std::cout << BOLD << "\nInput: " << RESET;
		std::cin >> cantidad;
	} while ((cantidad <= cantidad_min) && (cantidad > cantidad_max));
  std::cout << std::endl;
	return cantidad;
}

using Clave = int;

int main() {
  int opcion = -1;
  // Generar Ab vacío
  AB<Clave> *arbol = new AB<Clave>;
  std::cout << "\nArbol vacio\n";
  //arbol->MostrarAB();

  Clave clave_introducida;

  // Menú
  while (opcion != 0) {
    std::cout << BOLD << "\n-----MENU-----\n" << RESET;
    std::cout << "[0] Salir\n"
              << "[1] Insertar Clave\n"
              << "[2] Buscar Clave\n";
    opcion = RecogerCantidadPositiva(2);
    switch (opcion) {
      case 0:
        std::cout << "Saliendo del programa\n";
        break;
      case 1:
        std::cout << "Introduzca la clave a insertar: ";
        std::cin >> clave_introducida;
        arbol->InsertaEquil(clave_introducida);
        std::cout << "\nInsertar: " << clave_introducida << "\n";
        arbol->Print();
        break; 
      case 2:
        std::cout << "Introduzca la clave a buscar: ";
        std::cin >> clave_introducida;
        break;
    }

     // Mostrar Árbol

  
  }
  return 0;
}