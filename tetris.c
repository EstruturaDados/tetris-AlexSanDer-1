#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.

typedef struct {
   char nome;
   int id;
}Tetris;


#define MAX 5

typedef struct{
    Tetris pecas[MAX];
    int inicio;
    int fim;
    int total;
}Fila;


void iniciarFila(Fila *f){
    f -> inicio = 0;
    f -> fim = 0;
    f -> total = 0;
}

int filaCheia(Fila *f){
    return f -> total == MAX;
}

int filaVazia(Fila *f){
    return f -> total == 0;
}


void inserir(Fila *f,Tetris t){
    if(filaCheia(f)){
        printf("Fila cheia, Não é possivel inserir. \n");
        return;
    }

    f -> pecas[f -> fim] = t;
    f -> fim = (f -> fim + 1) % MAX;
    f -> total++;
}

void remover(Fila *f,Tetris *t){
    if(filaVazia(f)){
        printf("Fila vazia, Não é possivel remover. \n");
        return;
    }

    *t = f -> pecas[f -> inicio];
    f -> inicio = (f -> inicio + 1) % MAX;
    f -> total--;
}

void  mostrarFila(Fila *f){

    printf("Fila: ");
    for(int i = 0,idx = f -> inicio; i < f -> total; i++,idx = (idx + 1) % MAX){
        printf("[%c,%d] ", f->pecas[idx].nome,f->pecas[idx].id);
    }

    printf("\n");
}




void menu(){

    char texto[] =
                   " 1 - Jogar peça \n"
                   " 2 - Remover peça \n"
                   " 3 - Exibir peças \n"
                   " 4 - Sair \n";

    printf("\n");
    printf("%s", texto);

   
}


int main() {

    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.


    Fila f;
    iniciarFila(&f);

    Tetris t1 = {'I', 1};
    Tetris t2 = {'O', 2};
    Tetris t3 = {'T', 3};
    Tetris t4 = {'L', 4};

    inserir(&f,t1);
    inserir(&f,t2);
    inserir(&f,t3);
    inserir(&f,t4);

   int opcao;

    while (opcao != 4) {

    mostrarFila(&f);  
    menu();
    printf("Escolha uma opção: \n");
    scanf("%d", &opcao);


    switch (opcao) {
    case 1:

    char nome_peca;
    int id_peca;

    printf("Digite nome da peça: \n ");
    scanf("%c", &nome_peca);
    printf("Digite id da peça: \n");
    scanf("%d", &id_peca);
    
    Tetris t_user = {nome_peca,id_peca};

    inserir(&f,t_user);
    mostrarFila(&f);

        break;
    
    default:
        break;
    }
    



    }
    
    

    



















    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha


    return 0;
}

