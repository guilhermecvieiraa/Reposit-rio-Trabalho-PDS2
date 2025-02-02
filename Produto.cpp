#include "Produto.hpp"
#include <fstream>

void Produto::salvarProduto(const std::string& nomeEmpresa) {
    std::ofstream arquivo("produtos.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Empresa: " << nomeEmpresa << "\n";
        arquivo << "Produto: " << nome << "\n";
        arquivo << "Custo: " << custo << "\n";
        arquivo << "Data de Fabricação: " << dataFabricacao << "\n";
        arquivo << "Código: " << codigo << "\n";
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
