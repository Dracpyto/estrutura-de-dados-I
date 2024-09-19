#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib> // usar rand e strand 
#include <ctime>   // usar o time para gerar aleatoriedade 

 /*
aluno: adan alexey mafra de meneses
matricula: 202311140032
Professor: Denis Lima do Rosário
 */

int main() {
    std::queue<int> filaPar;    // Fila para números pares
    std::queue<int> filaImpar;  // Fila para números ímpares
    std::stack<int> pilha;      // Pilha para armazenar os valores positivos
    int num;

    // Inicializando o gerador de números aleatórios 
    std::srand(std::time(0));

    // Gerando valores aleatórios (incluindo 0 para finalizar)
    std::cout << "Gerando valores aleatorios...\n";
    for (int i = 0; i < 15; ++i) { // gerar 15 valores aleatórios entre -10 e 10
        num = (std::rand() % 21) - 10; // Gera números entre -10 e 10
        if (num == 0) continue; // Ignora o zero, já que ele finaliza a entrada

        std::cout << "Valor gerado: " << num << "\n";

        // Separar os números em pares e ímpares
        if (num % 2 == 0) {
            filaPar.push(num);
        } else {
            filaImpar.push(num);
        }
    }

    // Processando as filas
    std::cout << "\nProcessando as filas...\n";
    while (!filaPar.empty() || !filaImpar.empty()) {
       
	    // Primeiro processa a fila de ímpares
        if (!filaImpar.empty()) {
            int valorImpar = filaImpar.front();
            filaImpar.pop();
            std::cout << "Retirado da FILA IMPAR: " << valorImpar << "\n";

            if (valorImpar > 0) {
                pilha.push(valorImpar); // Adiciona à pilha se for positivo
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
                pilha.push(valorPar); // Adiciona à pilha se for positivo
            } else if (!pilha.empty()) {
                pilha.pop(); // Remove da pilha se for negativo e houver elementos
            }
        }
    }


    // Exibindo o conteúdo final da pilha
    std::cout << "\nconteudo final da PILHA:\n";
    if (pilha.empty()) {
        std::cout << "A pilha está vazia.\n";
    } else {
        while (!pilha.empty()) {
            std::cout << pilha.top() << " ";
            pilha.pop();
        }
        std::cout << "\n";
    }

    return 0;
}
