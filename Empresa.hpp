#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include "Endereço.hpp"
#include "Departamento.hpp"
#include "Produto.hpp"
#include "Refeitorio.hpp"
#include <vector>

class Empresa {
public:
    std::string nome;
    Endereco endereco;
    std::string cnpj;
    std::vector<Departamento> departamentos;
    std::vector<Produto> produto; 
    std::vector<Refeitorio> refeitorios;
    void salvarEmpresa();
};

#endif
