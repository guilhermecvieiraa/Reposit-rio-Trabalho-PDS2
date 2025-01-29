#ifndef SOLICITACAO_HPP
#define SOLICITACAO_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Motorista.hpp"
#include <list>

using namespace std;

class Solicitacao {
private:
    string veiculo;
    Motorista motorista;
    string endereco;
    double valorFrete;
    string produto;
    static list<Motorista> bancoMotoristas;

public:
    Solicitacao(string veiculo = "", Motorista motorista = Motorista(), string endereco = "", double valorFrete = 0.0, string produto = "");
// corrigido
    void solicitarDadosEntrega();
    void exibirDetalhes() const;
    void salvarEmArquivo();

    static void cadastrarMotorista(const Motorista& m);
    static bool verificarMotorista(const string& nomeMotorista);
};

#endif
