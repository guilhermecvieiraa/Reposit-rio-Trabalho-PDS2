#include "Funcionario.hpp"

void Funcionario::salvarFuncionario() {
    std::ofstream arquivo("funcionarios.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "ID Funcionario " << ID_funcionario << "\n";
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
