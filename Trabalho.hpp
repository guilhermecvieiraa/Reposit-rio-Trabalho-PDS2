#ifndef TRABALHO_HPP
#define TRABALHO_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Departamento.hpp"

class Trabalho {
public:
    std::string tipo;
    std::string tempoExec;
    std::string detalheTrabalho;
    std::string custo;
    Departamento departamento;

    Trabalho(const std::string &tipo, const std::string &tempoExec, const std::string &detalheTrabalho, 
             const std::string &custo, const Departamento &departamento);

    void salvarTrabalho() const;
};

#endif
