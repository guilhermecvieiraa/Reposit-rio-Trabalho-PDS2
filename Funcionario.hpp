#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>

class Funcionario {
private:
    std::string nome;
    std::string departamento;
    int idFuncionario;
    std::string cargo;

public:
    Funcionario(const std::string& nome, const std::string& departamento, int id, const std::string& cargo);
    
    void setNome(const std::string& nome);
    std::string getNome() const;

    void setDepartamento(const std::string& departamento);
    std::string getDepartamento() const;

    void setIdFuncionario(int id);
    int getIdFuncionario() const;

    void setCargo(const std::string& cargo);
    std::string getCargo() const;
};

class Cargos {
public:
  std::string nome_do_cargo;
  float salario;

  void salvarCargos(const std::string &cargoFuncionario) {
    std::ofstream arquivo("cargos.txt", std::ios::app);
    if (arquivo.is_open()) {
      arquivo << "Funcionário: " << cargoFuncionario << "\n";
      arquivo << "Nome do Cargo: " << nome_do_cargo << "\n";
      arquivo << "Salário: " << salario << "\n";
      arquivo << "-----------------------------\n";
      arquivo.close();
    }
  }
};

#endif
