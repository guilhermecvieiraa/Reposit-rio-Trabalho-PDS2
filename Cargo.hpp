#ifndef CARGO_HPP
#define CARGO_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Funcionario.hpp"

class Funcionario;  // Forward declaration of Funcionario class

class Cargo {
public:
    std::string nomeDoCargo;
    float salario;
    Funcionario funcionario;  // Associado a um funcionário

    Cargo(const std::string &nomeDoCargo, float salario, const Funcionario &funcionario);

    void salvarCargo() const;
};

#endif
