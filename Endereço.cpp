#include "Endereço.hpp"

void Endereco::salvarEndereco() {
    std::ofstream arquivo("enderecos.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Rua: " << rua << "\n";
        arquivo << "Bairro: " << bairro << "\n";
        arquivo << "CEP: " << cep << "\n";
        arquivo << "Número: " << numero << "\n";
        arquivo << "Complemento: " << complemento << "\n";
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
