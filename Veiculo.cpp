#include "Veiculo.hpp"

Veiculo::Veiculo(const std::string &tipo, const std::string &modelo, const std::string &placa, const std::string &documento)
    : tipoVeiculo(tipo), modelo(modelo), placa(placa), documento(documento) {}

void Veiculo::salvarVeiculo() const {
    std::ofstream arquivo("veiculos.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << "Tipo de Veículo: " << tipoVeiculo << "\n";
        arquivo << "Modelo: " << modelo << "\n";
        arquivo << "Placa: " << placa << "\n";
        arquivo << "Documento: " << documento << "\n";
        arquivo << "-----------------------------\n";
        arquivo.close();
    }
}
