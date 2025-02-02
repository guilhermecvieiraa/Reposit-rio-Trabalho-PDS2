#ifndef DEPARTAMENTO_HPP
#define DEPARTAMENTO_HPP

#include <iostream>
#include <vector>
#include "Trabalho.hpp"

class Departamento {
public:
    std::string nome;
    std::string gestor;    
    std::vector<Trabalho> trabalhos;

    void salvarDepartamento();
};

#endif // DEPARTAMENTO_HPP