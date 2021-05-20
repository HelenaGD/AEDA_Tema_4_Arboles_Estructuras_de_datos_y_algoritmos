#pragma once

#include <iostream>

#include "nodobinario.hpp"

template<class Clave>
class nodoAVL: public nodoBB<Clave>{
 private:
  int bal_;
 public:
  nodoAVL() : nodoBB<Clave>() {};
  nodoAVL (const int bal, const Clave &dato, const Clave& clave, nodoBB<Clave> *izq = NULL, nodoBB<Clave> *dcho = NULL) : nodoBB<Clave>(dato, clave, izq, dcho) {
    bal_ = bal;
  }
  //nodoAVL(nodoBB<Clave>* raiz) : AB<Clave>(raiz){};
  ~nodoAVL(){};
};