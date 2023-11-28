# Desafio_EscadaRolante

## Integrantes do Grupo:
Rodrigo Mironiuc Fernandes - 32274823;
Mauricio Gabriel Gutierrez Garcia - 32266601;


## Instruções:
1) Instalar git e gcc

2) Clonar o repositório :`https://github.com/rodmironiuc/Desafio_EscadaRolante`

3) Compilar o arquivo : 
`gcc escadaRolante.c -o escadaRolanteExe `

4) Executar os arquivo criados (esse formato possibilita com que o professor escolha o teste a ser realizado na hora de rodar):
`./escadaRolanteExe <nomeArquivoEntrada>`


## Explicação:
Para resolver o problema proposto nosso grupo desenvolveu a seguinte estratégia:
Primeiro, criamos uma estrutura `Passageiro` que serve para armazenar as informações de cada passageiro, sendo o tempo de chegada e a direção que deseja ir na escada. 
Em seguida, implementamos o método entrada para extrair a quantidade de passageiros e suas especificações do arquivo de entrada (`entrada.txt`).
Por fim, criamos o método principal do programa, o método escadaRolante, que recebe como parametro um vetor de Passageiros e a quantidade total, e realiza a simulação da escada da forma que queremos. Funciona da seguinte maneira: processamos os passageiros na ordem que chegam, sendo que se um passageiro chega e a escada estiver indo na mesma direção, o passageiro será incluído na mesma hora.
Caso o contrário, o passageiro é colocado em uma fila de passageiros pendentes. Agora, se houver passageiros pendentes e a escada rolante não tiver processando mais passageiros do lado atual, ela muda a direção e começa a processar os passageiros pendentes, repetindo o mesmo processo.
Quando não houver mais nenhum passageiro a ser processado, então terminamos a lista e a função retorna o momentoFinal, que foi todo o tempo necessário para resolver o problema(que foi sendo atualizado dentro das iterações).
O grupo acredita que foi uma boa maneira de resolver o problema, mas poderia talvez ter sido feito de maneira mais eficiente, caso tivessemos utilizado threads para processar mais de um passageiro ao mesmo tempo. Porém, não entendemos como isso poderia ser aplicado dentro desse contexto da escada rolante, que teoricamente lida com um passageiro por vez. 

## Alguns testes selecionados:
