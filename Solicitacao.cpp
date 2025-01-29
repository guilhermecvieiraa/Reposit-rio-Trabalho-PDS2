#include "Solicitacao.hpp"
#include <iostream>
#include <fstream>

list<Motorista> Solicitacao::bancoMotoristas; // corrigido 

Solicitacao::Solicitacao(string veiculo, Motorista motorista, string endereco, double valorFrete, string produto) {
    this->veiculo = veiculo;
    this->motorista = motorista;
    this->endereco = endereco;
    this->valorFrete = valorFrete;
    this->produto = produto;
}

void Solicitacao::solicitarDadosEntrega() {
    if (veiculo.empty()) { 
        cout << "Digite o veículo a ser usado para a entrega: ";
        getline(cin, veiculo);
    }

    if (!verificarMotorista(motorista.getNome())) {
        cout << "Motorista não cadastrado! Cadastre o motorista primeiro.\n";
        motorista.solicitarDadosM();
        cadastrarMotorista(motorista);
    }

    if (endereco.empty()) {
        cout << "Digite o endereço de entrega: ";
        getline(cin, endereco);
    }

    if (valorFrete == 0.0) {
        cout << "Digite o valor do frete: ";
        cin >> valorFrete;
        cin.ignore();
    }

    if (produto.empty()) {
        cout << "Digite o produto a ser entregue: ";
        getline(cin, produto);
    }
}

void Solicitacao::exibirDetalhes() const {
    cout << "\n=====  Recibo Solicitação =====\n";
    cout << "Veículo: " << veiculo << endl;
    cout << "Motorista: " << motorista.getNome() << endl;
    cout << "Endereço: " << endereco << endl;
    cout << "Valor do frete: R$ " << valorFrete << endl;
    cout << "Produto: " << produto << endl;
}

void Solicitacao::salvarEmArquivo() {
    ofstream arquivo("solicitacao.txt");

    if (arquivo.is_open()) {
        arquivo << "=== SOLICITACAO DE ENTREGA ===\n";
        arquivo << "Veículo: " << veiculo << "\n";
        arquivo << "Motorista: " << motorista.getNome() << "\n";
        arquivo << "Endereço: " << endereco << "\n";
        arquivo << "Valor do frete: R$ " << valorFrete << "\n";
        arquivo << "Produto: " << produto << "\n";
        arquivo.close();
        cout << "\nDados salvos com sucesso em 'solicitacao.txt'!\n";
    } else {
        cout << "Erro ao criar o arquivo!\n";
    }
}

void Solicitacao::cadastrarMotorista(const Motorista& m) {
    bancoMotoristas.push_back(m);
}

bool Solicitacao::verificarMotorista(const string& nomeMotorista) {
    for (const auto& motorista : bancoMotoristas) {
        if (motorista.getNome() == nomeMotorista) {
            return true;
        }
    }
    return false;
}
