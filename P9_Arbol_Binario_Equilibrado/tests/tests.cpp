#include "funciones.hpp"

#include <vector>
#include "iostream"

using Clave = int;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"

class Testclass {
 public:
  std::vector<Clave> secuencia_correcta = {1, 2, 3, 6, 8};
  std::vector<Clave> secuencia_desordenada = {6, 8, 2, 1, 3};

  bool TestInsercion() {
    int size_secuencia = 5;
    std::vector<Clave>* secuencia = new std::vector<Clave>;
    secuencia->resize(size_secuencia);
    *secuencia = secuencia_desordenada;

    Insercion(secuencia, size_secuencia, false);
    return (*secuencia == secuencia_correcta);
  }

  bool TestQuickSort() {
    int size_secuencia = 5;
    std::vector<Clave>* secuencia = new std::vector<Clave>;
    secuencia->resize(size_secuencia);
    *secuencia = secuencia_desordenada;

    QuickSort(secuencia, size_secuencia, false);
    return (*secuencia == secuencia_correcta);
  }

  bool TestShellSort() {
    int size_secuencia = 5;
    std::vector<Clave>* secuencia = new std::vector<Clave>;
    secuencia->resize(size_secuencia);
    *secuencia = secuencia_desordenada;

    ShellSort(secuencia, size_secuencia, false);
    return (*secuencia == secuencia_correcta);
  }

  bool TestSeleccion() {
    int size_secuencia = 5;
    std::vector<Clave>* secuencia = new std::vector<Clave>;
    secuencia->resize(size_secuencia);
    *secuencia = secuencia_desordenada;

    Seleccion(secuencia, size_secuencia, false);

    return (*secuencia == secuencia_correcta);
  }

  bool TestMergeSort() {
    int size_secuencia = 5;
    std::vector<Clave>* secuencia = new std::vector<Clave>;
    secuencia->resize(size_secuencia);
    *secuencia = secuencia_desordenada;

    MergeSort(secuencia, size_secuencia, false);
    return (*secuencia == secuencia_correcta);
  }

  bool TestHeapSort() {
    int size_secuencia = 5;
    std::vector<Clave>* secuencia = new std::vector<Clave>;
    secuencia->resize(size_secuencia);
    *secuencia = secuencia_desordenada;

    HeapSort(secuencia, size_secuencia, false);

    return (*secuencia == secuencia_correcta);
  }
};

int main(void) {
  Testclass test;
  system("clear");
  std::cout << "Test Funcion Insercion: ";
  std::cout << ((test.TestInsercion()) ? GREEN"ok"RESET : RED"fail"RESET) << std::endl; 
  system("sleep 1");

  std::cout << "Test Funcion QuickSort: ";
  std::cout << ((test.TestQuickSort()) ? GREEN"ok"RESET : RED"fail"RESET) << std::endl; 
  system("sleep 1");

  std::cout << "Test Funcion ShellSort: ";
  std::cout << ((test.TestShellSort()) ? GREEN"ok"RESET : RED"fail"RESET) << std::endl;  
  system("sleep 1");

  std::cout << "Test Funcion Seleccion: ";
  std::cout << ((test.TestSeleccion()) ? GREEN"ok"RESET : RED"fail"RESET) << std::endl;  
  system("sleep 1");

  std::cout << "Test Funcion MergeSort: ";
  std::cout << ((test.TestMergeSort()) ? GREEN"ok"RESET : RED"fail"RESET) << std::endl;  
  system("sleep 1");

  std::cout << "Test Funcion HeapSort: ";
  std::cout << ((test.TestHeapSort()) ? GREEN"ok"RESET : RED"fail"RESET) << std::endl;  
  system("sleep 1");

  return 0;
}