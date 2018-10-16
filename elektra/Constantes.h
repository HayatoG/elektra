#include<allegro5/allegro.h>
//Arquivo para declara��o de CONSTANTES do SmartGator
//Constantes devem ser declaradas com letras maiusculas
// Atributos da tela

const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

//Declara��o das constantes de fun��es Allegro
extern ALLEGRO_DISPLAY *janela = NULL;
extern ALLEGRO_BITMAP *IMAGEM_SPLASHSCREEN = NULL;
extern ALLEGRO_BITMAP *IMAGEM_MENUINICIAL = NULL;
extern ALLEGRO_BITMAP *IMAGEM_TELAOPCOES = NULL;
extern ALLEGRO_BITMAP *IMAGEM_FASE1 = NULL;
extern ALLEGRO_BITMAP *IMAGEM_FASE2 = NULL;
extern ALLEGRO_BITMAP *IMAGEM_FASE3 = NULL;
extern ALLEGRO_BITMAP *IMAGEM_CARD = NULL;
extern ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
extern ALLEGRO_BITMAP *botao_sair = NULL, *area_jogar = 0;
extern ALLEGRO_EVENT evento;
extern ALLEGRO_TIMEOUT timeout;
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
struct Posicoes
{
	double x, y, x0, y0;
	int jacareAndando;

};



