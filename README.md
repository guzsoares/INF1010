# INF1010
Trabalho 1 de estrutura de dados avançados

Nota final: ??/10

Autores:    Gustavo Molina Soares,
            Leo Land Bairos Lomardo

## Lista heterogênea

O objetivo do trabalho é implementar, na linguagem C, uma função que cria um array de structs de figuras geometricas e algumas funções para manipular esse array, tais como:
- `retiraLista`: retira um elemento da lista
- `imprimeLista`: imprime a lista inteira junto com sua área e perímetro
- `buscaLista`: busca um elemento na lista de acordo com seu index

As structs criadas foram as seguintes:

- `struct triangulo`: recebe um float b, onde b é o tamanho da base
- `struct hexogono`: recebe um float b, onde b é o tamanho da base
- `struct retangulo`: recebe um float b e um float h, onde b é o tamanho da base e h é o a altura
- `struct circulo`: recebe um float r, onde r é o tamanho do raio
- `struct quadrado`: recebe um float b, onde b é o tamanho da base

## Como compilar o código

```
gcc -Wall -o t1 t1.c
./t1
```
