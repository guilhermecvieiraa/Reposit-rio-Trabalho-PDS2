#include "Gestores.hpp"

Gestores::Gestores(const std::string& nome, const std::string& departamento, int id, const std::string& cargo, const std::string& senha)
    : Funcionario(nome, departamento, id, cargo), senha(senha) {}

void Gestores::setSenha(const std::string& senha) {
    this->senha = senha;
}

std::string Gestores::getSenha() const {
    return senha;
}