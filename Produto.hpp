#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>

class Produto {
public:
    std::string nome;
    float custo;
    std::string dataFabricacao;
    int codigo;

    void salvarProduto(const std::string& nomeEmpresa);
};

#endif
