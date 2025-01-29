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

#endif
