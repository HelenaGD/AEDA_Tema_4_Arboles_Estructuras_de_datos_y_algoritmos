#pragma once

template<class Clave>
class nodoB {
 public:
  nodoB (const int dato, nodoB *izq = NULL, nodoB *dcho = NULL) 
  : dato_(dato), izq_(izq), dcho_(dcho) {}

  void printDato() {
    std::cout << dato_;
  }

  Clave dato_;
  // Nodos hijos
  nodoB *izq_;
  nodoB *dcho_;
};