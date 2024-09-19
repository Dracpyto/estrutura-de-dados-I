#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib> // usar rand e strand 
#include <ctime>   // usar o time para gerar aleatoriedade 

 /*
aluno: adan alexey mafra de meneses
matricula: 202311140032
Professor: Denis Lima do Ros�rio
 */

int main() {
    std::queue<int> filaPar;    // Fila para n�meros pares
    std::queue<int> filaImpar;  // Fila para n�meros �mpares
    std::stack<int> pilha;      // Pilha para armazenar os valores positivos
    int num;

    // Inicializando o gerador de n�meros aleat�rios 
    std::srand(std::time(0));

    // Gerando valores aleat�rios (incluindo 0 para finalizar)
    std::cout << "Gerando valores aleatorios...\n";
    for (int i = 0; i < 15; ++i) { // gerar 15 valores aleat�rios entre -10 e 10
        num = (std::rand() % 21) - 10; // Gera n�meros entre -10 e 10
        if (num == 0) continue; // Ignora o zero, j� que ele finaliza a entrada

        std::cout << "Valor gerado: " << num << "\n";

        // Separar os n�meros em pares e �mpares
        if (num % 2 == 0) {
            filaPar.push(num);
        } else {
            filaImpar.push(num);
        }
    }

    // Processando as filas
    std::cout << "\nProcessando as filas...\n";
    while (!filaPar.empty() || !filaImpar.empty()) {
       
	    // Primeiro processa a fila de �mpares
        if (!filaImpar.empty()) {
            int valorImpar = filaImpar.front();
            filaImpar.pop();
            std::cout << "Retirado da FILA IMPAR: " << valorImpar << "\n";

            if (valorImpar > 0) {
                pilha.push(valorImpar); // Adiciona � pilha se for positivo
            } else if (!pilha.empty()) {
                pilha.pop(); // Remove da pilha se for negativo e houver elementos
            }
        }


        // Em seguida, processa a fila de pares
        if (!filaPar.empty()) {
            int valorPar = filaPar.front();
            filaPar.pop();
            std::cout << "Retirado da FILA PAR: " << valorPar << "\n";

            if (valorPar > 0) {
                pilha.push(valorPar); // Adiciona � pilha se for positivo
            } else if (!pilha.empty()) {
                pilha.pop(); // Remove da pilha se for negativo e houver elementos
            }
        }
    }


    // Exibindo o conte�do final da pilha
    std::cout << "\nconteudo final da PILHA:\n";
    if (pilha.empty()) {
        std::cout << "A pilha est� vazia.\n";
    } else {
        while (!pilha.empty()) {
            std::cout << pilha.top() << " ";
            pilha.pop();
        }
        std::cout << "\n";
    }

    return 0;
}
