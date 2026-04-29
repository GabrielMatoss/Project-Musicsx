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

void tocarMusica(){

}

void  mostrarMenu(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Selecione:");

  lcd.setCursor(0,1);
  lcd.print(nomes[musicaAtual]);
}

void lerMenu() {
 // next
  if(digitalRead(BTN_UP) == HIGH) {
    musicaAtual++;
    if(musicaAtual > 4) {
        musicaAtual = 0;
    }
    delay(200);
  }

  // back
  if(digitalRead(BTN_DOWN) == HIGH) {
    musicaAtual--;
    if(musicaAtual < 0) {
        musicaAtual = 4;
    }
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
}

void loop() {
  lerMenu();
  tocarMusica();
}
