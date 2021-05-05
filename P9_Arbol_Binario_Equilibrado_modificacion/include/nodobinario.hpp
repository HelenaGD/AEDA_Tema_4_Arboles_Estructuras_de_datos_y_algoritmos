#pragma once

#define RESET "\033[0m"
#define CYAN "\033[36m"

template<class Clave>
class nodoB {
 public:
 /*
  nodoB (const Clave dato, nodoB *izq = NULL, nodoB *dcho = NULL) 
  : dato_(dato), izq_(izq), dcho_(dcho) {}*/
  nodoB (const Clave &dato, nodoB *izq = NULL, nodoB *dcho = NULL) {
    dato_ = dato;
    izq_ = izq;
    dcho_ = dcho;
  }

  void printDato() {
    std::cout << CYAN << dato_ << RESET;
  }

  Clave dato_;
  // Nodos hijos
  nodoB *izq_;
  nodoB *dcho_;
};