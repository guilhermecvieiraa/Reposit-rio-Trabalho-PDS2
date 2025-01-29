#include "Funcionario.hpp"

Funcionario::Funcionario(const std::string& nome, const std::string& departamento, int id, const std::string& cargo)
    : nome(nome), departamento(departamento), idFuncionario(id), cargo(cargo) {}

void Funcionario::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Funcionario::getNome() const {
    return nome;
}

void Funcionario::setDepartamento(const std::string& departamento) {
    this->departamento = departamento;
}

std::string Funcionario::getDepartamento() const {
    return departamento;
}

void Funcionario::setIdFuncionario(int id) {
    idFuncionario = id;
}

int Funcionario::getIdFuncionario() const {
    return idFuncionario;
}

void Funcionario::setCargo(const std::string& cargo) {
    this->cargo = cargo;
}

std::string Funcionario::getCargo() const {
    return cargo;
}
