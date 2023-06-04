# Leilão
## Prova Fase 1 – OBI2023
\
Para arrecadar dinheiro para o Hospital da cidade, os alunos do Centro Acadêmico conseguiram
que o maior esportista nascido e criado na cidade, hoje um jogador de fama internacional, doasse
uma camiseta do seu time atual, autografada.
Os alunos então organizaram um leilão pela internet, aceitando lances pela camiseta, com a promessa
de que o lance de maior valor compraria a camiseta pelo valor oferecido. Cada lance é composto
pelo nome do interessado e o valor oferecido.
No entanto a notícia do leilão viralizou, e o número de lances foi muito grande. Sabendo que você
sabe resolver problemas usando o computador, os alunos do Centro Acadêmico pediram a sua ajuda
para processar os lances.
Dada a lista de lances, na ordem em que foram feitos, escreva um programa para determinar o lance
de maior valor. Se houver empate no valor, o lance que foi feito primeiro é o vencedor.

### **Entrada**
A primeira linha contém um inteiro N, o número de lances recebidos. A seguir são dados os N
lances, na ordem em que foram feitos. Cada lance é dado em duas linhas: a primeira linha contém
uma cadeia de caracteres C, o nome da pessoa que fez o lance; a segunda linha contém um inteiro
V , o valor do lance.

### **Saída**
Seu programa deve produzir duas linhas. A primeira linha deve conter o nome da pessoa que fez o
lance ganhador. A segunda linha deve conter o valor do lance ganhador.

### **Restrições**
• 0 ≤ N ≤ 10 000\
• C contém apenas letras maiúsculas e minúsculas, não acentuadas.\
• C contém no mínimo uma e no máximo 10 letras.\
• 1 ≤ V ≤ 100 000

### **Informações sobre a pontuação**
• A tarefa vale 100 pontos.\
• Para um conjunto de casos de testes valendo 16 pontos, C contém apenas uma letra.\
• Para um conjunto de casos de testes valendo outros 84 pontos, nenhuma restrição adicional.

### **Exemplos**
|Exemplo de entrada 1|Saída|
|---|---|
4 | Pedro
Leila | 250
200
Pedro
250
Clara
230
Eduardo
200

*Explicação do exemplo 1: Pedro fez o lance de maior valor, portanto é o vencedor.*

|Exemplo de entrada 2|Saída|
|---|---|
5 | Joana
Mateus | 2354
2000
Joana
2354
Eduardo
2354
Iara
2354
Michel
2300

*Explicação do exemplo 2: Há um empate entre os valores oferecidos por Joana, Eduardo e Iara, mas Joana é a vencedora porque foi a primeira a fazer um lance nesse valor.*