#pragma once

#include <queue>
#include <cmath>
#include <iomanip>

#include "nodobinario.hpp"

template<class Clave>
class AB {
 public:
  AB():raiz_(NULL){}
  ~AB() {Podar(raiz_);}

  void Podar(nodoBB<Clave>* &nodo) {
    if (nodo == NULL) {return;};
    Podar(nodo->izq_);
    Podar(nodo->dcho_);
    delete nodo;
    nodo = NULL;
  }

  bool EsVacio(nodoBB<Clave> *nodo) {
    return (nodo == NULL);
  }

  bool EsHoja(nodoBB<Clave> *nodo) {
    return ((!nodo->dcho_)&&(!nodo->izq_));
  }

  const int TamRama(nodoBB<Clave> *nodo) {
    return (nodo == NULL) ? 0 : (1 + TamRama(nodo->izq_) + TamRama(nodo->dcho_));
  }

  const int Tam() {return TamRama(raiz_);}

  const int AltN(nodoBB<Clave>* nodo) {
    if (nodo == NULL) {
      return 0;
    }

    int alt_i = AltN(nodo->izq_);
    int alt_d = AltN(nodo->dcho_);

    if (alt_d > alt_i) {
      return ++alt_d;
    } else {
      return ++alt_i;
    }
  }

  const int Alt() {return AltN(raiz_);}

  const bool EquilibrioRama(nodoBB<Clave> *nodo) {
    if (nodo == NULL) return true;
    int eq = TamRama(nodo->izq_) - TamRama(nodo->dcho_);
    switch (eq) {
      case -1:
      case 0:
      case 1:
        return (EquilibrioRama(nodo->izq_)&&(EquilibrioRama(nodo->dcho_)));
      default:
        return false;
    }
  }

  const bool Equilibrado() {
    return EqulibrioRama(raiz_);
  }

  void InsertaEquilRama (const Clave dato, nodoBB<Clave>* nodo) {
    if (TamRama(nodo->izq_) <= TamRama(nodo->dcho_)) {
      if (nodo->izq_ != NULL) {
        InsertaEquilRama(dato, nodo->izq_);
      } else {
        nodo->izq_ = new nodoBB<Clave>(dato, NULL, NULL);
      } 
    } else {
      if (nodo->dcho_ != NULL) {
        InsertaEquilRama(dato,nodo->dcho_);
      } else {
        nodo->dcho_ = new nodoBB<Clave>(dato, NULL, NULL);
      }
    }
  }

  void InsertaEquil(const Clave& dato) {
    if (raiz_ == NULL) {
      raiz_ = new nodoBB<Clave>(dato,NULL,NULL);
    } else {
      InsertaEquilRama(dato, raiz_);
    }
  }

  virtual void Insertar(Clave& clave_dada) = 0;
  //virtual void InsertarRama(nodoBB<Clave>* nodo, Clave& clave_dada)  = 0;

  virtual nodoBB<Clave>* BuscarRama(nodoBB<Clave>* nodo, Clave clave_dada) = 0;
/*
  nodoBB<Clave>* BuscarRama(nodoBB<Clave>* nodo, Clave clave_dada) {
    nodoBB<Clave>* aux;
    if (nodo == NULL) {
      return NULL;
    } else {
      if (clave_dada == nodo->dato_) {
        return nodo;
      } else {
        aux = BuscarRama(nodo->izq_, clave_dada);
        /*
        if (clave_dada < nodo->dato_) {
          return BuscarRama(nodo->izq_, clave_dada);
        } else {
          return BuscarRama(nodo->dcho_, clave_dada);
        }//
      }
      if (aux == NULL) {
        return BuscarRama(nodo->dcho_, clave_dada);
      } else {
        return aux;
      }
    }
  }*/

  nodoBB<Clave>* BuscarClave(Clave& clave) {
    return BuscarRama(raiz_, clave);
  }

  bool Buscar(const Clave& clave) {
    return !(BuscarRama(raiz_, clave) == NULL);
  }

  void printNivel(nodoBB<Clave>* nodo, int nivel, nodoBB<Clave>* nodo_anterior) {
    if ((nodo == NULL)) {
      if (nivel < 2) {
        std::cout << "[.]";
        return;
      } else {
        return;
      }
    } 

    if (nivel == 1) {
      std::cout << "[";
      nodo->printDato();
      std::cout << "]";
    } else if (nivel > 1) {
      printNivel(nodo->izq_, nivel-1, nodo);
      printNivel(nodo->dcho_, nivel-1, nodo);
    }
  }

  void print (nodoBB<Clave>* nodo) {
    int h = Alt();
    nodoBB<Clave>* aux(0);
    for (int i = 1; i <= h+1; ++i) {
      std::cout << "Nivel " << i-1 << ": ";
      printNivel(nodo,i, aux);
      std::cout << "\n";
    }
  }

  void Print() {
    print(raiz_);
  }

 protected:
  nodoBB<Clave> *raiz_;
};