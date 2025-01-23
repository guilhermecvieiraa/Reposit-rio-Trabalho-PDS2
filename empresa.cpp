#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

class Departamento {
  // Classe vazia por enquanto
};

class Refeitorio {
  // Classe vazia por enquanto
};

class Empresa {
public:
  std::string nome;
  std::string endereco;
  std::string cnpj;

  void salvarEmpresa() {
    std::ofstream arquivo("empresa.txt", std::ios::app);
    if (arquivo.is_open()) {
      arquivo << "Nome: " << nome << "\n";
      arquivo << "Endereço: " << endereco << "\n";
      arquivo << "CNPJ: " << cnpj << "\n";
      arquivo << "-----------------------------\n";
      arquivo.close();
    }
  }
};

int main() {
  Empresa empresa;
  Produto produto;

  std::cout << "Digite o nome da empresa: ";
  std::getline(std::cin, empresa.nome);

  std::cout << "Digite o endereço da empresa: ";
  std::getline(std::cin, empresa.endereco);

  std::cout << "Digite o CNPJ da empresa: ";
  std::getline(std::cin, empresa.cnpj);

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

  std::cout << "Informações salvas com sucesso!!" << std::endl;
  return 0;
}
