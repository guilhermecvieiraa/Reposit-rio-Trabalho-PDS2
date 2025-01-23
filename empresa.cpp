#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Class for Product
class Produto {
public:
    string nome;
    double custo;
    string dataFabricacao;
    int codigo;

    void cadastrarProduto() {
        cout << "\nCadastro de Produto:\n";
        cout << "Nome do Produto: ";
        getline(cin, nome);
        cout << "Custo: ";
        cin >> custo;
        cin.ignore(); // Clear input buffer
        cout << "Data de Fabricação (dd/mm/aaaa): ";
        getline(cin, dataFabricacao);
        cout << "Código: ";
        cin >> codigo;
        cin.ignore(); // Clear input buffer

        // Save to file
        ofstream file("produtos.txt", ios::app);
        if (file.is_open()) {
            file << "Produto: " << nome << "\n";
            file << "Custo: " << custo << "\n";
            file << "Data de Fabricação: " << dataFabricacao << "\n";
            file << "Código: " << codigo << "\n";
            file << "------------------------\n";
            file.close();
            cout << "Produto salvo com sucesso em produtos.txt!\n";
        } else {
            cerr << "Erro ao abrir o arquivo produtos.txt!\n";
        }
    }
};

// Class for Company
class Empresa {
public:
    string nome;
    string endereco;
    string cnpj;
    vector<Produto> produtos;

    void cadastrarEmpresa() {
        cout << "\nCadastro de Empresa:\n";
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Endereço: ";
        getline(cin, endereco);
        cout << "CNPJ: ";
        getline(cin, cnpj);

        // Save to file
        ofstream file("empresa.txt", ios::app);
        if (file.is_open()) {
            file << "Empresa: " << nome << "\n";
            file << "Endereço: " << endereco << "\n";
            file << "CNPJ: " << cnpj << "\n";
            file << "------------------------\n";
            file.close();
            cout << "Empresa salva com sucesso em empresa.txt!\n";
        } else {
            cerr << "Erro ao abrir o arquivo empresa.txt!\n";
        }
    }

    void menuProdutos() {
        int opcao;
        do {
            cout << "\nMenu de Produtos para a empresa: " << nome << "\n";
            cout << "1. Cadastrar Produto\n";
            cout << "2. Voltar ao Menu Principal\n";
            cout << "Selecione uma opção: ";
            cin >> opcao;
            cin.ignore(); // Clear input buffer

            switch (opcao) {
            case 1: {
                Produto produto;
                produto.cadastrarProduto();
                produtos.push_back(produto);
                break;
            }
            case 2:
                cout << "Voltando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
            }
        } while (opcao != 2);
    }
};

int main() {
    Empresa empresa;
    int opcao;

    do {
        cout << "\nMenu Principal:\n";
        cout << "1. Cadastrar Empresa\n";
        cout << "2. Menu de Produtos\n";
        cout << "3. Sair\n";
        cout << "Selecione uma opção: ";
        cin >> opcao;
        cin.ignore(); // Clear input buffer

        switch (opcao) {
        case 1:
            empresa.cadastrarEmpresa();
            break;
        case 2:
            if (empresa.nome.empty()) {
                cout << "Nenhuma empresa cadastrada. Cadastre uma empresa primeiro!\n";
            } else {
                empresa.menuProdutos();
            }
            break;
        case 3:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 3);

    return 0;
}
