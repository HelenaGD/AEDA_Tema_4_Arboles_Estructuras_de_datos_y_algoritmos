#pragma once

#include <iostream>

#include "arbolbinario.hpp"

template<class Clave>
class ABB: public AB<Clave>{
 private:
  bool traza_;
 protected:
  nodoAVL<Clave>*& root() {return reinterpret_cast<nodoAVL<Clave>*&>(AB<Clave>::root());}
  bool traza() {return traza_;}

 public:
  ABB() : AB<Clave>() {};
  ABB(nodoBB<Clave>* raiz) : AB<Clave>(raiz){};
  ~ABB(){};
  //ABB(){};

  void traza(bool seleccion) {
    traza_ = seleccion;
  }

  nodoBB<Clave>* BuscarRama(nodoBB<Clave>* nodo, Clave clave_dada) {
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

  void Insertar(Clave& clave_dada) {
    InsertarRama(AB<Clave>::root(), clave_dada);
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

  virtual void Eliminar(Clave& clave_dada) = 0;

};