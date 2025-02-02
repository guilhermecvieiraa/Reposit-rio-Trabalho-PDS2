#include "Cargo.hpp"

Cargo::Cargo(const std::string &nomeDoCargo, float salario, const Funcionario &funcionario)
    : nomeDoCargo(nomeDoCargo), salario(salario), funcionario(funcionario) {}

void Cargo::salvarCargo() const {
    std::ofstream arquivo("cargos.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Nome do Cargo: " << nomeDoCargo << "\n";
        arquivo << "Salário: " << salario << "\n";
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
