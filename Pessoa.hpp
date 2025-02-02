#ifndef PESSOA_HPP
#define PESSOA_HPP

#include "Endereço.hpp"
#include<vector>

class Pessoa {
private:
    std::string cpf;
    std::string telefone;

    bool validarCPF(const std::string& cpf);
    bool validarNumero(const std::string& numero);

public:
    std::string nome;
    std::vector<Endereco> Endereco;
    std::string cpf;
    std::string telefone;

    void salvarPessoa();
};

#endif
