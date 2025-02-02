#include "Transportadora.hpp"

Transportadora::Transportadora(const std::string &nome, const std::string &endereco)
    : nome(nome), endereco(endereco) {}

void Transportadora::salvarTransportadora() const {
    std::ofstream arquivo("transportadora.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Nome da Transportadora: " << nome << "\n";
        arquivo << "Endereço: " << endereco << "\n";
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
