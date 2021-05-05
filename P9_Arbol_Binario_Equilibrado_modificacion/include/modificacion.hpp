#pragma once

#include <iostream>

class modificacion {
 public:
  modificacion(){};
  modificacion(std::string color, std::string potencia, std::string marca)
  : color_(color), potencia_(potencia), marca_(marca){};

  modificacion(const modificacion&){};

  modificacion& operator = (const modificacion &p) {
    if (this != &p) {
      this->color_ = p.color_;
      this->marca_ = p.marca_;
      this->potencia_ = p.potencia_;
    }
    return *this;
  }

  bool operator == (const modificacion &p) const {
    return ((this->color_ == p.color_) && (this->marca_ == p.marca_) && (this->potencia_ == p.potencia_));
  }

  void print() {
    std::cout << color_ << "|" << potencia_ << "|" << marca_;
  }

  friend std::ostream& operator << (std::ostream &o, modificacion &p);
  friend std::istream& operator >> (std::istream &i, modificacion &p);

 private:
  std::string color_;
  std::string potencia_;
  std::string marca_;
};

std::ostream& operator << (std::ostream &o, modificacion &p) {
    o << p.color_ << "|" << p.potencia_ << "|" << p.marca_;
    return o;
  }

std::istream& operator >> (std::istream &i, modificacion &p) {
    std::cout << "\nIntroducir color: ";
    i >> p.color_;
    std::cout << "Introducir potencia: ";
    i >> p.potencia_;
    std::cout << "Introducir marca: ";
    i >> p.marca_;
    i.ignore();
    return i;
  }