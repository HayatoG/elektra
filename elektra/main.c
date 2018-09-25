// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Constantes.h"
#include <stdio.h>

int main(void)
{
	int sair = 0;

    if (!al_init()){
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }

    if (!al_init_image_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return -1;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);

    if (!janela){
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }
	// Configura o título da janela
	al_set_window_title(janela, "SmartGator");

	// Torna apto o uso de mouse na aplicação
	if (!al_install_mouse()) {
		error_msg("Falha ao inicializar o mouse");
		al_destroy_display(janela);
		return -1;
	}

	// Atribui o cursor padrão do sistema para ser usado
	if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)) {
		error_msg("Falha ao atribuir ponteiro do mouse");
		al_destroy_display(janela);
		return -1;
	}
	
	// Declaração de imagens usadas
	// Se possível seguir o padrão (IMAGEM_NOMEDAIMAGEM)
	IMAGEM_SPLASHSCREEN = al_load_bitmap("Imagens/SplashScreen.png");
	IMAGEM_MENUINICIAL  = al_load_bitmap("Imagens/MenuInicial.png");
	IMAGEM_TELAOPCOES   = al_load_bitmap("Imagens/TelaOpcoes.png");

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
					tela = 3
				}break;
			}
			case 2:
				if (evento.type == ALLEGRO_EVENT_MOUSE_AXES)
				{
					int btn_voltar = botoesMenuIniciar(evento, 30, 90, 90, 140);

					if (btn_voltar)
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

					if (btn_voltar)
					{
						al_draw_bitmap(IMAGEM_MENUINICIAL, 0, 0, 0);
						al_flip_display();
						tela = 1;
					}
				}
				break;
			case 3:
				al_draw_bitmap(IMAGEM_MENUINICIAL, 0, 0, 0);
				al_flip_display();
			
		}
		


		
	}

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
