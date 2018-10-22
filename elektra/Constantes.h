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
ALLEGRO_BITMAP *IMAGEM_PERSONAGEM = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *botao_sair = NULL, *area_jogar = 0;
ALLEGRO_EVENT evento;
ALLEGRO_TIMEOUT timeout;
ALLEGRO_AUDIO_STREAM *theme = NULL;
ALLEGRO_AUDIO_STREAM *starting = NULL;
ALLEGRO_SAMPLE *somefeitos = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_FONT *fonteSpace = NULL;



// Definição das telas
#define MENU_PRINCIPAL 1;
#define TELA_OPCOES 2;
#define FASE_PANTANO 3;
#define FASE_CIDADE 4;
#define FASE_REINO 5;
#define TELA_TUTORIAL 6;

// CARDS



//Struct para declaração de posições
typedef struct
{
	double x[10], y[10];
	int jacareAndando;

} Posicoes;


