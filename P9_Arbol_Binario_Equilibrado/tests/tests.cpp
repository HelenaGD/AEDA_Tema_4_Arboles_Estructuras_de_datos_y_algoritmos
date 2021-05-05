#include "arbolbinario.hpp"
#include "nodobinario.hpp"

#include <vector>
#include "iostream"

using Clave = int;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

using Clave = int;

class Testclass {
 public:
  AB<Clave> *arbol = new AB<Clave>;
  
};

int main(void) {
  Testclass test;
  system("clear");
  std::cout << "Test Funcion Insercion: ";
  std::cout << ((test.TestInsercion()) ? GREEN"ok"RESET : RED"fail"RESET) << std::endl; 
  system("sleep 1");

  

  return 0;
}