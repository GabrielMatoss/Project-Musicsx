#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

#define BTN_UP 9
#define BTN_DOWN 8
#define BTN_PLAY 10
#define BTN_STMENU 11
#define LED_PLAY 13
#define LED_STOP A1
#define BUZZER 12


int estadoMusica = 0;
int ultimoEstado = -1;//força a atualizar o lcd
int ultimaMusica = -1;

char nomes[5][16] = {
  "Mario",
  "Zelda",
  "Tetris",
  "Pokemon",
  "StarWars"
};

void setup() {
  lcd.begin(16,2);

  pinMode(BTN_UP, INPUT);
  pinMode(BTN_DOWN, INPUT);
  pinMode(BTN_PLAY, INPUT);
  pinMode(BTN_STMENU, INPUT);
  pinMode(LED_PLAY, OUTPUT);
  pinMode(LED_STOP, OUTPUT);
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

void tocar_musica(){

}

void  mostrarMenu(){

}
void lerMenu() {}

void loop() {
  lerMenu();
  tocar_musica();
}
