#include "arbolbinario.hpp"
#include "nodobinario.hpp"
#include "arbolbinariobusqueda.hpp"

#include <assert.h>
#include <iostream>

using Clave = int;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

using Clave = int;

Clave RAIZ = 50;
Clave HIJO1 = 25;
Clave HIJO1_1 = 10;
Clave HIJO1_2 = 30;
Clave HIJO2 = 75;
Clave HIJO2_1 = 60;
Clave HIJO2_2 = 80;

Clave no_incluido = 99;

class Testclass {
 public:
  /*
                  [raiz]
              [hijo1][hijo2]
  [hijo1_1][hijo_1_2][hijo2_1][hijo2_2]
                   [50]
                 [25][75]
             [10][30][60][80]
  */
  nodoBB<Clave> *hijo1_1_ = new nodoBB<Clave>(HIJO1_1,HIJO1_1); 
  nodoBB<Clave> *hijo1_2_ = new nodoBB<Clave>(HIJO1_2,HIJO1_2); 
  nodoBB<Clave> *hijo1_ = new nodoBB<Clave>(HIJO1,HIJO1, hijo1_1_,hijo1_2_); 
  nodoBB<Clave> *hijo2_1_ = new nodoBB<Clave>(HIJO2_1,HIJO2_1);
  nodoBB<Clave> *hijo2_2_ = new nodoBB<Clave>(HIJO2_2,HIJO2_2);
  nodoBB<Clave> *hijo2_ = new nodoBB<Clave>(HIJO2,HIJO2, hijo2_1_,hijo2_2_);
  nodoBB<Clave> *raiz_ = new nodoBB<Clave>(RAIZ,RAIZ,hijo1_, hijo2_); 
  AB<Clave> *arbol_ = new ABB<Clave>(raiz_);

  void TestInsertar() {
    AB<Clave> *arbol = new ABB<Clave>();
    arbol->Insertar(RAIZ);
    arbol->Insertar(HIJO1);
    arbol->Insertar(HIJO2);
    arbol->Insertar(HIJO2_1);
    arbol->Insertar(HIJO2_2);
    arbol->Insertar(HIJO1_1);
    arbol->Insertar(HIJO1_2);

    assert(arbol->getraiz()->dato_ == RAIZ);
    assert(arbol->getraiz()->izq_->dato_ == HIJO1);
    assert(arbol->getraiz()->izq_->izq_->dato_ == HIJO1_1);
    assert(arbol->getraiz()->izq_->dcho_->dato_ == HIJO1_2);
    assert(arbol->getraiz()->dcho_->dato_ == HIJO2);
    assert(arbol->getraiz()->dcho_->izq_->dato_ == HIJO2_1);
    assert(arbol->getraiz()->dcho_->dcho_->dato_ == HIJO2_2);
  }

  void TestBuscar() {
    assert(arbol_->Buscar(RAIZ) == true);
    assert(arbol_->Buscar(HIJO1) == true);
    assert(arbol_->Buscar(HIJO1_1) == true);
    assert(arbol_->Buscar(HIJO1_2) == true);
    assert(arbol_->Buscar(HIJO2) == true);
    assert(arbol_->Buscar(HIJO2_1) == true);
    assert(arbol_->Buscar(HIJO2_2) == true);

    assert(arbol_->Buscar(no_incluido) == false);

  }
  
};

int main(void) {
  Testclass test;
  system("clear");

  std::cout << CYAN << "~~~~~ T E S T S ~~~~~\n" << RESET;

  std::cout << "Test Funcion Insercion: ";
  //try {
    test.TestInsertar();
  /* } catch(_exception e) {
    std::cout << RED << "FAIL\n" << RESET;
    //std::cerr << e.what() << std::endl;
    return -1;
  } */
  std::cout << GREEN << "OK\n" << RESET;
  system("sleep 0.5");

  std::cout << "Test Funcion Busqueda: ";
  //try {
    test.TestBuscar();
  /* } catch(std::exception &e) {
    std::cout << RED << "FAIL\n" << RESET;
    std::cerr << e.what() << std::endl;
    return -2;
  } */
  std::cout << GREEN << "OK\n" << RESET;
  system("sleep 0.5");

  return 0;
}