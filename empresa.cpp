#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Solicitacao.hpp"

// as vezes nao compensaria usar using namespace std para organizar? 

class Endereco{
  public:
  std::string rua;
  std::string bairro;
  std::string cep;
  int numero;
  std::string complemento;
 
 void salvarEndereco(const int){
  std::ofstream arquivo("produtos.txt", std::ios::app);
    if (arquivo.is_open()) {
      arquivo << "Rua: " << rua << "\n";
      arquivo << "Bairro: " << bairro << "\n";
      arquivo << "CEP: " << cep << "\n";
      arquivo << "Numero: " << numero << "\n";
      arquivo << "Complemento: " << complemento << "\n";
      arquivo << "-----------------------------\n";
      arquivo.close();
    }
 }
};

class Produto {
public:
  std::string nome;
  float custo;
  std::string dataFabricacao;
  int codigo;

  void salvarProduto(const std::string &nomeEmpresa) {
    std::ofstream arquivo("produtos.txt", std::ios::app);
    if (arquivo.is_open()) {
      arquivo << "Empresa: " << nomeEmpresa << "\n";
      arquivo << "Produto: " << nome << "\n";
      arquivo << "Custo: " << custo << "\n";
      arquivo << "Data de Fabricação: " << dataFabricacao << "\n";
      arquivo << "Código: " << codigo << "\n";
      arquivo << "-----------------------------\n";
      arquivo.close();
    }
  }
};

class Departamento{
    public:
        std::string nome;
        std::string gestor;
        std::vector<Funcionario> funcionarios;
        std::string trabalhos;

        void salvarDepartamento(){
            std::ofstream arquivo("departamento.txt", std::ios::app);
            if (arquivo.is_open()) {
      arquivo << "Nome: " << nome<< "\n";
      arquivo << "Gestor: " << gestor << "\n";
      arquivo << "Funcionarios: ";
      for (const auto& funcionario : funcionarios) {
                arquivo << " - " << funcionario.nome << "\n";
            }
      arquivo << "Trabalhos: " << trabalhos << "\n";
      arquivo << "-----------------------------\n";
      arquivo.close();
      arquivo << "-----------------------------\n";
      arquivo.close();
    }
        }
};

class Refeitorio {
  // Classe vazia por enquanto
};

class Funcionario {
  // Classe vazia por enquanto
  std::string nome;
};

class Empresa {
public:
  std::string nome;
  Endereco endereco;
  std::string cnpj;
  std::vector<Departamento> departamentos;

  void salvarEmpresa() {
    std::ofstream arquivo("empresa.txt", std::ios::app);
    if (arquivo.is_open()) {
      arquivo << "Nome: " << nome << "\n";
      arquivo << "Endereço: " << endereco.rua << ", n°" << endereco.numero << " - " << endereco.bairro << " - " << endereco.cep;
      arquivo << "CNPJ: " << cnpj << "\n";
      arquivo << "Departamentos:";
      for (const auto& departamento: departamentos){;
                arquivo << " - " << departamento.nome << "\n";
            }
      arquivo << "-----------------------------\n";
      arquivo.close();
    }
  }
};

int main() {
  Empresa empresa;
  Produto produto;
  Departamento departamento;
  Endereco endereco;

  std::cout << "Digite o nome da empresa: ";
  std::getline(std::cin, empresa.nome);

  std::cout << "Digite o CNPJ da empresa: ";
  std::getline(std::cin, empresa.cnpj);

  std::cout << "Digite a rua da empresa: ";
  std::getline(std::cin, endereco.rua);

  std::cout << "Digite o bairro da empresa: ";
  std::getline(std::cin, endereco.bairro);

  std::cout << "Digite o CEP da empresa: ";
  std::getline(std::cin, endereco.cep);

  std::cout << "Digite o número da empresa: ";
  std::cin, endereco.numero;

  std::cout << "Digite o complemento do endereço da empresa: ";
  std::getline(std::cin, endereco.complemento);



  empresa.salvarEmpresa();

  std::cout << "\nInformações sobre os produtos.\n";

  char continuar = 's';
  while (continuar == 's') {
    std::cout << "Digite o nome do produto: ";
    std::getline(std::cin, produto.nome);

    std::cout << "Digite o custo do produto: ";
    std::cin >> produto.custo;
    std::cin.ignore();

    std::cout << "Digite a data de fabricação do produto: ";
    std::getline(std::cin, produto.dataFabricacao);

    std::cout << "Digite o código do produto: ";
    std::cin >> produto.codigo;
    std::cin.ignore();

    produto.salvarProduto(empresa.nome);

    std::cout << "Deseja adicionar outro produto? (s/n): ";
    std::cin >> continuar;
    std::cin.ignore();
  }

  char continuar = 's';
  while (continuar == 's') {
    std::cout << "Digite o nome do departamento: ";
    std::getline(std::cin, departamento.nome);

    std::cout << "Digite o nome do gestor do departamento: ";
    std::getline(std::cin, departamento.gestor);

    std::cout << "Digite os trabalhos do departamento: ";
    std::getline(std::cin, departamento.trabalhos);

    departamento.salvarDepartamento();
  }



  std::cout << "Informações salvas com sucesso!!" << std::endl;
 
// Implementacao da classe solicitacao(Denner) de entrega na main 
 std::cout << "\n=== Solicitação de Entrega ===\n";

    Solicitacao pedido1;
    pedido1.solicitarDados();
    pedido1.exibirDetalhes();
    pedido1.salvarEmArquivo();

  // Fiz essa solicitacao para simular como se ja tivesse uma solicitacao na fila quando o programa lesse o arquivo txt para pegar os dados 
  
    Solicitacao pedido2("Caminhão", "Lucas Lima", "Gustavo Corsão, 1470", 140, "Caixas de Eletrônicos");
    std::cout << "\nPedido anterior na fila de espera:" << std::endl;
    pedido2.exibirDetalhes();
    pedido2.salvarEmArquivo();

    std::cout << "Informações salvas com sucesso!!" << std::endl;
    
    return 0;
}
