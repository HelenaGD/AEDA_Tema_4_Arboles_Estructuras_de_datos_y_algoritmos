#pragma once

#include <iostream>

#include "arbolbinariobusqueda.hpp"

template<class Clave>
class AVL: public ABB<Clave>{
 protected:
  nodoAVL<Clave>*& root() {return reinterpret_cast<nodoAVL<Clave>*&>(AB<Clave>::root());}
 
 public:
  AVL() : ABB<Clave>() {};
  AVL(nodoAVL<Clave>* raiz) : ABB<Clave>(raiz){};
  ~AVL(){};

  void rotacion_II(nodoAVL<Clave>* &nodo) {
    nodoAVL<Clave>* nodo1 = nodo->izq();
    nodo->izq() = nodo1->dcho();
    nodo1->dcho() = nodo;
    if (nodo1->balance() == 1) {
      nodo->balance() = 0;
      nodo1->balance() = 0;
    }
    else { // nodo1->bal == 0
      nodo->balance() = 1;
      nodo1->balance() = -1;
    }
    nodo = nodo1;
  };

  void rotacion_DD (nodoAVL<Clave>* &nodo) {
    nodoAVL<Clave>* nodo1 = nodo->dcho();
    nodo->dcho() = nodo1->izq();
    nodo1->izq() = nodo;
    if (nodo1->balance() == -1) {
      nodo->balance() = 0;
      nodo1->balance() = 0;
    }
    else { // nodo1->bal == 0
      nodo->balance() = -1;
      nodo1->balance() = 1;
    }
    nodo = nodo1;
  };

  void rotacion_ID (nodoAVL<Clave>* &nodo) {
    nodoAVL<Clave>* nodo1 = nodo->izq();
    nodoAVL<Clave>* nodo2 = nodo1->dcho();
    nodo->izq() = nodo2->dcho();
    nodo2->dcho() = nodo;
    nodo1->dcho() = nodo2->izq();
    nodo2->izq() = nodo1;
    if (nodo2->balance() == -1)
      nodo1->balance() = 1;
    else nodo1->balance() = 0;
      if (nodo2->balance() == 1)
        nodo->balance() = -1;
      else 
        nodo->balance() = 0;
    nodo2->balance() = 0;
    nodo = nodo2;
  }

  void rotacion_DI (nodoAVL<Clave>* &nodo) {
    nodoAVL<Clave>* nodo1 = nodo->dcho();
    nodoAVL<Clave>* nodo2 = nodo1->izq();
    nodo->dcho() = nodo2->izq();
    nodo2->izq() = nodo;
    nodo1->izq() = nodo2->dcho();
    nodo2->dcho() = nodo1;
    if (nodo2->balance() == 1)
      nodo1->balance() = -1;
    else nodo1->balance() = 0;
      if (nodo2->balance() == -1)
        nodo->balance() = 1;
      else 
        nodo->balance() = 0;
    nodo2->balance() = 0;
    nodo = nodo2;
  }

  void insert_re_balancea_izda(nodoAVL<Clave>* &nodo) {
    bool crece;
    switch (nodo->balance()) {
      case -1: nodo->balance() = 0;
        crece = false;
        break;
      case 0: nodo->balance() = 1 ;
        break;
      case 1: {nodoAVL<Clave>* nodo1 = nodo->izq();
        if (nodo1->balance() == 1)
          rotacion_II(nodo);
        else rotacion_ID(nodo);
          crece = false;
      }
    }
  };

  void insert_re_balancea_dcha (nodoAVL<Clave>* &nodo) {
    bool crece;
    switch (nodo->balance()) {
      case 1: nodo->balance() = 0;
        crece = false;
        break;
      case 0: nodo->balance() = -1;
        break;
      case -1: {nodoAVL<Clave>* nodo1 = nodo->dcho();
        if (nodo1->balance() == -1)
          rotacion_DD(nodo);
        else rotacion_DI(nodo);
          crece = false;
      }
    }
  };

  void inserta_bal( nodoAVL<Clave>* &nodo, nodoAVL<Clave>* nuevo, bool& crece) {
    if (nodo == NULL) {
      nodo = nuevo;
      crece = true;
    }
    else if (nuevo->clave_ < nodo->clave_) {
      inserta_bal(nodo->izq(),nuevo,crece);
      if (crece) insert_re_balancea_izda(nodo);
    }
    else {
      inserta_bal(nodo->dcho(), nuevo, crece);
      if (crece) insert_re_balancea_dcha(nodo);
    }
  };

  void Insertar(Clave ClaveDada) {
    nodoAVL<Clave>* nuevo = new nodoAVL<Clave>(AB<Clave>::root()->bal_, ClaveDada, ClaveDada, 0);
    bool crece = false;
    inserta_bal(AB<Clave>::root(), nuevo, crece);
  }

  void elimina_rama( nodoAVL<Clave>* &nodo, Clave& clave_dada, bool& decrece) {
    if (nodo == NULL) return;
      if (clave_dada < nodo->clave_) {
      elimina_rama(nodo->izq(), clave_dada, decrece);
        if (decrece)
          eliminar_re_balancea_izda(nodo, decrece);
      } else if (clave_dada > nodo->clave_) {
          elimina_rama(nodo->dcho(), clave_dada,decrece);
        if (decrece)
          eliminar_re_balancea_dcha(nodo, decrece);
      } else { // clave_dada == nodo->clave
          nodoAVL<Clave>* eliminado = nodo;
        if (nodo->izq() == NULL) {
          nodo = nodo->dcho();
          decrece = true;
        }
        else if (nodo->dcho() == NULL) {
          nodo = nodo->izq();
          decrece = true;
        }
        else {
          sustituye(eliminado, nodo->izq(), decrece);
        if (decrece)
          eliminar_re_balancea_izda(nodo, decrece);
        }
        delete eliminado;
    }
  };

  void sustituye(nodoAVL<Clave>* &eliminado,nodoAVL<Clave>* &sust, bool &decrece) {
    if (sust->dcho() != NULL) {
      sustituye(eliminado, sust->dcho(), decrece);
      if (decrece)
        eliminar_re_balancea_dcha(sust, decrece);
    }
    else {
      //eliminado->Info = sust->Info;
      eliminado->clave_ = sust->clave_;
      eliminado = sust;
      sust = sust->izq();
      decrece = true;
    }
  }

  void Eliminar( Clave& clave_dada) {
    bool decrece = false;
    elimina_rama(AVL<Clave>::root(), clave_dada, decrece);
  };

  void eliminar_re_balancea_izda (nodoAVL<Clave>* &nodo, bool& decrece) {
    switch (nodo->balance()) {
      case -1: {
        nodoAVL<Clave>* nodo1 = nodo->dcho();
        if (nodo1->balance() > 0)
          rotacion_DI(nodo);
        else {
          if (nodo1->balance() == 0)
            decrece = false;
          rotacion_DD(nodo);
        }
        break;
      }
      case 0: 
        nodo->balance() = -1;
        decrece = false;
        break;
      case 1: 
        nodo->balance() = 0;
    }
  }

  void eliminar_re_balancea_dcha (nodoAVL<Clave>* &nodo, bool& decrece) {
    switch (nodo->balance()) {
      case 1: {nodoAVL<Clave>* nodo1 = nodo->izq();
        if (nodo1->balance() < 0)
          rotacion_ID(nodo);
        else {
          if (nodo1->balance() == 0)
            decrece = false;
          rotacion_II(nodo);
        }
        break ;
      }
      case 0: nodo->balance() = 1;
        decrece = false;
      break;
        case -1: nodo->balance() = 0;
    }
  }

 private:
};