#include "Trabalho.hpp"

Trabalho::Trabalho(const std::string &tipo, const std::string &tempoExec, const std::string &detalheTrabalho, 
                   const std::string &custo, const Departamento &departamento)
    : tipo(tipo), tempoExec(tempoExec), detalheTrabalho(detalheTrabalho), custo(custo), departamento(departamento) {}

void Trabalho::salvarTrabalho() const {
    std::ofstream arquivo("trabalho.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Tipo: " << tipo << "\n";
        arquivo << "Tempo de Execução: " << tempoExec << "\n";
        arquivo << "Detalhes do Trabalho: " << detalheTrabalho << "\n";
        arquivo << "Custo: " << custo << "\n";
        arquivo << "Departamento: " << departamento.nome << "\n";  // Supondo que `Departamento` tem um atributo `nome`
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
