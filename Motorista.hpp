#ifndef MOTORISTA_HPP
#define MOTORISTA_HPP

#include <iostream>
#include <string>

using namespace std;

class Motorista {
private:
    string NomeMotorista;
    int IdadeMotorista;
    string NumeroCNH;
    string ValidadeCNH;
    string TipoCNH;

public:
    // Construtor
    Motorista(string NomeMotorista = "", int IdadeMotorista = 0, 
              string NumeroCNH = "", string ValidadeCNH = "", 
              string TipoCNH = "");

    // Métodos
    void solicitarDadosM();
    void exibirDados() const;

    // Getters
    string getNome() const;
    int getIdadeMotorista() const;
    string getNumeroCNH() const;
    string getValidadeCNH() const;
    string getTipoCNH() const;
};

#endif
