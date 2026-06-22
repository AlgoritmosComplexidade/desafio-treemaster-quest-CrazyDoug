// Feito por Douglas Alves Costa
// Nivel AVENTUREIRO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int id;
    char titulo[100];
    char autor[50];
    int ano;
    struct No* esquerdo;
    struct No* direito;
} No;

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

No* inserir_bst(No* raiz, No* novo_no) {
    if (raiz == NULL) {
        return novo_no;
    }

    if (novo_no->id < raiz->id) {
        raiz->esquerdo = inserir_bst(raiz->esquerdo, novo_no);
    } else if (novo_no->id > raiz->id) {
        raiz->direito = inserir_bst(raiz->direito, novo_no);
    }

    return raiz;
}

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

int maior(int a, int b) {
    return (a > b) ? a : b;
}

// Calcula a altura da árvore em número de níveis.
// Árvore vazia tem altura 0.
int calcular_altura(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + maior(calcular_altura(raiz->esquerdo),
                     calcular_altura(raiz->direito));
}

void rotacao_direita(No** raiz) {
    No* filho = (*raiz)->esquerdo;
    (*raiz)->esquerdo = filho->direito;
    filho->direito = *raiz;
    *raiz = filho;
}

void rotacao_esquerda(No** raiz) {
    No* filho = (*raiz)->direito;
    (*raiz)->direito = filho->esquerdo;
    filho->esquerdo = *raiz;
    *raiz = filho;
}

// Transforma a árvore em uma "vine", uma espinha inclinada para a direita.
int criar_vine(No** raiz) {
    int contador = 0;
    No** atual = raiz;

    while (*atual != NULL) {
        if ((*atual)->esquerdo != NULL) {
            rotacao_direita(atual);
        } else {
            contador++;
            atual = &((*atual)->direito);
        }
    }

    return contador;
}

// Faz rotações à esquerda em sequência para compactar a vine.
void compactar_vine(No** raiz, int quantidade) {
    No** atual = raiz;

    for (int i = 0; i < quantidade; i++) {
        if (*atual != NULL && (*atual)->direito != NULL) {
            rotacao_esquerda(atual);
            atual = &((*atual)->direito);
        }
    }
}

// Calcula 2^k - 1, que representa o número de nós de uma árvore perfeita.
int maior_potencia_menos_um(int n) {
    int x = 1;

    while (x <= n) {
        x = x * 2;
    }

    return (x / 2) - 1;
}

// Balanceia a vine usando o algoritmo DSW.
void balancear_vine(No** raiz, int n) {
    int m = maior_potencia_menos_um(n);

    compactar_vine(raiz, n - m);

    while (m > 1) {
        m = m / 2;
        compactar_vine(raiz, m);
    }
}

No* dsw_balancear(No* raiz) {
    int n = criar_vine(&raiz);
    balancear_vine(&raiz, n);

    return raiz;
}

int main() {
    printf("=== CODEFOREST SOLUTIONS - TREEMASTER QUEST ===\n\n");

    No* raiz = NULL;

    raiz = inserir_bst(raiz, criar_no(1001, "Introducao a programacao", "Joao Silva", 2020));
    raiz = inserir_bst(raiz, criar_no(1002, "Estruturas de dados avancadas", "Maria Oliveira", 2023));
    raiz = inserir_bst(raiz, criar_no(1003, "Banco de Dados", "Carlos Mendes", 2021));
    raiz = inserir_bst(raiz, criar_no(1004, "Redes de Computadores", "Ana Souza", 2019));
    raiz = inserir_bst(raiz, criar_no(1005, "Sistemas Operacionais", "Marcos Lima", 2022));
    raiz = inserir_bst(raiz, criar_no(1006, "Inteligencia Artificial", "Fernanda Rocha", 2024));
    raiz = inserir_bst(raiz, criar_no(1007, "Engenharia de Software", "Paulo Costa", 2020));

    printf("=== Documentos cadastrados em ordem crescente de ID ===\n");
    exibir_em_ordem(raiz);

    printf("\nAltura antes do balanceamento DSW: %d\n", calcular_altura(raiz));

    raiz = dsw_balancear(raiz);

    printf("Altura depois do balanceamento DSW: %d\n\n", calcular_altura(raiz));

    printf("=== Documentos apos o balanceamento DSW ===\n");
    exibir_em_ordem(raiz);

    return 0;
}