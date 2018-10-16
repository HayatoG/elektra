// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Constantes.h"
#include <stdio.h>
#pragma once
#define _CRT_SECURE_NO_WARNINGS



ALLEGRO_EVENT evento;
ALLEGRO_TIMEOUT timeout;

int main(void)
{
	int sair = 0;

	char dado;

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

	al_init_font_addon();

	if (!al_init_ttf_addon()) {
		error_msg("Falha ao inicializar add-on allegro_ttf");
		return 0;
	}

	// Torna apto o uso de mouse na aplicação
	if (!al_install_mouse()) {
		error_msg("Falha ao inicializar o mouse");
		al_destroy_display(janela);
		return -1;
	}

	//inicializa addon do teclado
	if (!al_install_keyboard()) {
		error_msg("Falha ao inicializar o teclado");
		return 0;
	}

	fonte = al_load_font("arial.ttf", 48, 0);
	if (!fonte) {
		error_msg("Falha ao carregar \"arial.ttf\"");
		al_destroy_display(janela);
		return 0;
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
	IMAGEM_FASE1        = al_load_bitmap("Imagens/Fase_1.png");
	IMAGEM_FASE2        = al_load_bitmap("Imagens/Fase_2.png");
	IMAGEM_FASE3        = al_load_bitmap("Imagens/Fase_3.png");


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

	al_register_event_source(fila_eventos, al_get_keyboard_event_source());
	al_register_event_source(fila_eventos, al_get_mouse_event_source());
	al_register_event_source(fila_eventos, al_get_display_event_source(janela));
	
    al_draw_bitmap(IMAGEM_SPLASHSCREEN, 0, 0, 0);
    al_flip_display();
    al_rest(3.0);

    al_draw_bitmap(IMAGEM_MENUINICIAL, 0, 0, 0);
    al_flip_display();
	int tela = MENU_PRINCIPAL;
	int tecla = 0;

	al_register_event_source(fila_eventos, al_get_mouse_event_source());

    while (!sair){
        al_init_timeout(&timeout, 0.05);

        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
		
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }
		switch (tela) {
		case 1 :
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
					tela = FASE_CIDADE;
				}
				else if (btn_opcoes) {
					al_draw_bitmap(IMAGEM_TELAOPCOES, 0, 0, 0);
					al_flip_display();
					tela = TELA_OPCOES;
				}
				else if (btn_tutorial) {
					al_draw_bitmap(IMAGEM_SPLASHSCREEN, 0, 0, 0);
					al_flip_display();
					tela = TELA_TUTORIAL;
				}
			}break;
			case 2:
				//telaOpcoes();
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
						tela = MENU_PRINCIPAL;
					}
				}
				break;
			case 3:
				al_draw_bitmap(IMAGEM_FASE1, 0, 0, 0);
				al_flip_display();
				break;
			case 4:
				al_draw_bitmap(IMAGEM_FASE2, 0, 0, 0);
				al_flip_display();
		
				al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				
				if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
					//verifica qual tecla foi pressionada
					switch (evento.keyboard.keycode) {
						//seta para cima
					case ALLEGRO_KEY_SPACE:
						tecla = 1;
						break;
					}

				}
				else if (evento.type == ALLEGRO_EVENT_KEY_UP) {
					tecla = 5;
				}
					if (tecla){

						switch (tecla) {
						case 1:
							//dado = dadosFunction();
							//Mesma função do dado, mas funcionando aqui
							srand(time(NULL));
							int x = 1 + (rand() % 6);
							char i[10];
							sprintf_s(i, 10, "%d", x);

							al_draw_textf(fonte, al_map_rgb(0, 0, 0),355, 135, ALLEGRO_ALIGN_CENTRE , i);
							al_flip_display();
							al_rest(2);
							break;
							
						}
						
						tecla = 0;
						break;
					}
				
				break;

			
		}
		

		
	}

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
