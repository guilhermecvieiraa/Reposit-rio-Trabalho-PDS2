#include "Refeitorio.hpp"

Refeitorio::Refeitorio(const std::string &localizacao, const std::string &cozinheira_chefe, 
                       const std::string &comodidade, const std::string &horario, const Empresa &empresa)
    : localizacao(localizacao), cozinheira_chefe(cozinheira_chefe), 
      comodidade(comodidade), horario_de_funcionamento(horario), empresa(empresa) {}

void Refeitorio::salvarRefeitorio() const {
    std::ofstream arquivo("refeitorio.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Localização: " << localizacao << "\n";
        arquivo << "Cozinheira Chefe: " << cozinheira_chefe << "\n";
        arquivo << "Comodidade: " << comodidade << "\n";
        arquivo << "Horário de Funcionamento: " << horario_de_funcionamento << "\n";
        arquivo << "Empresa: " << empresa.nome << "\n";  // Assumindo que `Empresa` tem um atributo `nome`
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
