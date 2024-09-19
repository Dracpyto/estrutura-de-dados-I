#include <iostream>
#include <queue>
#include <string>

 /*
aluno: adan alexey mafra de meneses
matricula: 202311140032
Professor: Denis Lima do Rosário
 */

// Estrutura para representar um avião
struct Aviao {
    std::string nome;
    int id;
    
    // Construtor
    Aviao(std::string nome, int id) : nome(nome), id(id) {}
};

// Função para listar os aviões na fila
void listarAvioes(const std::queue<Aviao>& fila) {
    if (fila.empty()) {
        std::cout << "Nenhum aviao na fila de espera.\n";
        return;
    }
    
    std::queue<Aviao> temp = fila;  // Criar uma cópia temporária da fila para listagem
    std::cout << "Avioes na fila de espera:\n";
    while (!temp.empty()) {
        Aviao aviao = temp.front();
        std::cout << "ID: " << aviao.id << ", Nome: " << aviao.nome << "\n";
        temp.pop(); 
    }
}

// Função para listar os atributos do primeiro avião
void listarPrimeiroAviao(const std::queue<Aviao>& fila) {
    if (fila.empty()) {
        std::cout << "Nenhum aviao na fila de espera.\n";
    } else {
        Aviao aviao = fila.front();
        std::cout << "Primeiro aviao na fila:\n";
        std::cout << "ID: " << aviao.id << ", Nome: " << aviao.nome << "\n";
    }
}

int main() {
    std::queue<Aviao> filaDecolagem;  // Fila de aviões aguardando decolagem
    int opcao, idCounter = 1;
    std::string nomeAviao;

    do {
        std::cout << "\n--- Controle da Pista de Decolagem ---\n";
        std::cout << "1. Listar o número de avioes aguardando\n";
        std::cout << "2. Autorizar a decolagem do primeiro aviao\n";
        std::cout << "3. Adicionar um aviao à fila de espera\n";
        std::cout << "4. Listar todos os avioes na fila de espera\n";
        std::cout << "5. Listar as características do primeiro aviao\n";
        std::cout << "6. Sair\n";
        std::cout << "Escolha uma opçao: ";
        std::cin >> opcao;

        switch (opcao) {
        case 1:
            std::cout << "Número de avioes aguardando: " << filaDecolagem.size() << "\n";
            break;
        
        case 2:
            if (!filaDecolagem.empty()) {
                Aviao primeiroAviao = filaDecolagem.front();
                std::cout << "Aviao ID: " << primeiroAviao.id << " com nome " << primeiroAviao.nome << " autorizado para decolagem.\n";
                filaDecolagem.pop();  // Remove o primeiro avião da fila
            } else {
                std::cout << "Nenhum aviao na fila para decolagem.\n";
            }
            break;

        case 3:
            std::cout << "Digite o nome do aviao: ";
            std::cin >> nomeAviao;
            filaDecolagem.push(Aviao(nomeAviao, idCounter++));  // Adiciona um avião à fila
            std::cout << "Aviao adicionado à fila.\n";
            break;

        case 4:
            listarAvioes(filaDecolagem);  // Listar todos os aviões na fila
            break;

        case 5:
            listarPrimeiroAviao(filaDecolagem);  // Mostrar as características do primeiro avião
            break;

        case 6:
            std::cout << "Encerrando o programa...\n";
            break;

        default:
            std::cout << "Opcao Tente de novo.\n";
            break;
        }
    } while (opcao != 6);

    return 0;
}
