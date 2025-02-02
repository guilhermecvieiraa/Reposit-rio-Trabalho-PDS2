#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <iostream>
#include <fstream>
#include <string>

class Veiculo {
public:
    std::string tipoVeiculo;
    std::string modelo;
    std::string placa;
    std::string documento;

    Veiculo(const std::string &tipo, const std::string &modelo, const std::string &placa, const std::string &documento);

    void salvarVeiculo() const;
};

#endif
