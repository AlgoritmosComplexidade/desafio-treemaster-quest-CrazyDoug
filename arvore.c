#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// ALGORITMOS EM ÁRVORES BINÁRIAS E AVL - Desafio TreeMaster Quest
// Utilize este código base para iniciar o seu desafio.
// Descomente e implemente as funções de acordo com o nível escolhido.

// ====================================================================
// ESTRUTURAS DE DADOS
// ====================================================================

// Estrutura para os Níveis Novato e Aventureiro (BST Padrão)
typedef struct No {
    int id;
    char titulo[100];
    char autor[50];
    int ano;
    struct No* esquerdo;
    struct No* direito;
} No;

// Estrutura para o Nível Mestre (AVL)
// Dica: Note a mudança do tipo do ID e a adição da variável 'altura'
typedef struct NoAVL {
    unsigned long int id;
    char titulo[100];
    char autor[50];
    int ano;
    int altura;
    struct NoAVL* esquerdo;
    struct NoAVL* direito;
} NoAVL;

// ====================================================================
// PROTÓTIPOS: NÍVEL NOVATO
// ====================================================================

// Função para criar um novo nó da árvore binária
No* criar_no(int id, const char* titulo, const char* autor, int ano) {
    // Dica: Use malloc para alocar o nó, copie as strings usando strcpy, 
    // inicialize esquerdo e direito como NULL.
    return NULL;
}

// Inserção na Árvore Binária de Busca (Recursiva ou Iterativa)
No* inserir_bst(No* raiz, No* novo_no) {
    // Dica: Compare o ID do novo_no com o ID da raiz para decidir se vai
    // para a esquerda ou para a direita.
    return raiz;
}

// Percurso Em-Ordem (In-Order) para listar os documentos
void exibir_em_ordem(No* raiz) {
    // Dica: Visite o filho esquerdo, imprima a raiz, visite o filho direito.
}

// ====================================================================
// PROTÓTIPOS: NÍVEL AVENTUREIRO (DSW e Altura)
// ====================================================================

/*
int calcular_altura(No* raiz) {
    // Dica: A altura é 1 + o máximo entre a altura da subárvore esquerda e direita.
    // Retorne -1 se a raiz for NULL.
    return 0;
}

// Funções do algoritmo DSW
int criar_vine(No** raiz) {
    // Dica: Use rotações à direita para transformar a árvore em uma lista encadeada (vine).
    return 0; // Retorna o número de nós
}

void balancear_vine(No** raiz, int n) {
    // Dica: Use rotações à esquerda baseadas na quantidade ideal de nós perfeitos.
}

No* dsw_balancear(No* raiz) {
    // Dica: Chame criar_vine e depois balancear_vine.
    return raiz;
}
*/

// ====================================================================
// PROTÓTIPOS: NÍVEL MESTRE (Árvore AVL)
// ====================================================================

/*
int altura_no_avl(NoAVL* no) {
    // Dica: Retorne a altura salva no nó, ou -1 se for NULL.
    return 0;
}

int fator_balanceamento(NoAVL* no) {
    // Dica: Altura da subárvore esquerda menos a altura da subárvore direita.
    return 0;
}

// Implemente as funções de rotação: rotacao_direita, rotacao_esquerda, etc.

NoAVL* inserir_avl(NoAVL* raiz, NoAVL* novo_no) {
    // Dica: Insira como na BST normal. Depois, atualize a altura do nó atual.
    // Calcule o fator de balanceamento e aplique as rotações (LL, RR, LR, RL) se necessário.
    return raiz;
}
*/

// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    printf("=== CODEFOREST SOLUTIONS - TREEMASTER QUEST ===\n\n");

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL NOVATO
    // ---------------------------------------------------------
    /*
    No* raiz = NULL;

    // Criando os dois documentos base fornecidos no PDF
    No* doc1 = criar_no(1001, "Introducao a programacao", "Joao Silva", 2020);
    No* doc2 = criar_no(1002, "Estruturas de dados avancadas", "Maria Oliveira", 2023);

    raiz = inserir_bst(raiz, doc1);
    raiz = inserir_bst(raiz, doc2);

    printf("=== Documentos cadastrados ===\n");
    exibir_em_ordem(raiz);
    */

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL AVENTUREIRO
    // ---------------------------------------------------------
    /*
    // Imprimir altura ANTES do DSW
    // raiz = dsw_balancear(raiz);
    // Imprimir altura DEPOIS do DSW
    */

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL MESTRE
    // ---------------------------------------------------------
    /*
    // Inicializar uma raiz do tipo NoAVL
    // Inserir documentos usando inserir_avl
    // Capturar tempo, rotações e calcular resultados
    // Exibir comparativo: "Tempo de execucao: AVL venceu (1)"
    */

    return 0;
}
