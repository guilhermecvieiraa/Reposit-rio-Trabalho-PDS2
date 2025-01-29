#include "Motorista.hpp"

using namespace std;

// Construtor
Motorista::Motorista(string NomeMotorista, int IdadeMotorista, string NumeroCNH, string ValidadeCNH, string TipoCNH) {
    this->NomeMotorista = NomeMotorista;
    this->IdadeMotorista = IdadeMotorista;
    this->NumeroCNH = NumeroCNH;
    this->ValidadeCNH = ValidadeCNH;
    this->TipoCNH = TipoCNH;
}

// Método para solicitar dados
void Motorista::solicitarDadosM() {
    if (NomeMotorista.empty()) { 
        cout << "Digite o nome do motorista a ser cadastrado: ";
        getline(cin, NomeMotorista);
    }

    if (IdadeMotorista == 0) {
        cout << "Digite a idade do motorista: ";
        cin >> IdadeMotorista;
        cin.ignore();  // Limpa o buffer
    }

    if (NumeroCNH.empty()) {
        cout << "Digite os números da CNH: ";
        getline(cin, NumeroCNH);
    }

    if (ValidadeCNH.empty()) {
        cout << "Digite a validade da CNH: ";
        getline(cin, ValidadeCNH);
    }

    if (TipoCNH.empty()) {
        cout << "Digite o tipo da CNH (A,B,C,D): ";
        getline(cin, TipoCNH);
    }
}

// Método para exibir os dados
void Motorista::exibirDados() const {
    cout << "Nome: " << NomeMotorista << endl;
    cout << "Idade: " << IdadeMotorista << endl;
    cout << "Número da CNH: " << NumeroCNH << endl;
    cout << "Validade da CNH: " << ValidadeCNH << endl;
    cout << "Tipo da CNH: " << TipoCNH << endl;
}

// Métodos getter
string Motorista::getNome() const { return NomeMotorista; }
int Motorista::getIdadeMotorista() const { return IdadeMotorista; }
string Motorista::getNumeroCNH() const { return NumeroCNH; }
string Motorista::getValidadeCNH() const { return ValidadeCNH; }
string Motorista::getTipoCNH() const { return TipoCNH; }
