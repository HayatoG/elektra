#include<allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
//Arquivo para declara��o de CONSTANTES do SmartGator
//Constantes devem ser declaradas com letras maiusculas
// Atributos da tela

const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

//Declara��o das constantes de fun��es Allegro
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_BITMAP *IMAGEM_SPLASHSCREEN = NULL;
ALLEGRO_BITMAP *IMAGEM_MENUINICIAL = NULL;
ALLEGRO_BITMAP *IMAGEM_TELAOPCOES = NULL;
ALLEGRO_BITMAP *IMAGEM_FASE1 = NULL;
ALLEGRO_BITMAP *IMAGEM_FASE2 = NULL;
ALLEGRO_BITMAP *IMAGEM_FASE3 = NULL;
ALLEGRO_BITMAP *IMAGEM_CARD = NULL;
ALLEGRO_BITMAP *IMAGEM_PERSONAGEM = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *botao_sair = NULL, *area_jogar = 0;
ALLEGRO_EVENT evento;
ALLEGRO_TIMEOUT timeout;
ALLEGRO_FONT *fonte = NULL;

// Defini��o das telas
#define MENU_PRINCIPAL 1;
#define TELA_OPCOES 2;
#define FASE_PANTANO 3;
#define FASE_CIDADE 4;
#define FASE_REINO 5;
#define TELA_TUTORIAL 6;

// CARDS



//Struct para declara��o de posi��es
typedef struct
{
	double x[10], y[10];
	int jacareAndando;

} Posicoes;



