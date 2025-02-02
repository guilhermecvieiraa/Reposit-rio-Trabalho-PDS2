#include <iostream>
#include <fstream>
#include "Empresa.hpp"
#include "Departamento.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Produto.hpp"
#include "Gestores.hpp"
#include "Transportadora.hpp"
#include "Motorista.hpp"
#include "Veiculo.hpp"
#include "Solicitacao.hpp"
#include "Refeitorio.hpp"

class Cargo {
public:
    std::string nomeDoCargo;
    float salario;
    Funcionario funcionario;

    Cargo(const std::string &nomeDoCargo, float salario, const Funcionario &funcionario);

    void salvarCargo() const;

    std::string toString() const {
        return "Cargo: " + nomeDoCargo + ", Salário: " + std::to_string(salario) + 
               ", Funcionário: " + funcionario.toString();
    }
};

class Departamento {
public:
    std::string nome;
    std::string gestor;
    std::vector<Funcionario> funcionarios;
    std::vector<Trabalho> trabalhos;

    // Construtor
    Departamento(const std::string &nome, const std::string &gestor, const std::vector<Funcionario> &funcionarios, const std::vector<Trabalho> &trabalhos)
        : nome(nome), gestor(gestor), funcionarios(funcionarios), trabalhos(trabalhos) {}

    void salvarDepartamento() const;

    // Método toString
    std::string toString() const {
        std::string result = "Departamento: " + nome + ", Gestor: " + gestor;

        result += "\nFuncionários:\n";
        for (const auto &funcionario : funcionarios) {
            result += "  - " + funcionario.toString() + "\n"; // Supõe que Funcionario tem toString
        }

        result += "Trabalhos:\n";
        for (const auto &trabalho : trabalhos) {
            result += "  - " + trabalho.toString() + "\n"; // Supõe que Trabalho tem toString
        }

        return result;
    }
};


class Empresa {
public:
    std::string nome;
    Endereco endereco;
    std::string cnpj;
    std::vector<Departamento> departamentos;
    std::vector<Produto> produtos; 
    std::vector<Refeitorio> refeitorios;

    Empresa(const std::string &nome, const Endereco &endereco, const std::string &cnpj,
            const std::vector<Departamento> &departamentos,
            const std::vector<Produto> &produtos,
            const std::vector<Refeitorio> &refeitorios)
        : nome(nome), endereco(endereco), cnpj(cnpj), 
          departamentos(departamentos), produtos(produtos), refeitorios(refeitorios) {}

    void salvarEmpresa() const;

    // Método toString
    std::string toString() const {
        std::string result = "Empresa: " + nome + "\n";
        result += "CNPJ: " + cnpj + "\n";
        result += "Endereço: " + endereco.toString() + "\n"; // Supondo que Endereco tenha toString

        result += "\nDepartamentos:\n";
        for (const auto &departamento : departamentos) {
            result += departamento.toString() + "\n"; // Supondo que Departamento tenha toString
        }

        result += "\nProdutos:\n";
        for (const auto &produto : produtos) {
            result += "  - " + produto.toString() + "\n"; // Supondo que Produto tenha toString
        }

        result += "\nRefeitórios:\n";
        for (const auto &refeitorio : refeitorios) {
            result += "  - " + refeitorio.toString() + "\n"; // Supondo que Refeitorio tenha toString
        }

        return result;
    }
};

class Endereco {
public:
    std::string rua;
    std::string bairro;
    std::string cep;
    int numero;
    std::string complemento;

    Endereco(const std::string &rua, const std::string &bairro, const std::string &cep, 
             int numero, const std::string &complemento)
        : rua(rua), bairro(bairro), cep(cep), numero(numero), complemento(complemento) {}

    void salvarEndereco() const;

    // Método toString
    std::string toString() const {
        return "Rua: " + rua + ", Nº: " + std::to_string(numero) + ", Bairro: " + bairro +
               ", CEP: " + cep + (complemento.empty() ? "" : ", Complemento: " + complemento);
    }
};

class Funcionario {
public:
    std::vector<Departamento> departamentos;
    std::string ID_funcionario;
    std::vector<Cargo> cargos;

    Funcionario(const std::string &ID_funcionario,
                const std::vector<Departamento> &departamentos,
                const std::vector<Cargo> &cargos)
        : ID_funcionario(ID_funcionario), departamentos(departamentos), cargos(cargos) {}

    void salvarFuncionario() const;

    // Método toString
    std::string toString() const {
        std::string result = "ID do Funcionário: " + ID_funcionario + "\n";

        result += "Departamentos:\n";
        for (const auto &departamento : departamentos) {
            result += "  - " + departamento.toString() + "\n"; // Supõe que Departamento tem toString
        }

        result += "Cargos:\n";
        for (const auto &cargo : cargos) {
            result += "  - " + cargo.toString() + "\n"; // Supõe que Cargo tem toString
        }

        return result;
    }
};

class Gestores : public Funcionario {
public:
    // Construtor
    Gestores(const std::string &ID_funcionario,
             const std::vector<Departamento> &departamentos,
             const std::vector<Cargo> &cargos)
        : Funcionario(ID_funcionario, departamentos, cargos) {}

    // Método toString
    std::string toString() const {
        return Funcionario::toString() + "\nCargo: Gestor";
    }
};

class Motorista {
public:
    // Atributos públicos
    string NomeMotorista;
    int IdadeMotorista;
    string NumeroCNH;
    string ValidadeCNH;
    string TipoCNH;

    // Construtor
    Motorista(string NomeMotorista = "", int IdadeMotorista = 0, 
              string NumeroCNH = "", string ValidadeCNH = "", 
              string TipoCNH = "");

    // Métodos
    string toString() const;  // Método que retorna a representação em string
};

class Pessoa {
public:
    std::string nome;
    std::string cpf;
    std::string telefone;
    std::vector<Endereco> Endereco;  // Um vetor de objetos Endereço

    // Métodos
    bool validarCPF(const std::string& cpf);
    bool validarNumero(const std::string& numero);

    void salvarPessoa();

    std::string toString() const {
        return "Nome: " + nome + "\n" + 
               "CPF: " + cpf + "\n" + 
               "Telefone: " + telefone;
    }
};

class Produto {
public:
    std::string nome;
    float custo;
    std::string dataFabricacao;
    int codigo;

    // Método para salvar o produto
    void salvarProduto(const std::string& nomeEmpresa);

    std::string toString() const {
        return "Produto: " + nome + ", Custo: " + std::to_string(custo) + 
               ", Data de Fabricação: " + dataFabricacao + ", Código: " + std::to_string(codigo);
    }

    
};

class Refeitorio {
public:
    std::string localizacao;
    std::string cozinheira_chefe;
    std::string comodidade;
    std::string horario_de_funcionamento;
    Empresa empresa;

    // Construtor
    Refeitorio(const std::string &localizacao, const std::string &cozinheira_chefe, 
               const std::string &comodidade, const std::string &horario, const Empresa &empresa);

    // Método para salvar os dados do refeitório
    void salvarRefeitorio() const;

     std::string toString() const {
        return "Refeitório localizado em: " + localizacao + ", Cozinheira Chefe: " + cozinheira_chefe + 
               ", Comodidade: " + comodidade + ", Horário de Funcionamento: " + horario_de_funcionamento + 
               ", Empresa: " + empresa.toString();  // Supondo que Empresa tenha o método toString
    }
};

class Solicitacao {
public:
    std::string veiculo;
    Motorista motorista;
    std::string endereco;
    double valorFrete;
    std::string produto;

    Solicitacao(const std::string &veiculo = "", const Motorista &motorista = Motorista(), 
                const std::string &endereco = "", double valorFrete = 0.0, 
                const std::string &produto = "")
        : veiculo(veiculo), motorista(motorista), endereco(endereco), 
          valorFrete(valorFrete), produto(produto) {}

    std::string toString() const {
        return "Solicitação: Veículo: " + veiculo + ", Motorista: " + motorista.toString() + 
               ", Endereço: " + endereco + ", Valor do Frete: " + std::to_string(valorFrete) + 
               ", Produto: " + produto;
    }
};

class Trabalho {
public:
    std::string tipo;
    std::string tempoExec;
    std::string detalheTrabalho;
    std::string custo;
    Departamento departamento;

    // Construtor
    Trabalho(const std::string &tipo = "", const std::string &tempoExec = "", 
             const std::string &detalheTrabalho = "", const std::string &custo = "", 
             const Departamento &departamento = Departamento());

    // Método para salvar os dados do trabalho
    void salvarTrabalho() const;

    std::string toString() const {
        // Exemplo de conversão dos dados da classe em string
        return "Trabalho: " + tipo;
    }
};

Trabalho::Trabalho(const std::string &tipo, const std::string &tempoExec, 
                   const std::string &detalheTrabalho, const std::string &custo, 
                   const Departamento &departamento)
    : tipo(tipo), tempoExec(tempoExec), detalheTrabalho(detalheTrabalho), 
      custo(custo), departamento(departamento) {}

class Transportadora {
public:
    std::string nome;
    std::string endereco;

    Transportadora(const std::string &nome = "", const std::string &endereco = "")
        : nome(nome), endereco(endereco) {}

    std::string toString() const {
        return "Transportadora: " + nome + ", Endereço: " + endereco;
    }
};

class Veiculo {
public:
    std::string tipoVeiculo;
    std::string modelo;
    std::string placa;
    std::string documento;

    Veiculo(const std::string &tipo = "", const std::string &modelo = "", 
            const std::string &placa = "", const std::string &documento = "")
        : tipoVeiculo(tipo), modelo(modelo), placa(placa), documento(documento) {}

    std::string toString() const {
        return "Veículo: " + tipoVeiculo + ", Modelo: " + modelo + 
               ", Placa: " + placa + ", Documento: " + documento;
    }
};





void salvarEmpresa(const Empresa& empresa) {
    std::ofstream file("Empresa.txt");
    if (file.is_open()) {
        file << empresa.toString();
        file.close();
    }
}

void salvarDepartamento(const Departamento& depto) {
    std::ofstream file("Departamento.txt");
    if (file.is_open()) {
        file << depto.toString();
        file.close();
    }
}

void salvarPessoa(const Pessoa& pessoa) {
    std::ofstream file("Pessoa.txt");
    if (file.is_open()) {
        file << pessoa.toString();
        file.close();
    }
}

void salvarFuncionario(const Funcionario& func) {
    std::ofstream file("Funcionario.txt");
    if (file.is_open()) {
        file << func.toString();
        file.close();
    }
}

void salvarTrabalho(const Trabalho& trabalho) {
    std::ofstream file("Trabalho.txt");
    if (file.is_open()) {
        file << trabalho.toString();
        file.close();
    }
}

void salvarProduto(const Produto& produto) {
    std::ofstream file("Produto.txt");
    if (file.is_open()) {
        file << produto.toString();
        file.close();
    }
}

void salvarGestor(const Gestores& gestor) {
    std::ofstream file("Gestor.txt");
    if (file.is_open()) {
        file << gestor.toString();
        file.close();
    }
}

void salvarTransportadora(const Transportadora& transp) {
    std::ofstream file("Transportadora.txt");
    if (file.is_open()) {
        file << transp.toString();
        file.close();
    }
}

void salvarMotorista(const Motorista& motorista) {
    std::ofstream file("Motorista.txt");
    if (file.is_open()) {
        file << motorista.toString();
        file.close();
    }
}

void salvarVeiculo(const Veiculo& veiculo) {
    std::ofstream file("Veiculo.txt");
    if (file.is_open()) {
        file << veiculo.toString();
        file.close();
    }
}

void salvarSolicitacao(const Solicitacao& sol) {
    std::ofstream file("Solicitacao.txt");
    if (file.is_open()) {
        file << sol.toString();
        file.close();
    }
}

void salvarRefeitorio(const Refeitorio& refeitorio) {
    std::ofstream file("Refeitorio.txt");
    if (file.is_open()) {
        file << refeitorio.toString();
        file.close();
    }
}

int main() {
    Empresa empresa("Minha Empresa", endereco, "12345678000199", {}, {}, {});
    Departamento depto("TI", "Carlos", {}, {});
    Endereco endereco("Rua ABC", "Centro", "12345-678", 123, "Apto 101");
    Pessoa pessoa("João", "123.456.789-00", "(11) 99999-9999");
    Funcionario func(depto, 1001, "Engenheiro");
    Trabalho trabalho("Desenvolvimento de Software", "40 horas", "Sistema Web", "5000.0", depto);
    Produto produto("Notebook", 3000.0, "2024-01-15", 123);
    Gestores gestor("12345", {}, {});
    Transportadora transportadora;
    Motorista motorista("João", 30, "123456789", "2025-12-31", "B, C");
    Veiculo veiculo("Caminhão", "Volvo FH", "XYZ-1234", "Doc2024");
    Solicitacao solicitacao("Caminhão", motorista, "Rua Entrega, 789", 150.0, "Notebook");
    Refeitorio refeitorio("Bloco A", "Maria", "Buffet", "08:00 - 18:00", empresa);

    salvarEmpresa(empresa);
    salvarDepartamento(depto);
    salvarPessoa(pessoa);
    salvarFuncionario(func);
    salvarTrabalho(trabalho);
    salvarProduto(produto);
    salvarGestor(gestor);
    salvarTransportadora(transportadora);
    salvarMotorista(motorista);
    salvarVeiculo(veiculo);
    salvarSolicitacao(solicitacao);
    salvarRefeitorio(refeitorio);

    std::cout << "Dados salvos com sucesso!" << std::endl;

    return 0;
}};
