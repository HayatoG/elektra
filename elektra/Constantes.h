//Aruqivo para declaração de CONSTANTES do SmartGator
//Constantes devem ser declaradas com letras maiusculas

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
// Atributos da tela
const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

//Declaração das constantes de funções Allegro
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_BITMAP *IMAGEM_SPLASHSCREEN = NULL;
ALLEGRO_BITMAP *IMAGEM_MENUINICIAL = NULL;
ALLEGRO_BITMAP *IMAGEM_TELAOPCOES = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *botao_sair = NULL, *area_jogar = 0;
ALLEGRO_EVENT evento;
ALLEGRO_AUDIO_STREAM *musica = NULL;
ALLEGRO_SAMPLE *somefeitos = NULL;


#define Tela1 = MenuInicial;
#define Tela2 = Opcoes;
#define Tela3 = Tutorial;
#define Tela4 = Fase1;
#define Tela5 = Fase2;
#define Tela6 = Fase3;

