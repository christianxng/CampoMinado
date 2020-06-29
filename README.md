# CampoMinado

Campo minado é um popular jogo de computador para um jogador. Foi inventado por Robert
Donner em 1989 e tem como objetivo revelar um campo de minas sem que alguma seja
detonada. Este jogo tem sido reescrito para as mais diversas plataformas, sendo a sua versão
mais popular a que vinha nativamente em edições do Windows.
(Fonte: https://pt.wikipedia.org/wiki/Campo_minado)

## Regras do Jogo
A área de jogo consiste em um campo de quadrados retangular. Cada quadrado pode ser
revelado digitando suas respectivas coordenadas, e se o quadrado selecionado contiver uma mina, então o jogo acaba.
Se, por outro lado, o quadrado não contiver uma mina, uma de duas coisas poderá acontecer:

<p> 1. Um número aparece, indicando a quantidade de quadrados adjacentes que contêm
minas; </p>
<p> 2. Nenhum número aparece. Neste caso, o jogo revela automaticamente os
quadrados que se encontram adjacentes ao quadrado vazio, já que não podem
conter minas; </p>
O jogo é ganho quando todos os quadrados que não têm minas são revelados.
Opcionalmente, o jogador pode marcar qualquer quadrado que acredita que contém uma mina
com uma bandeira, bastando para isso, acessar a opção no menu,digitar suas coordenadas e nvamente digitar a letra B.

## Tabuleiro do Jogo
Para o tabuleiro os seguintes caracteres foram utilizados na representação:

<p> ● # : quadrado fechado </p>
<p> ● B: bandeira </p>
<p> ● * : bomba </p>
<p> ● - : quadrado aberto sem bomba adjacente </p>


# Desenvolvimento

Projeto foi desenvolvido em linguagem C.
