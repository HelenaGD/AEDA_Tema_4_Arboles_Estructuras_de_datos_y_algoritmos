#pragma once

#include <iostream>

#include "arbolbinario.hpp"

template<class Clave>
class ABB: public AB<Clave>{
 public:
  //ABB() : AB() {};

  nodoBB<Clave>* BuscarRama(nodoBB<Clave>* nodo, Clave clave_dada) {
    nodoBB<Clave>* aux;
    if (nodo == NULL) {
      return NULL;
    } else {
      if (clave_dada == nodo->clave_) {
        return nodo;
      } else {
        if (clave_dada < nodo->clave_) {
          return BuscarRama(nodo->izq_, clave_dada);
        } else {
          return BuscarRama(nodo->dcho_, clave_dada);
        }
      }
    }
  };

  void Insertar(const Clave& clave_dada) {
    InsertarRama(raiz_, clave_dada);
  }

  void InsertarRama(nodoBB<Clave>* &nodo, Clave& clave_dada) {
    if (nodo == NULL) {
      nodo = new nodoBB(clave_dada, clave_dada);
    } else if (clave_dada < nodo->clave_) {
      InsertarRama(nodo->izq_, clave_dada);
    } else {
      InsertarRama(nodo->dcho_, clave_dada);
    }
  }

};