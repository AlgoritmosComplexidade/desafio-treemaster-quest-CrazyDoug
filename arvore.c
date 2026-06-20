// Feito por Douglas Alves Costa
// Nivel NOVATO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// ALGORITMOS EM ÁRVORES BINÁRIAS E AVL - Desafio TreeMaster Quest

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
// FUNÇÕES: NÍVEL NOVATO
// ====================================================================

// Função para criar um novo nó da árvore binária
No* criar_no(int id, const char* titulo, const char* autor, int ano) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    novo->id = id;
    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    novo->ano = ano;
    novo->esquerdo = NULL;
    novo->direito = NULL;

    return novo;
}

// Inserção na Árvore Binária de Busca
No* inserir_bst(No* raiz, No* novo_no) {
    if (raiz == NULL) {
        return novo_no;
    }

    if (novo_no->id < raiz->id) {
        raiz->esquerdo = inserir_bst(raiz->esquerdo, novo_no);
    } else if (novo_no->id > raiz->id) {
        raiz->direito = inserir_bst(raiz->direito, novo_no);
    } else {
        printf("ID %d ja existe na arvore. Documento nao inserido.\n", novo_no->id);
    }

    return raiz;
}

// Percurso Em-Ordem para listar os documentos em ordem crescente de ID
void exibir_em_ordem(No* raiz) {
    if (raiz != NULL) {
        exibir_em_ordem(raiz->esquerdo);

        printf("ID: %d | Titulo: %s | Autor: %s | Ano: %d\n",
               raiz->id,
               raiz->titulo,
               raiz->autor,
               raiz->ano);

        exibir_em_ordem(raiz->direito);
    }
}

// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    printf("=== CODEFOREST SOLUTIONS - TREEMASTER QUEST ===\n\n");

    No* raiz = NULL;

    No* doc1 = criar_no(1001, "Introducao a programacao", "Joao Silva", 2020);
    No* doc2 = criar_no(1002, "Estruturas de dados avancadas", "Maria Oliveira", 2023);

    raiz = inserir_bst(raiz, doc1);
    raiz = inserir_bst(raiz, doc2);

    printf("=== Documentos cadastrados em ordem crescente de ID ===\n");
    exibir_em_ordem(raiz);

    return 0;
}