#ifndef TRANSPORTADORA_HPP
#define TRANSPORTADORA_HPP

#include <iostream>
#include <fstream>
#include <string>

class Transportadora {
public:
    std::string nome;
    std::string endereco;

    Transportadora(const std::string &nome, const std::string &endereco);

    void salvarTransportadora() const;
};

#endif
