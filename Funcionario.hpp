#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>
#include "Cargo.hpp"
#include <vector>

class Funcionario {
    std::string ID_funcionario;
    std::vector<Cargo> cargos;
    void salvarFuncionario();
};

#endif
