# Contas a pagar
## Prova Fase 1 – OBI2023 
\
Vô João está aposentado, tem boa saúde, mas a vida não está fácil. Todo mês é um sufoco para
conseguir pagar as contas! Ainda bem que ele é muito amigo dos donos das lojas do bairro, e eles
permitem que ele fique devendo.
Depois de pagar aluguel, conta de luz, conta de água, conta do telefone celular e conta do mercado,
Vô João ainda tem que pagar as contas do Açougue, da Farmácia e da Padaria.
Dados o valor que Vô João tem disponível e o valor das contas do Açougue, Farmácia e Padaria,
escreva um programa para determinar quantas contas, entre as três que ainda não foram pagas, Vô
João consegue pagar.

### **Entrada:**
A entrada contém quatro linhas. A primeira linha contém um inteiro V , o valor que Vô João tem
disponível para pagar as contas. A segunda linha contém um inteiro A, o valor da conta do Açougue.
A terceira linha contém um inteiro F, o valor da conta da Farmácia. A quarta linha contém um
inteiro P, o valor da conta da Padaria.

### **Saída:**
Seu programa deve produzir uma única linha, contendo um único inteiro, o maior número de contas
que Vô João consegue pagar.

### **Restrições:**
• 0 ≤ V ≤ 2 000 \
• 1 ≤ A ≤ 1 000 \
• 1 ≤ F ≤ 1 000 \
• 1 ≤ P ≤ 1 000 

### **Informações sobre a pontuação:**
• A tarefa vale 100 pontos. 

### **Exemplos:**
| Exemplo de entrada 1 | Saída |
| --- | --- | 
| 100 | 3 |
| 30 |
| 40 |
| 30 |

*Explicação do exemplo 1: o valor total das contas é 40 + 30 + 30 = 100 e o valor disponível é
100, então Vô João consegue pagar as três contas.*


| Exemplo de entrada 2 | Saída | 
| --- | --- |
|50|0|
|82|
|99|
|51|

*Explicação do exemplo 2: o valor que Vô João tem é menor do que o valor de qualquer uma
das contas, então ele não consegue pagar nenhuma delas.*

|Exemplo de entrada 3| Saída |
| --- | --- |
|200| 1 |
|180|
|100|
|120|

*Explicação do exemplo 3: com 200 disponível para pagar as contas, Vô João só consegue pagar
uma das contas.*

|Exemplo de entrada 4|Saída|
|---|---|
|200|2|
|100|
|180|
|90|

*Explicação do exemplo 4: com 200 disponível para pagar as contas, Vô João consegue pagar
ou apenas a conta da Farmácia (que custa 180), ou as contas do Açougue e da Padaria (que
custam 100 + 90 = 190). Portanto Vô João consegue pagar duas contas.*