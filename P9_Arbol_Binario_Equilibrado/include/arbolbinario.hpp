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

  void Podar(nodoB<Clave>* &nodo) {
    if (nodo == NULL) {return;};
    Podar(nodo->izq_);
    Podar(nodo->dcho_);
    delete nodo;
    nodo = NULL;
  }

  bool EsVacio(nodoB<Clave> *nodo) {
    return (nodo == NULL);
  }

  bool EsHoja(nodoB<Clave> *nodo) {
    return ((!nodo->dcho_)&&(!nodo->izq_));
  }

  const int TamRama(nodoB<Clave> *nodo) {
    return (nodo == NULL) ? 0 : (1 + TamRama(nodo->izq_) + TamRama(nodo->dcho_));
  }

  const int Tam() {return TamRama(raiz_);}

  const bool EquilibrioRama(nodoB<Clave> *nodo) {
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

  void InsertaEquilRama (const Clave dato, nodoB<Clave>* nodo) {
    if (TamRama(nodo->izq_) <= TamRama(nodo->dcho_)) {
      if (nodo->izq_ != NULL) {
        InsertaEquilRama(dato, nodo->izq_);
      } else {
        nodo->izq_ = new nodoB<Clave>(dato, NULL, NULL);
      } 
    } else {
      if (nodo->dcho_ != NULL) {
        InsertaEquilRama(dato,nodo->dcho_);
      } else {
        nodo->dcho_ = new nodoB<Clave>(dato, NULL, NULL);
      }
    }
  }

  void InsertaEquil(const Clave dato) {
    if (raiz_ == NULL) {
      raiz_ = new nodoB<Clave>(dato,NULL,NULL);
    } else {
      InsertaEquilRama(dato, raiz_);
    }
  }

  nodoB<Clave>* BuscarRama(nodoB<Clave>* nodo, Clave clave_dada) {
    if (nodo == NULL) {
      return NULL;
    }
    if (clave_dada == nodo->dato_) {
      return nodo;
    } 
    if (clave_dada < nodo->dato_) {
      return BuscarRama(nodo->izq_, clave_dada);
    } else {
      return BuscarRama(nodo->dcho_, clave_dada);
    }
  }

  nodoB<Clave>* Buscar(Clave& clave) {
    return BuscarRama(raiz_, clave);
  }

  void print(nodoB<Clave>* nodo) { //}, int &nivel, int &hijos) {
    std::queue< nodoB<Clave> *> colaNodos;
    int totalNodos = TamRama(raiz_);
    //int techo = log2(totalNodos+1);
    colaNodos.push(raiz_);
    //int pot = 0;
    int nivel = 0;
    int hijos = 0;
    while (colaNodos.size() > 0) {
      int niveles = colaNodos.size();
      std::cout << "Nivel " << nivel << ": ";

      while (niveles > 0) {
        nodoB<Clave>* dummy = colaNodos.front();
        colaNodos.pop();
        //std::cout<<std::setw((niveles==pow(2,pot))?pow(2, (techo-pot)):pow(2, (techo-pot+1)));
        std::cout << "[";
        if (dummy->dato_ == 0) {
          std::cout << ".";
        } else {
          dummy->printDato();
        }
        std::cout << "]";
        if(dummy->izq_ != NULL) {
          colaNodos.push(dummy->izq_);
          hijos++;
        } else if (hijos != 0) {
          colaNodos.push(0);
        }
        if(dummy->dcho_ != NULL) {
          colaNodos.push(dummy->dcho_);
          hijos = 2;
        } else if (hijos != 0) {
          colaNodos.push(0);
          hijos = 0;
        }
        niveles--;
      }

      //pot++;
      std::cout << std::endl;
      nivel++;
    }
}

    /*
    if(nodo != NULL) {
      nivel++;
      if (nodo->izq_) {
        print(nodo->izq_, nivel, hijos);
      }
      if(nodo->dcho_) {
        print(nodo->dcho_, nivel, hijos);
      }
      std::cout << "[";
      nodo->printDato();
      hijos++;
      std::cout << "]";
      if ((nivel == 0) && (hijos == 2)) {
        std::cout << "\n";
        hijos = 0;
      }
    } else {
      if (nivel == 0) {
        std::cout << "[.]\n";
      } else {
        std::cout << "[.]";
      }
    }*/
/*
  void MostrarAB() {
    int nivel = 0;
    int hijos = 0;
    std::cout << "Nivel " << nivel <<": ";
    print(raiz_, nivel, hijos);
  }*/
  void Print() {
    print(raiz_);
  }

 private:
  nodoB<Clave> *raiz_;
};