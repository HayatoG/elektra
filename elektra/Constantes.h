#include<allegro5/allegro.h>
<<<<<<< HEAD
//Arquivo para declaração de CONSTANTES do SmartGator
=======
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
//Arquivo para declara��o de CONSTANTES do SmartGator
>>>>>>> SMARTGATOR-4
//Constantes devem ser declaradas com letras maiusculas

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
// Atributos da tela
const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

//Declaração das constantes de funções Allegro
extern ALLEGRO_DISPLAY *janela = NULL;
extern ALLEGRO_BITMAP *IMAGEM_SPLASHSCREEN = NULL;
extern ALLEGRO_BITMAP *IMAGEM_MENUINICIAL = NULL;
extern ALLEGRO_BITMAP *IMAGEM_TELAOPCOES = NULL;
extern ALLEGRO_BITMAP *IMAGEM_FASE1 = NULL;
extern ALLEGRO_BITMAP *IMAGEM_FASE2 = NULL;
extern ALLEGRO_BITMAP *IMAGEM_FASE3 = NULL;
extern ALLEGRO_BITMAP *IMAGEM_CARD = NULL;
extern ALLEGRO_BITMAP *IMAGEM_PERSONAGEM = NULL;
extern ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
extern ALLEGRO_BITMAP *botao_sair = NULL, *area_jogar = 0;
extern ALLEGRO_EVENT evento;
extern ALLEGRO_TIMEOUT timeout;
<<<<<<< HEAD
extern ALLEGRO_AUDIO_STREAM *musica = NULL;
extern ALLEGRO_SAMPLE *somefeitos = NULL;
=======
extern ALLEGRO_FONT *fonte = NULL;

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
>>>>>>> SMARTGATOR-4

#define Tela1 = MenuInicial;
#define Tela2 = Opcoes;
#define Tela3 = Tutorial;
#define Tela4 = Fase1;
#define Tela5 = Fase2;
#define Tela6 = Fase3;

