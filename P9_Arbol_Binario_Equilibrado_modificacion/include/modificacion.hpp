#pragma once

#include <iostream>

class coche {
 public:
  coche(){};
  coche(std::string matricula, long numero_de_bastidor, 
  std::string marca, std::string modelo, int ultima_revision, 
  std::string tipo)
  : matricula_(matricula), 
  numero_de_bastidor_(numero_de_bastidor), 
  marca_(marca), 
  modelo_(modelo),
  ultima_revision_(ultima_revision),
  tipo_(tipo) {};

  coche(const coche&){};

  coche& operator = (const coche &p) {
    if (this != &p) {
      this->matricula_ = p.matricula_;
      this->numero_de_bastidor_ = p.numero_de_bastidor_;
      this->marca_ = p.marca_;
      this->modelo_ = p.modelo_;
      this->ultima_revision_ = p.ultima_revision_;
      this->tipo_ = p.tipo_;
    }
    return *this;
  }

  bool operator == (const coche &p) const {
    return ((this->matricula_ == p.matricula_) && 
          (this->numero_de_bastidor_ == p.numero_de_bastidor_) &&
          (this->marca_ == p.marca_) && 
          (this->modelo_ == p.modelo_) &&
          (this->ultima_revision_ == p.ultima_revision_) &&
          (this->tipo_ == p.tipo_));
  }

  void print() {
    std::cout << this->matricula_ << "|" << this->numero_de_bastidor_ 
    << "|" << this->marca_ << "|" << this->modelo_ << "|" << this->ultima_revision_
    << "|" << this->tipo_;
  }

  void Introducir();

  friend std::ostream& operator << (std::ostream &o, coche &p);
  friend std::istream& operator >> (std::istream &i, coche &p);

 private:
  std::string matricula_;
  int numero_de_bastidor_;
  std::string marca_;
  std::string modelo_;
  int ultima_revision_;
  std::string tipo_;
};

void coche::Introducir() {
  std::string cadena_texto;
  int numero;

  std::cout << "\nIntroducir matricula: ";
  std::cin >> cadena_texto; 
  matricula_ = cadena_texto;
  std::cout << "Introducir numero de bastidor: ";
  std::cin >> numero; 
  numero_de_bastidor_ = numero;
  std::cout << "Introducir marca: ";
  std::cin >> cadena_texto; 
  marca_ = cadena_texto;
  std::cout << "Introducir modelo: ";
  std::cin >> cadena_texto; 
  modelo_ = cadena_texto;
  std::cout << "Introducir ultima revision: ";
  std::cin >> numero; 
  ultima_revision_ = numero;
  std::cout << "Tipo: ";
  std::cin >> cadena_texto; 
  tipo_ = cadena_texto;
}

std::ostream& operator << (std::ostream &o, coche &p) {
    o << p.matricula_ << "|" << p.numero_de_bastidor_ 
    << "|" << p.marca_ << "|" << p.modelo_ 
    << "|" << p.ultima_revision_ << "|" << p.tipo_;
    return o;
  }

std::istream& operator >> (std::istream &i, coche &p) {
    std::cout << "\nIntroducir matricula: ";
    i >> p.matricula_;
    std::cout << "Introducir numero de bastidor: ";
    i >> p.numero_de_bastidor_;
    std::cout << "Introducir marca: ";
    i >> p.marca_;
    std::cout << "Introducir modelo: ";
    i >> p.modelo_;
    std::cout << "Introducir ultima revision: ";
    i >> p.ultima_revision_;
    std::cout << "Tipo: ";
    i >> p.tipo_;
    i.ignore();
    return i;
  }