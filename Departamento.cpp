#include "Departamento.hpp"
#include "Funcionario.hpp"
#include <fstream>

void Departamento::salvarDepartamento() {
    std::ofstream arquivo("departamento.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Nome: " << nome << "\n";
        arquivo << "Gestor: " << gestor << "\n";
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
