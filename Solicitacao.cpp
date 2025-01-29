#include "Solicitacao.hpp" 

//construtora
Solicitacao::Solicitacao(string veiculo, string motorista, string endereco, double valorFrete, string produto) {
    this->veiculo = veiculo;
    this->motorista = motorista;
    this->endereco = endereco;
    this->valorFrete = valorFrete;
    this->produto = produto;
}
//para caso nao for passado dados criei essa funcao para perguntar e pedir o dado
void Solicitacao::solicitarDados() {
    if (veiculo.empty()) { 
        cout << "Digite o veículo a ser usado para a entrega: ";
        getline(cin, veiculo);
    }

    if (motorista.empty()) {
        cout << "Digite o nome do motorista: ";
        getline(cin, motorista);
    }

    if (endereco.empty()) {
        cout << "Digite o endereço de entrega: ";
        getline(cin, endereco);
    }

    if (valorFrete == 0.0) {
        cout << "Digite o valor do frete: ";
        cin >> valorFrete;
        cin.ignore(); // fiz essa pq é bom para evitar problema com o getline 
    }

    if (produto.empty()) {
        cout << "Digite o produto a ser entregue: ";
        getline(cin, produto);
    }
}

void Solicitacao::exibirDetalhes() const {
        cout << "\n=====  Recibo Solicitação Numero 2 =====\n";
        cout << "Veículo: " << veiculo << endl;
        cout << "Motorista: " << motorista << endl;
        cout << "Endereço: " << endereco << endl;
        cout << "Valor do frete: R$ " << valorFrete << endl;
        cout << "Produto: " << produto << endl;
    }

void Solicitacao::salvarEmArquivo() {
        ofstream arquivo("solicitacao.txt"); // Abre/cria o arquivo

        if (arquivo.is_open()) {
            arquivo << "=== SOLICITACAO DE ENTREGA ===\n";
            arquivo << "Veículo: " << veiculo << "\n";
            arquivo << "Motorista: " << motorista << "\n";
            arquivo << "Endereço: " << endereco << "\n";
            arquivo << "Valor do frete: R$ " << valorFrete << "\n";
            arquivo << "Produto: " << produto << "\n";
            arquivo.close(); // Fecha o arquivo
            cout << "\nDados salvos com sucesso em 'solicitacao.txt'!\n";
        } else {
            cout << "Erro ao criar o arquivo!\n";
        }
    }



