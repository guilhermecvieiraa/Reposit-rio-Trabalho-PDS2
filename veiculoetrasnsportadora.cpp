#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Classe Veiculo
class Veiculo {
public:
    string tipoVeiculo;
    string modelo;
    string placa;
    string documento;

    Veiculo(const string &tipo, const string &modelo, const string &placa, const string &documento)
        : tipoVeiculo(tipo), modelo(modelo), placa(placa), documento(documento) {}

    void salvarVeiculo() const {
        ofstream arquivo("veiculos.txt", ios::app);
        if (arquivo.is_open()) {
            arquivo << "Tipo de Veículo: " << tipoVeiculo << "\n";
            arquivo << "Modelo: " << modelo << "\n";
            arquivo << "Placa: " << placa << "\n";
            arquivo << "Documento: " << documento << "\n";
            arquivo << "-----------------------------\n";
            arquivo.close();
        }
    }
};

// Classe Transportadora
class Transportadora {
public:
    string nome;
    string endereco;

    Transportadora(const string &nome, const string &endereco) : nome(nome), endereco(endereco) {}

    void salvarTransportadora() const {
        ofstream arquivo("transportadora.txt", ios::app);
        if (arquivo.is_open()) {
            arquivo << "Nome da Transportadora: " << nome << "\n";
            arquivo << "Endereço: " << endereco << "\n";
            arquivo << "-----------------------------\n";
            arquivo.close();
        }
    }
};

int main() {
    // Informações da transportadora
    string nomeTransportadora, enderecoTransportadora;

    cout << "Digite o nome da transportadora: ";
    getline(cin, nomeTransportadora);

    cout << "Digite o endereço da transportadora: ";
    getline(cin, enderecoTransportadora);

    Transportadora transportadora(nomeTransportadora, enderecoTransportadora);
    transportadora.salvarTransportadora();

    // Adicionar veículos
    char continuar = 's';
    while (continuar == 's') {
        string tipo, modelo, placa, documento;

        cout << "Digite o tipo do veículo: ";
        getline(cin, tipo);

        cout << "Digite o modelo do veículo: ";
        getline(cin, modelo);

        cout << "Digite a placa do veículo: ";
        getline(cin, placa);

        cout << "Digite o documento do veículo: ";
        getline(cin, documento);

        Veiculo veiculo(tipo, modelo, placa, documento);
        veiculo.salvarVeiculo();

        cout << "Deseja adicionar outro veículo? (s/n): ";
        cin >> continuar;
        cin.ignore();
    }

    cout << "Informações salvas com sucesso!" << endl;
    return 0;
}
