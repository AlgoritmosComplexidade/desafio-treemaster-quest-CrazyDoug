// Feito por Douglas Alves Costa
// Nivel MESTRE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct No {
    unsigned long int id;
    char titulo[100];
    char autor[50];
    int ano;
    int altura;
    struct No* esquerdo;
    struct No* direito;
} No;

long long rotacoes_avl = 0;
long long rotacoes_dsw = 0;

int maior(int a, int b) {
    return (a > b) ? a : b;
}

int altura_no(No* no) {
    if (no == NULL) {
        return 0;
    }
    return no->altura;
}

int calcular_altura(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + maior(calcular_altura(raiz->esquerdo),
                     calcular_altura(raiz->direito));
}

int fator_balanceamento(No* no) {
    if (no == NULL) {
        return 0;
    }

    return altura_no(no->esquerdo) - altura_no(no->direito);
}

No* criar_no(unsigned long int id, const char* titulo, const char* autor, int ano) {
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    novo->id = id;
    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    novo->ano = ano;
    novo->altura = 1;
    novo->esquerdo = NULL;
    novo->direito = NULL;

    return novo;
}

No* rotacao_direita_avl(No* y) {
    No* x = y->esquerdo;
    No* temp = x->direito;

    x->direito = y;
    y->esquerdo = temp;

    y->altura = 1 + maior(altura_no(y->esquerdo), altura_no(y->direito));
    x->altura = 1 + maior(altura_no(x->esquerdo), altura_no(x->direito));

    rotacoes_avl++;

    return x;
}

No* rotacao_esquerda_avl(No* x) {
    No* y = x->direito;
    No* temp = y->esquerdo;

    y->esquerdo = x;
    x->direito = temp;

    x->altura = 1 + maior(altura_no(x->esquerdo), altura_no(x->direito));
    y->altura = 1 + maior(altura_no(y->esquerdo), altura_no(y->direito));

    rotacoes_avl++;

    return y;
}

No* inserir_avl(No* raiz, No* novo_no) {
    if (raiz == NULL) {
        return novo_no;
    }

    if (novo_no->id < raiz->id) {
        raiz->esquerdo = inserir_avl(raiz->esquerdo, novo_no);
    } else if (novo_no->id > raiz->id) {
        raiz->direito = inserir_avl(raiz->direito, novo_no);
    } else {
        return raiz;
    }

    raiz->altura = 1 + maior(altura_no(raiz->esquerdo), altura_no(raiz->direito));

    int balanceamento = fator_balanceamento(raiz);

    // Caso LL
    if (balanceamento > 1 && novo_no->id < raiz->esquerdo->id) {
        return rotacao_direita_avl(raiz);
    }

    // Caso RR
    if (balanceamento < -1 && novo_no->id > raiz->direito->id) {
        return rotacao_esquerda_avl(raiz);
    }

    // Caso LR
    if (balanceamento > 1 && novo_no->id > raiz->esquerdo->id) {
        raiz->esquerdo = rotacao_esquerda_avl(raiz->esquerdo);
        return rotacao_direita_avl(raiz);
    }

    // Caso RL
    if (balanceamento < -1 && novo_no->id < raiz->direito->id) {
        raiz->direito = rotacao_direita_avl(raiz->direito);
        return rotacao_esquerda_avl(raiz);
    }

    return raiz;
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

        printf("ID: %lu | Titulo: %s | Autor: %s | Ano: %d\n",
               raiz->id,
               raiz->titulo,
               raiz->autor,
               raiz->ano);

        exibir_em_ordem(raiz->direito);
    }
}

void rotacao_direita_dsw(No** raiz) {
    No* filho = (*raiz)->esquerdo;
    (*raiz)->esquerdo = filho->direito;
    filho->direito = *raiz;
    *raiz = filho;

    rotacoes_dsw++;
}

void rotacao_esquerda_dsw(No** raiz) {
    No* filho = (*raiz)->direito;
    (*raiz)->direito = filho->esquerdo;
    filho->esquerdo = *raiz;
    *raiz = filho;

    rotacoes_dsw++;
}

int criar_vine(No** raiz) {
    int contador = 0;
    No** atual = raiz;

    while (*atual != NULL) {
        if ((*atual)->esquerdo != NULL) {
            rotacao_direita_dsw(atual);
        } else {
            contador++;
            atual = &((*atual)->direito);
        }
    }

    return contador;
}

void compactar_vine(No** raiz, int quantidade) {
    No** atual = raiz;

    for (int i = 0; i < quantidade; i++) {
        if (*atual != NULL && (*atual)->direito != NULL) {
            rotacao_esquerda_dsw(atual);
            atual = &((*atual)->direito);
        }
    }
}

int maior_potencia_menos_um(int n) {
    int x = 1;

    while (x <= n) {
        x = x * 2;
    }

    return (x / 2) - 1;
}

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

void liberar_arvore(No* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerdo);
        liberar_arvore(raiz->direito);
        free(raiz);
    }
}

int main() {
    printf("=== CODEFOREST SOLUTIONS - TREEMASTER QUEST ===\n");
    printf("=== NIVEL MESTRE - AVL VS DSW ===\n\n");

    unsigned long int ids[] = {
        1001, 1002, 1003, 1004, 1005,
        1006, 1007, 1008, 1009, 1010
    };

    char titulos[][100] = {
        "Introducao a programacao",
        "Estruturas de dados avancadas",
        "Banco de Dados",
        "Redes de Computadores",
        "Sistemas Operacionais",
        "Inteligencia Artificial",
        "Engenharia de Software",
        "Computacao em Nuvem",
        "Seguranca da Informacao",
        "Arquitetura de Software"
    };

    char autores[][50] = {
        "Joao Silva",
        "Maria Oliveira",
        "Carlos Mendes",
        "Ana Souza",
        "Marcos Lima",
        "Fernanda Rocha",
        "Paulo Costa",
        "Juliana Martins",
        "Ricardo Alves",
        "Beatriz Fernandes"
    };

    int anos[] = {
        2020, 2023, 2021, 2019, 2022,
        2024, 2020, 2021, 2023, 2024
    };

    int total = 10;

    No* raiz_avl = NULL;
    No* raiz_dsw = NULL;

    clock_t inicio_avl = clock();

    for (int i = 0; i < total; i++) {
        raiz_avl = inserir_avl(
            raiz_avl,
            criar_no(ids[i], titulos[i], autores[i], anos[i])
        );
    }

    clock_t fim_avl = clock();

    clock_t inicio_dsw = clock();

    for (int i = 0; i < total; i++) {
        raiz_dsw = inserir_bst(
            raiz_dsw,
            criar_no(ids[i], titulos[i], autores[i], anos[i])
        );
    }

    raiz_dsw = dsw_balancear(raiz_dsw);

    clock_t fim_dsw = clock();

    double tempo_avl = ((double)(fim_avl - inicio_avl)) / CLOCKS_PER_SEC;
    double tempo_dsw = ((double)(fim_dsw - inicio_dsw)) / CLOCKS_PER_SEC;

    int altura_avl = calcular_altura(raiz_avl);
    int altura_dsw = calcular_altura(raiz_dsw);

    printf("=== Documentos cadastrados na AVL ===\n");
    exibir_em_ordem(raiz_avl);

    printf("\n=== Documentos cadastrados na DSW ===\n");
    exibir_em_ordem(raiz_dsw);

    printf("\n=== RELATORIO DE PERFORMANCE ===\n\n");

    printf("Altura AVL: %d\n", altura_avl);
    printf("Altura DSW: %d\n", altura_dsw);

    printf("\nRotacoes AVL: %lld\n", rotacoes_avl);
    printf("Rotacoes DSW: %lld\n", rotacoes_dsw);

    printf("\nTempo AVL: %.8f segundos\n", tempo_avl);
    printf("Tempo DSW: %.8f segundos\n", tempo_dsw);

    printf("\n=== COMPARATIVO FINAL ===\n");

    if (altura_avl < altura_dsw) {
        printf("Altura da arvore: AVL venceu (1)\n");
    } else {
        printf("Altura da arvore: DSW venceu (0)\n");
    }

    if (rotacoes_avl < rotacoes_dsw) {
        printf("Numero de rotacoes: AVL venceu (1)\n");
    } else {
        printf("Numero de rotacoes: DSW venceu (0)\n");
    }

    if (tempo_avl < tempo_dsw) {
        printf("Tempo de execucao: AVL venceu (1)\n");
    } else {
        printf("Tempo de execucao: DSW venceu (0)\n");
    }

    liberar_arvore(raiz_avl);
    liberar_arvore(raiz_dsw);

    return 0;
}