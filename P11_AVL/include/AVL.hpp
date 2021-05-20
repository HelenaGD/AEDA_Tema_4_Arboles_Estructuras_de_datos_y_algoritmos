#pragma once

#include <iostream>

#include "arbolbinariobusqueda.hpp"

template<class Clave>
class AVL: public ABB<Clave>{
 public:
  AVL() : ABB<Clave>() {};
  AVL(nodoAVL<Clave>* raiz) : ABB<Clave>(raiz){};
  ~AVL(){};

  void rotacion_II(nodoAVL<Clave>* &nodo) {
    nodoAVL<Clave> nodo1 = nodo->izdo_;
    nodo->izdo_ = nodo1->dcho_;
    nodo1->dcho_ = nodo;
    if (nodo1->bal_ == 1) {
      nodo->bal_ = 0;
      nodo1->bal_ = 0;
    }
    else { // nodo1->bal == 0
      nodo->bal_ = 1;
      nodo1->bal_ = -1;
    }
    nodo = nodo1;
  };

  void rotacion_DD (nodoAVL<Clave>* &nodo) {
    nodoAVL<Clave> nodo1 = nodo->dcho_;
    nodo->dcho_ = nodo1->izdo_;
    nodo1->izdo_ = nodo;
    if (nodo1->bal_ == -1) {
      nodo->bal_ = 0;
      nodo1->bal_ = 0;
    }
    else { // nodo1->bal == 0
      nodo->bal_ = -1;
      nodo1->bal_ = 1;
    }
    nodo = nodo1;
  };

  void insert_re_balancea_izda(nodoAVL<Clave>* &nodo) {
    bool crece;
    switch (nodo->bal_) {
      case -1: nodo->bal_ = 0;
        crece = false;
        break;
      case 0: nodo->bal_ = 1 ;
        break;
      case 1: nodoAVL<Clave>* nodo1 = nodo->izdo_;
        if (nodo1->bal_ == 1)
          rotacion_II(nodo);
        else rotacion_ID(nodo);
          crece = false;
    }
  };

  void insert_re_balancea_dcha (nodoAVL<Clave>* &nodo) {
    bool crece;
    switch (nodo->bal_) {
      case 1: nodo->bal_ = 0;
        crece = false;
        break;
      case 0: nodo->bal_ = -1;
        break;
      case -1: nodoAVL<Clave>* nodo1 = nodo->dcho_;
        if (nodo1->bal_ == -1)
          rotacion_DD(nodo);
        else rotacion_DI(nodo);
          crece = false;
    }
  };

  void inserta_bal( nodoAVL<Clave>* &nodo, nodoAVL<Clave>* nuevo, bool& crece) {
    if (nodo == NULL) {
      nodo = nuevo;
      crece = true;
    }
    else if (nuevo->clave_ < nodo->clave_) {
      inserta_bal(nodo->izdo_,nuevo,crece);
      if (crece) insert_re_balancea_izda(nodo);
    }
    else {
      inserta_bal(nodo->dcho_, nuevo, crece);
      if (crece) insert_re_balancea_dcha(nodo);
    }
  };

  void Insertar(Clave ClaveDada) {
    nodoAVL<Clave> nuevo = nodoAVL( raiz_->bal_, ClaveDada, ClaveDada, 0);
    bool crece = false;
    inserta_bal(nodoBB<Clave>::raiz_, nuevo, crece);
  }

  void elimina_rama( nodoAVL<Clave>* &nodo, Clave& clave_dada, bool& decrece) {
    if (nodo == NULL) return;
      if (clave_dada < nodo->clave_) {
      elimina_rama(nodo->izdo_, clave_dada, decrece);
        if (decrece)
          eliminar_re_balancea_izda(nodo, decrece);
      } else if (clave_dada > nodo->clave_) {
          elimina_rama(nodo->dcho_, clave_dada,decrece);
        if (decrece)
          eliminar_re_balancea_dcha(nodo, decrece);
      } else { // clave_dada == nodo->clave
          nodoAVL<Clave>* eliminado = nodo;
        if (nodo->izdo_ == NULL) {
          nodo = nodo->dcho_;
          decrece = true;
        }
        else if (nodo->dcho_ == NULL) {
          nodo = nodo->izdo_;
          decrece = true;
        }
        else {
          sustituye(eliminado, nodo->izdo_, decrece);
        if (decrece)
          eliminar_re_balancea_izda(nodo, decrece);
        }
        delete eliminado;
    }
  };

  void Eliminar( Clave& clave_dada) {
    bool decrece = false;
    elimina_rama( nodoBB<Clave>::raiz, clave_dada, decrece);
  };

 private:
};