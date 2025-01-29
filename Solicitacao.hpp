#ifndef SOLICITACAO_HPP
#define SOLICITACAO_HPP
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Solicitacao {
private:
    string veiculo;
    string motorista;
    string endereco;
    double valorFrete;
    string produto;

public:
    // Para verificar se entrou dados, se nao tiver entrado a construtor da ""
    Solicitacao(string veiculo = "", string motorista = "", string endereco = "", double valorFrete = 0.0, string produto = "");

    void solicitarDados();

    void exibirDetalhes() const;

    void salvarEmArquivo();
};

#endif 