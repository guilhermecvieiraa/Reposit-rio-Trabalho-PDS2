#ifndef GESTORES_HPP
#define GESTORES_HPP

#include "Funcionario.hpp"

class Gestores : public Funcionario {
private:
    std::string senha;

public:
    Gestores(const std::string& nome, const std::string& departamento, int id, const std::string& cargo, const std::string& senha);

    void setSenha(const std::string& senha);
    std::string getSenha() const;
};

#endif
