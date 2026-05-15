# Reprodutor de Músicas com Arduino

Este projeto tem como objetivo o desenvolvimento de um reprodutor de músicas utilizando o Arduino UNO, simulando o funcionamento básico de um player MP3.

O sistema permite ao usuário:

* Navegar entre músicas armazenadas
* Reproduzir músicas
* Pausar a execução
* Retornar ao menu principal

Além disso, o sistema utiliza LEDs para indicar o estado atual:

* LED verde: música em reprodução
* LED vermelho: música pausada

---

### Materiais Utilizados

* Arduino UNO
* Display LCD 16x2
* Buzzer (Piezo)
* 4 botões (UP, DOWN, PLAY/PAUSE, STOP)
* 2 LEDs (verde e vermelho)
* Resistores
* Jumpers

---

### Desenvolvimento

O projeto foi desenvolvido utilizando um sistema de controle de estados, onde variáveis são utilizadas para gerenciar o comportamento do programa durante a execução.

Nesse contexto, o sistema diferencia principalmente dois estados de reprodução:

* `TOCANDO` : reprodução ativa da música.
* `PAUSADO` : reprodução interrompida temporariamente.

O menu funciona como uma interface de navegação, sendo exibido quando não há música em execução.

Essa abordagem foi utilizada para evitar inconsistências na interface e facilitar o controle do fluxo do sistema.

As músicas foram armazenadas em vetores contendo:

* Frequências das notas musicais.
* Duração de cada nota.

Foi utilizada uma estrutura com arrays de ponteiros, permitindo reutilizar a lógica de reprodução para diferentes músicas, aumentando a escalabilidade do sistema.

O display LCD foi controlado utilizando a biblioteca `LiquidCrystal`, sendo responsável por:

* Exibir mensagem inicial
* Mostrar menu de seleção
* Informar estado da música (tocando/pausado)

---

## Imagem do Circuito
<div align="center">
  <img  width="600" height="405" alt="image" src="WhatsApp Image 2026-05-08 at 20.36.42.jpeg" />
</div>

<br>

## Imagens do projeto

###  Inicialização do Sistema

Ao iniciar, o display apresenta uma mensagem de boas-vindas:
<div align="center">
  <img width="600" height="405" alt="image" src="WhatsApp Image 2026-05-08 at 20.36.43 (1).jpeg" />
</div>

<br>

### Seleção de Músicas

O usuário pode navegar entre as músicas utilizando os botões UP e DOWN:
<div align="center">
  <img width="600" height="405" alt="image" src="WhatsApp Image 2026-05-08 at 20.36.42 (1).jpeg" />
</div>

<br>

### Reprodução

Ao pressionar o botão PLAY:

* A música começa a tocar no buzzer
* LED verde é ativado
<div align="center">
  <img width="600" height="405" alt="image" src="WhatsApp Image 2026-05-08 at 20.36.43.jpeg" />
</div>

<br>

### Pausa

Ao pressionar PLAY novamente:

* A música é pausada
* LED vermelho é ativado
  
<div align="center">
  <img width="600" height="405" alt="image" src="WhatsApp Image 2026-05-08 at 20.36.44.jpeg" />
</div>

<br>

### Retorno ao Menu

Ao pressionar STOP:

* O sistema retorna ao menu inicial


### Demonstração em Vídeo
Link para o video no youtube: https://youtu.be/7LqwHXfK1y4
Link demonstração:
---

## Tecnologias Utilizadas

* Linguagem C/C++ (Arduino)
* Arduino UNO
* Biblioteca LiquidCrystal
* Biblioteca Robson Couto de frequências
* Eletrônica básica (circuitos com LEDs, botões e buzzer) 


## Conclusão

O projeto atingiu todos os objetivos propostos, permitindo a reprodução de múltiplas músicas com controle completo por meio de botões físicos.

Durante o desenvolvimento, foram enfrentados desafios relacionados ao controle de estados e atualização do display LCD. Esses problemas foram resolvidos utilizando variáveis de controle de estado, garantindo consistência na interface e no comportamento do sistema.

Além disso, a utilização de arrays de ponteiros permitiu uma implementação mais organizada e escalável para o gerenciamento das músicas.

O projeto contribuiu significativamente para o aprendizado prático de:

* Manipulação de hardware com Arduino
* Estruturação de código com controle de estados


## Autores

Giovana Stofel Maia e Gabriel Matos Lourenço

