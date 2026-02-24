# ALGORITMOS EM ÁRVORES BINÁRIAS E AVL - Desafio TreeMaster Quest 🌳📚

Boas-vindas ao desafio **TreeMaster Quest**! Você foi contratado pela **CodeForest Solutions**, uma empresa líder mundial em sistemas de alta performance. Sua missão é dar os primeiros passos na modernização do sistema de indexação de uma das maiores bibliotecas digitais do planeta, que conta com mais de 50 milhões de documentos acadêmicos.

Para garantir buscas eficientes e escalabilidade, você desenvolverá o núcleo desse sistema utilizando **Árvores Binárias de Busca (BST)** e **Árvores AVL**.

O desafio está dividido em três níveis: **Novato**, **Aventureiro** e **Mestre**. Cada nível exige a implementação de técnicas de balanceamento mais sofisticadas. Escolha seu caminho e construa a base do nosso novo sistema!

### 🚨 Atenção: 
O nível **Novato** é o ponto de partida. Nele, o foco é construir a estrutura básica da árvore binária, inserir dados e realizar a leitura utilizando o percurso em-ordem, sem se preocupar ainda com o balanceamento.

---

## 🎮 Nível Novato: Construção da Base da Biblioteca

Sua primeira tarefa na CodeForest é criar a fundação do sistema. Você deve organizar os documentos pela sua chave única (ID) em uma Árvore Binária de Busca padrão.

### 🚩 Objetivo:
- Criar a estrutura da árvore, inserir dois documentos e exibi-los ordenados pelo ID.

### ⚙️ Funcionalidades do Sistema:
- **Estrutura de Dados:** Criar uma `struct` representando um nó da árvore contendo: `ID` (int), `Título` (string), `Autor` (string), `Ano de publicação` (int), e os ponteiros para os filhos `esquerdo` e `direito`.
- **Operação:** Implementar a função de **inserção** na árvore binária (mantendo a regra: menores à esquerda, maiores à direita).
- **Exibição:** Implementar o **percurso em-ordem** para imprimir os documentos cadastrados em ordem crescente de ID.

### 📥 Entrada e 📤 Saída de Dados:
- **Entrada:** Dados de 2 documentos via código ou teclado.
- **Saída:** O sistema deverá imprimir os documentos ordenados, um por linha, de forma clara (ID, Título, Autor, Ano).

---

## 🛡️ Nível Aventureiro: Otimização com Algoritmo DSW

Uma árvore desbalanceada pode degradar a performance do sistema de $O(\log n)$ para $O(n)$. Para evitar isso, você deve implementar uma rotina de balanceamento sob demanda.

### 🆕 Diferenças em relação ao Nível Novato:
- **Algoritmo de Balanceamento:** Implementar o algoritmo **Day-Stout-Warren (DSW)**, que transforma a árvore em uma "vine" (espinha) e depois a balanceia perfeitamente usando rotações.
- **Métricas:** Criar uma função para calcular a **altura da árvore** (número de níveis).
- **Saída:** Além de imprimir os documentos ordenados, o sistema deve imprimir a *altura da árvore ANTES* do balanceamento DSW e a *altura DEPOIS* do balanceamento.

---

## 🏆 Nível Mestre: Otimização Suprema com Árvores AVL

O sistema cresceu e não podemos mais depender de balanceamentos manuais. A exigência agora é que a árvore se auto-balanceie a cada inserção. Você implementará a poderosa Árvore AVL e fará um comparativo de performance com o DSW.

### 🆕 Diferenças em relação ao Nível Aventureiro:
- **Estrutura de Dados Atualizada:** O `ID` do documento deve passar a ser do tipo `unsigned long int` para suportar chaves maiores. O nó da árvore deve incluir uma variável para a `altura` ou `fator de balanceamento`.
- **Algoritmo Principal:** Implementar as rotações (LL, RR, LR, RL) e a **inserção AVL** para balanceamento automático.
- **Fallback e Comparação:** Manter o DSW como opção manual e comparar o desempenho das duas táticas baseando-se em:
  - *Altura da árvore* (Vence quem tiver menor).
  - *Número de rotações* (Vence quem usar menos).
  - *Tempo de execução* (Vence quem for mais rápido).

### 📤 Saída de Dados:
- Ao final, exibir um relatório de comparação informando qual método foi superior em cada métrica, formatando a saída como `1` (se AVL venceu) ou `0` (se DSW venceu). Ex: `Tempo de execução: AVL venceu (1)`.

---

💡 **Dica do Professor:** Árvores e ponteiros exigem atenção aos detalhes! Faça desenhos no papel de como os nós estão se conectando, principalmente na hora de implementar as rotações do nível Mestre e a transformação em "vine" do nível Aventureiro. Lembre-se de liberar a memória alocada ao final do programa!

Boa sorte e que o código esteja com você! 🚀
