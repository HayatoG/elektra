#include<allegro5/allegro.h>
//Arquivo para declaração de CONSTANTES do SmartGator
//Constantes devem ser declaradas com letras maiusculas
// Atributos da tela

const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

//Declaração das constantes de funções Allegro
extern ALLEGRO_DISPLAY *janela = NULL;
extern ALLEGRO_BITMAP *IMAGEM_SPLASHSCREEN = NULL;
extern ALLEGRO_BITMAP *IMAGEM_MENUINICIAL = NULL;
extern ALLEGRO_BITMAP *IMAGEM_TELAOPCOES = NULL;
extern ALLEGRO_BITMAP *IMAGEM_TELA1 = NULL;
extern ALLEGRO_BITMAP *IMAGEM_TELA2 = NULL;
extern ALLEGRO_BITMAP *IMAGEM_TELA3 = NULL;
extern ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
extern ALLEGRO_BITMAP *botao_sair = NULL, *area_jogar = 0;
extern ALLEGRO_EVENT evento;
extern ALLEGRO_TIMEOUT timeout;



