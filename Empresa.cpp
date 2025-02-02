#include "Empresa.hpp"
#include <fstream>

void Empresa::salvarEmpresa() {
    std::ofstream arquivo("empresa.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Nome: " << nome << "\n";
        arquivo << "Endereço: " << endereco.rua << ", " << endereco.numero << " - " << endereco.bairro << "\n";
        arquivo << "CNPJ: " << cnpj << "\n";
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
