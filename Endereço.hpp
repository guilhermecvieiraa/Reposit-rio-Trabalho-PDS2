#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#include <iostream>
#include <fstream>

class Endereco {
public:
    std::string rua;
    std::string bairro;
    std::string cep;
    int numero;
    std::string complemento;

    void salvarEndereco();
};

#endif
