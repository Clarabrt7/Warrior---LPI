
Warrior Combat


### `Warrior`
2 Guerreios: Aquiles e Perseu

```plaintext
+---------------------+
|     Warrior         |
+---------------------+
| - nome              |
| - hp                |
| - ataque()          |
| - defesa()          |
| - cura()            |
+---------------------+
```

### `Dado`
Irá decidir qual jogador inicia o combate no início de cada rodada

```plaintext
+---------------------+
|      Dado           |
+---------------------+
| - rolar()           | -> Ímpar, Par
+---------------------+
```

### `Arena`
Lista os guerreiros
Gerencia e guarda as ações deles

```plaintext
+---------------------+
|      Arena          |
+---------------------+
| - local             |
| - W1        |
| - W2        |
| - historicoAcoes[]  |
| - iniciarCombate()  |
+---------------------+
```

---

## ⚔️ Fluxo do Combate

```
(O jogo ficará em loop até que um jogador ter HP = 0 )

    A[Início do Combate] --> B[Rolar o dado para decidir quem começa]
    B --> C[Jogador 1 realiza uma ação]
    C --> D[Jogador 2 responde com a melhor ação]
    D --> E[Verifica se algum jogador tem HP = 0]
    E --> |Não| C
    E --> |Sim| F[Detecta que só há um vivo]
    F --> G[Fim do Jogo - Exibe o vencedor]
```

---
