#include <iostream>
#include <string>

using namespace std;

// Classe abstrata
class Autenticacao {
public:
    void autenticar() {
        coletarDados();
        if (validarDados()) {
            iniciarSessao();
        } else {
            cout << "Falha na autenticação.\n";
        }
    }

    virtual ~Autenticacao() {}

protected:
    virtual void coletarDados() = 0;
    virtual bool validarDados() = 0;

    void iniciarSessao() {
        cout << "Sessão iniciada com sucesso!\n";
    }
};

// Subclasse para Login e Senha
class LoginSenha : public Autenticacao {
private:
    string login, senha;

protected:
    void coletarDados() override {
        cout << "Login por usuário e senha\n";
        cout << "Digite o login: ";
        cin >> login;
        cout << "Digite a senha: ";
        cin >> senha;
    }

    bool validarDados() override {
        return login.length() > 4 && senha.length() > 8;
    }
};

// Subclasse para autenticação Google
class GoogleAuth : public Autenticacao {
private:
    string email;

protected:
    void coletarDados() override {
        cout << "Login via Google\n";
        cout << "Digite o e-mail: ";
        cin >> email;
    }

    bool validarDados() override {
        const string dominio = "@gmail.com";
        if (email.length() >= dominio.length()) {
            return email.compare(email.length() - dominio.length(), dominio.length(), dominio) == 0;
        }
        return false;
    }
};

// Subclasse para autenticação por QR Code
class QRCodeAuth : public Autenticacao {
private:
    string codigo;

protected:
    void coletarDados() override {
        cout << "📷 Login via QR Code\n";
        cout << "Digite o código QR: ";
        cin >> codigo;
    }

    bool validarDados() override {
        return codigo == "QR12345";
    }
};

// Função principal
int main() {
    int opcao;
    Autenticacao* auth = nullptr;

    cout << "=== Simulador de Autenticação Discord ===\n";
    cout << "Escolha o método de autenticação:\n";
    cout << "1. Login e Senha\n";
    cout << "2. Google\n";
    cout << "3. QR Code\n";
    cout << "Opção: ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            auth = new LoginSenha();
            break;
        case 2:
            auth = new GoogleAuth();
            break;
        case 3:
            auth = new QRCodeAuth();
            break;
        default:
            cout << "Opção inválida.\n";
            return 1;
    }

    auth->autenticar();

    delete auth;
    return 0;
}
