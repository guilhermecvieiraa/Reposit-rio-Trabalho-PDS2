#include "Pessoa.hpp"
#include <fstream>
#include <cctype>

bool Pessoa::validarCPF(const std::string& cpf) {
    if (cpf.length() != 11) return false;
    for (char c : cpf) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool Pessoa::validarNumero(const std::string& numero) {
    if (numero.length() != 11) return false;
    for (char c : numero) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void Pessoa::salvarPessoa() {
    std::ofstream arquivo("pessoas.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Nome: " << nome << "\n";
        arquivo << "Endereço: " << endereco.rua << ", " << endereco.numero << " - " << endereco.bairro << "\n";
        arquivo << "CPF: " << cpf << "\n";
        arquivo << "Telefone: " << telefone << "\n";
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
