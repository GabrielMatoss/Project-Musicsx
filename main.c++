#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

#define BTN_UP 9

#define BTN_DOWN 8

#define BTN_PLAY 10

#define BTN_STMENU 11

#define LED_PLAY 13

#define LED_STOP A1

#define BUZZER 12

/*mario
*/

int estadoMusica = 0;

int ultimoEstado = -1;//força a atualizar o lcd

int ultimaMusica = -1;

int musicaAtual = 0;

char nomes[5][16] = {

"Mario",

"Zelda",

"Tetris",

"Pokemon",

"StarWars"

};

int mario[] = {

660,660,0,660,0,520,660,0,780,0,392,

0,523,392,330,440,494,466,440,392,

660,660,660,

523,523,523,

330

};

int duracaoMario[] = {

100,100,100,100,100,100,100,100,300,100,300,

100,300,150,300,200,200,200,200,400,

120,120,120,

120,120,120,

800

};

int zelda[] = {

659, 698, 784, 880, 784, 698, 659,

587, 659, 698, 784, 698, 659,

523, 587, 659, 587, 523

};

int duracaoZelda[] = {

200,200,200,400,200,200,300,

200,200,200,400,200,200,

200,200,400,200,400

};

int tetris[] = {

659,494,523,587,523,494,440,

440,523,659,587,523,494,

523,587,659,523,440

};

int duracaoTetris[] = {

150,150,150,150,150,150,300,

150,150,300,150,150,300,

150,150,300,200,400

};

int pokemon[] = {

392,392,440,392,523,494,

392,392,440,392,587,523

};

int duracaoPokemon[] = {

200,200,200,200,300,400,

200,200,200,200,300,400

};

int starwars[] = {

440,440,440,349,523,440,

349,523,440,

659,659,659,698,523,415,349

};

int duracaoStarWars[] = {

300,300,300,200,100,400,

200,100,500,

300,300,300,200,100,200,500

};

int* musicas[] = {mario, zelda, tetris, pokemon, starwars};

int* duracoes[] = {duracaoMario, duracaoZelda, duracaoTetris, duracaoPokemon, duracaoStarWars};

int tamanhos[] = {27, 18, 18, 12, 16};

void setup() {

lcd.begin(16,2);

pinMode(BTN_UP, INPUT);

pinMode(BTN_DOWN, INPUT);

pinMode(BTN_PLAY, INPUT);

pinMode(BTN_STMENU, INPUT);

pinMode(LED_PLAY, OUTPUT);

pinMode(LED_STOP, OUTPUT);

pinMode(BUZZER, OUTPUT);

telaInicial();

mostrarMenu();

}

void telaInicial() {

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Bem vindo ao");

lcd.setCursor(0,1);

lcd.print("Music Fei");

delay(2000);

}

void mostrarMenu() {

lcd.clear();

lcd.setCursor(0,0);

lcd.print("Selecione:");

lcd.setCursor(0,1);

lcd.print(nomes[musicaAtual]);

}

void tocar_musica(){

// atualiza o LCD só Quando muda)

//utilizei algumas variaveis de "estado" pois estava

//dando bugs de visualização

if(estadoMusica != ultimoEstado || musicaAtual != ultimaMusica){

```
lcd.clear();

if(estadoMusica == 1) {
  lcd.setCursor(0,0);
  lcd.print("Tocando:");
  lcd.setCursor(0,1);
  lcd.print(nomes[musicaAtual]);
}
else if(estadoMusica == 2) {
  lcd.setCursor(0,0);
  lcd.print("Pausado:");
  lcd.setCursor(0,1);
  lcd.print(nomes[musicaAtual]);
}
else {
	lcd.setCursor(0,0);
	lcd.print("Selecione:");
	lcd.setCursor(0,1);
	lcd.print(nomes[musicaAtual]);
}

ultimoEstado = estadoMusica;
ultimaMusica = musicaAtual;
```

}

if(estadoMusica == 1) {//tocando

digitalWrite(LED_PLAY, HIGH);

digitalWrite(LED_STOP, LOW);

}

else if(estadoMusica == 2) {//pausado

digitalWrite(LED_PLAY, LOW);

digitalWrite(LED_STOP, HIGH);

}

else {//nadinha

digitalWrite(LED_PLAY, LOW);

digitalWrite(LED_STOP, LOW);

}

}

void lerMenu() {

// next

if(digitalRead(BTN_UP) == HIGH) {

musicaAtual++;

if(musicaAtual > 4) musicaAtual = 0;

// mostrarMenu();

delay(200);

}

// back(é assim que escreve anterior em ingles?)

if(digitalRead(BTN_DOWN) == HIGH) {

musicaAtual--;

if(musicaAtual < 0) musicaAtual = 4;

//mostrarMenu();

delay(200);

}

//play e pause

if(digitalRead(BTN_PLAY) == HIGH) {

if(estadoMusica == 0) {

estadoMusica = 1; // começa a tocar

}

else if(estadoMusica == 1) {

estadoMusica = 2; // pausa

}

else if(estadoMusica == 2) {

estadoMusica = 1; // volta a tocar

}

delay(300);

}

//volta ao menu de boas vindas

if(digitalRead(BTN_STMENU) == HIGH) {

estadoMusica = 0;

digitalWrite(LED_PLAY, LOW);

digitalWrite(LED_STOP, LOW);

telaInicial();   // volta pro "Bem vindo"

mostrarMenu();   // depois menu

delay(300);

}

if(digitalRead(BTN_STMENU) == HIGH) {

estadoMusica = 0;

noTone(BUZZER);

musica();

delay(300);

}

}

bool musica() {

int tamanho = tamanhos[musicaAtual];

for(int i = 0; i < tamanho; i++) {

```
if(digitalRead(BTN_PLAY) == HIGH) {
estadoMusica = 2;
noTone(BUZZER);

digitalWrite(LED_PLAY, HIGH);
digitalWrite(LED_STOP, LOW);

delay(300);
return false;
}

if(digitalRead(BTN_STMENU) == HIGH) {
    estadoMusica = 0;
    noTone(BUZZER);
    digitalWrite(LED_PLAY, LOW);
    digitalWrite(LED_STOP, HIGH);
    delay(300);

}

tone(BUZZER, musicas[musicaAtual] [i]);   // (corrigi aqui também!)
delay(duracoes[musicaAtual][i]);
noTone(BUZZER);
delay(50);
```

}

return true;

}

void loop() {

lerMenu();

tocar_musica();

if(estadoMusica == 1){

musica();

}

}