#ifndef REFEITORIO_HPP
#define REFEITORIO_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Empresa.hpp"

class Refeitorio {
public:
    std::string localizacao;
    std::string cozinheira_chefe;
    std::string comodidade;
    std::string horario_de_funcionamento;
    Empresa empresa;

    Refeitorio(const std::string &localizacao, const std::string &cozinheira_chefe, 
               const std::string &comodidade, const std::string &horario, const Empresa &empresa);

    void salvarRefeitorio() const;
};

#endif
