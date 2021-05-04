#include <iostream>

#include "nodobinario.hpp"
#include "arbolbinario.hpp"

#define INFINITO 999999

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"

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
  arbol->Print();

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
        std::cout << "\nInsertar: " << CYAN << clave_introducida << "\n" << RESET;
        arbol->Print();
        break; 
      case 2:
        std::cout << "Introduzca la clave a buscar: ";
        std::cin >> clave_introducida;
        std::cout << "Buscando: " << CYAN << clave_introducida << "\n" << RESET;
        if(arbol->Buscar(clave_introducida)) {
          std::cout << GREEN << "Se ha encontrado una coincidencia\n" << RESET;
        } else {
          std::cout << RED << "No se han encontrado coincidencias\n" << RESET;
        }
        break;
    }
  }
  return 0;
}