#pragma once
#include <iostream>

#define RESET "\033[0m"
#define CYAN "\033[36m"

template<class Clave>
class nodoBB {
 public:
  nodoBB (const Clave &dato, const Clave& clave, nodoBB *izq = NULL, nodoBB *dcho = NULL) 
  : dato_(dato), clave_(clave), izq_(izq), dcho_(dcho) {}

  void printDato() {
    std::cout  << CYAN << dato_ << RESET;
  }

  Clave dato_;
  Clave clave_;
  // Nodos hijos
  nodoBB *izq_;
  nodoBB *dcho_;
};