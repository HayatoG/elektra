// Parâmetro para rodar:
//gcc -lallegro -lallegro_main -lallegro_image -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro_audio -lallegro_acodec -o smart main.c
// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#include "Constantes.h"


/*#define Tela1 = MenuInicial;
#define Tela2 = Opcoes;
#define Tela3 = Tutorial;
#define Tela4 = Fase1;
#define Tela5 = Fase2;
#define Tela6 = Fase3;


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
ALLEGRO_SAMPLE *somefeitos = NULL;*/


int botoesMenuIniciar(ALLEGRO_EVENT e, int x1, int x2, int y1, int y2) {
	return e.mouse.x >= x1 && e.mouse.x <= x2 && e.mouse.y >= y1 && e.mouse.y <= y2;
}

int main()
{

	int sair = 0;

	al_init();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);

	musica = al_load_audio_stream("Sons/MarioTesteSound.wav", 4, 1024);
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);

	al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
    al_set_audio_stream_playing(musica, true);


    if (!janela){
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }
	// Configura o título da janela
	al_set_window_title(janela, "SmartGator");

	// Torna apto o uso de mouse na aplicação
	al_install_mouse();

	al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	// Declaração de imagens usadas
	// Se possível seguir o padrão (IMAGEM_NOMEDAIMAGEM)
	IMAGEM_SPLASHSCREEN = al_load_bitmap("Imagens/SplashScreen.png");
	IMAGEM_MENUINICIAL = al_load_bitmap("Imagens/MenuInicial.png");
	IMAGEM_TELAOPCOES = al_load_bitmap("Imagens/TelaOpcoes.png");

    // Declarar neste if com o || a cada imagem adicionada, para que caso haja erro, ele pare aqui.
    if (!IMAGEM_SPLASHSCREEN || !IMAGEM_MENUINICIAL || !IMAGEM_TELAOPCOES){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }

    fila_eventos = al_create_event_queue();
    if (!fila_eventos){
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return -1;
    }

	al_register_event_source(fila_eventos, al_get_mouse_event_source());
	al_register_event_source(fila_eventos, al_get_display_event_source(janela));
	
    al_draw_bitmap(IMAGEM_SPLASHSCREEN, 0, 0, 0);
    al_flip_display();
    al_rest(3.0);

    al_draw_bitmap(IMAGEM_MENUINICIAL, 0, 0, 0);
    al_flip_display();
    	int tela = 1;

	al_register_event_source(fila_eventos, al_get_mouse_event_source());

    while (!sair){
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.05);

        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
		
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }
		switch (tela) {
		case 1:
			if (evento.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				int btn_jogar = botoesMenuIniciar(evento, 850, 1250, 230, 320);
				int btn_opcoes = botoesMenuIniciar(evento, 970, 1250, 380, 430);
				int btn_tutorial = botoesMenuIniciar(evento, 900, 1265, 500, 540);

				if (btn_jogar || btn_opcoes || btn_tutorial)
				{
					al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
				}
				else
				{
					al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				}

			}
			else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
			{
				int btn_jogar = botoesMenuIniciar(evento, 850, 1250, 230, 320);
				int btn_opcoes = botoesMenuIniciar(evento, 970, 1250, 380, 430);
				int btn_tutorial = botoesMenuIniciar(evento, 900, 1265, 500, 540);

				if (btn_jogar) {
					al_draw_bitmap(IMAGEM_SPLASHSCREEN, 0, 0, 0);
					al_flip_display();
					al_rest(3.0);
					al_draw_bitmap(IMAGEM_MENUINICIAL, 0, 0, 0);
					al_flip_display();
				}
				else if (btn_opcoes) {
					al_draw_bitmap(IMAGEM_TELAOPCOES, 0, 0, 0);
					al_flip_display();
					tela = 2;
				}
				else if (btn_tutorial) {
					al_draw_bitmap(IMAGEM_SPLASHSCREEN, 0, 0, 0);
					al_flip_display();
					tela = 3;
				}
			}break;
			case 2:
				if (evento.type == ALLEGRO_EVENT_MOUSE_AXES)
				{
					int btn_voltar = botoesMenuIniciar(evento, 30, 90, 90, 140);
					int btn_som_off = botoesMenuIniciar(evento, 520, 610, 260, 340);
					int btn_som_on = botoesMenuIniciar(evento, 670, 770, 260, 340);

					if (btn_voltar)
					{
						al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					}
					else
					{
						al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
					}
					if (btn_som_off)
					{
						al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					}
					else
					{
						al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

					}
					if (btn_som_on)
					{
						al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					}
					else
					{
						al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
					}

				}
				else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
				{
					int btn_voltar = botoesMenuIniciar(evento, 30, 90, 90, 140);
					int btn_som_off = botoesMenuIniciar(evento, 520, 610, 260, 340);
					int btn_som_on = botoesMenuIniciar(evento, 670, 770, 260, 340);

					if (btn_voltar)
					{
						al_draw_bitmap(IMAGEM_MENUINICIAL, 0, 0, 0);
						al_flip_display();
						tela = 1;
					}

					if (btn_som_off)
					{
						al_set_audio_stream_playing(musica, false);
					}

					if (btn_som_on)
					{
						al_set_audio_stream_playing(musica, true);
					}
				}
				break;
			case 3:
				al_draw_bitmap(IMAGEM_MENUINICIAL, 0, 0, 0);
				al_flip_display();
				break;
			
		}
		
	}

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}