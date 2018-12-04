#include<allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
// Atributos da tela
const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;
//Constantes devem ser declaradas com letras maiusculas


ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_BITMAP *IMAGEM_SPLASHSCREEN = NULL;
ALLEGRO_BITMAP *IMAGEM_MENUINICIAL = NULL;
ALLEGRO_BITMAP *IMAGEM_TELAOPCOES = NULL;
ALLEGRO_BITMAP *IMAGEM_FASE1 = NULL;
ALLEGRO_BITMAP *IMAGEM_FASE2 = NULL;
ALLEGRO_BITMAP *IMAGEM_FASE3 = NULL;
ALLEGRO_BITMAP *IMAGEM_CARD = NULL;
ALLEGRO_BITMAP *IMAGEM_CREDITOS = NULL;
ALLEGRO_BITMAP *IMAGEM_PERSONAGEM = NULL;
ALLEGRO_BITMAP *IMAGEM_CASTELO = NULL;
ALLEGRO_BITMAP *IMAGEM_TELAFINAL = NULL;
ALLEGRO_BITMAP *IMAGEM_AVISO = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *botao_sair = NULL, *area_jogar = 0;
ALLEGRO_EVENT evento;
ALLEGRO_TIMEOUT timeout;
ALLEGRO_AUDIO_STREAM *theme = NULL;
ALLEGRO_AUDIO_STREAM *starting = NULL;
ALLEGRO_SAMPLE *somefeitos = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_FONT *fonteSpace = NULL;
ALLEGRO_FONT *fonteCard = NULL;
ALLEGRO_FONT *fonteCardPergunta = NULL;




// Definição das telas
#define MENU_PRINCIPAL 1;
#define TELA_OPCOES 2;
#define FASE_PANTANO 3;
#define FASE_CIDADE 4;
#define FASE_REINO 5;
#define TELA_TUTORIAL 6;
#define TELA_CREDITOS 7;
#define TELA_FINAL 8;

// CARDS
#define X_INICIAL_RESPOSTA 540;
#define X_FINAL_RESPOSTA 750;
#define Y_INICIAL_A 380;
#define Y_FINAL_A 430;
#define Y_INICIAL_B 480;
#define Y_FINAL_B 530;
#define Y_INICIAL_C 580;
#define Y_FINAL_C 630;

//Struct para declaração de posições
typedef struct structCards {
	char perguntas[550];
	char resposta1[150];
	char resposta2[150];
	char resposta3[150];
	int y1_certo;
	int y2_certo;
}structCards;

typedef struct structPosicoes {
	int posicao_x;
	int posicao_y;
} structPosicoes;

const int x_inicial_resposta = X_INICIAL_RESPOSTA;
const int x_final_resposta   = X_FINAL_RESPOSTA;
const int y_inicial_a        = Y_INICIAL_A;
const int y_final_a          = Y_FINAL_A;
const int y_inicial_b        = Y_INICIAL_B;
const int y_final_b			 = Y_FINAL_B;
const int y_inicial_c		 = Y_INICIAL_C;
const int y_final_c			 = Y_FINAL_C;

/*const int pantanoX[] = { 0, 140, 340, 515, 640, 880, 1070 };
const int pantanoY[] = { 415, 280, 260, 210, 120, 120, 70 };
const int cidadeX[] = { 20,  200, 380, 500, 650, 790, 955, 1040 };
const int cidadeY[] = { 207, 207, 207, 135, 70, 70, 70, 5 };
const int reinoX[] = { -13, 130, 260, 790 };
const int reinoY[] = { -30, -30, 30, 330 };*/


