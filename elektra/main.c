// Parâmetro para rodar:
//gcc -lallegro -lallegro_main -lallegro_image -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro_audio -lallegro_acodec -o smart main.c
// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Constantes.h"
#include <stdio.h>
#include <string.h>


ALLEGRO_EVENT evento;
ALLEGRO_TIMEOUT timeout;

int botoesFunction(ALLEGRO_EVENT e, int x1, int x2, int y1, int y2) {
	return e.mouse.x >= x1 && e.mouse.x <= x2 && e.mouse.y >= y1 && e.mouse.y <= y2;
}

int cardFunction(ALLEGRO_BITMAP *cartao, int x, int y, struct structCards *pergunta, struct structCards *resposta1, struct structCards *resposta2, struct structCards *resposta3) {

	ALLEGRO_COLOR preto = al_map_rgb(0,0,0);
	ALLEGRO_COLOR branco = al_map_rgb(0, 0, 255);

	fonteCard = al_load_font("fontePedra.ttf", 24, 0);

	al_draw_bitmap(cartao, x, y, 0);
	//al_draw_multiline_text(fonte, preto, 555, 70, 300, 100, 0, c[0].perguntas);
	al_draw_multiline_text(fonteCard, branco, 555, 120, 230, 50, 0, pergunta);
	al_draw_multiline_text(fonteCard, preto, 540, 380, 230, 40, 0, resposta1);
	al_draw_multiline_text(fonteCard, preto, 540, 480, 230, 40, 0, resposta2);
	al_draw_multiline_text(fonteCard, preto, 540, 580, 230, 40, 0, resposta3);
	al_flip_display();
	al_rest(5);
}

 typedef struct structCards {
	char perguntas[550];
	char resposta1[150];
	char resposta2[150];
	char resposta3[150];
	int x_certo;
	int y_certo;
}structCards;



int main(void)
{
	structCards carta[] = {
		{"What this expression “Strike while the iron is hot.” means?", "a) “Sua batata tá esquentando”", "b) “A coisa tá feia”", "c) “Aproveite enquanto é tempo”"},
		{"What this expression “That’s hardly the issue.” means?", "a) “Essa é uma questão difícil”", "b) “Isso não vem ao caso”", "c) “Isso é mais difícil do que eu pensei”"},
		{"What this expression “I got out of bed on the wrong side.” means?", "a) “Levantei com o pé esquerdo”","b) “Cai da cama nessa manhã”","c) “Sai da cama pelo lado errado”"},
		{"What this expression “A bird in the hand is worth two in the bush.” means?", "a) “Deixa ir”", "b) “Um pássaro é tão bonito quanto dois.”", "c) “Mais vale um pássaro na mão do que dois voando.”"},
		{"Complete the phrase “___ we ___ enough time to savage this love” ","a) Do/had","b) Does/has","c) Do/have"},
		{"Complete the phrase “___ I go to the ______” ","a) May/bathroom","b) May/restroom","c) Do/restroom"},
		{"Complete the phrase “ __ ___ a student?” ","a) Do/you","b) Are/you","c) Does/you"},
		{"Translate this phrase “What do you want to do tomorrow?”","a) O que você vai fazer amanhã?","b) Você quer fazer algo amanhã?","c) O que você quer fazer amanhã?"},
		{"Translate this phrase “I wanna live like a star?” ","a) Eu quero ser uma estrela","b) Eu quero viver como uma estrela","c) Eu sou uma estrela"},
		{"Translate this phrase “I intend to do something” ","a) Eu entendo para fazer algo","b) Eu pretendo fazer algo","c) Eu entendi que preciso fazer algo"},
		{"Translate this phrase “Actually, I don’t know what to do” ","a) Na verdade, eu não sei o que fazer","b) Atualmente, eu não sei o que fazer","c) Atualmente, eu não quero fazer nada"},
		{"Translate this phrase “Is it time to lunch?” ","a) É a hora do lanche?","b) É a hora de comer?","c) É a hora do almoço?"},
		{"Pass this phrase “You need this book” to interrogative form. ","a) Does you need this book?","b) Do you need this book?","c) Are you need this book?"},
		{"Pass this phrase “You went to the mall without me” to interrogative form. ","a) Did you go to the mall without me?","b) Do you went to the mall without me?","c) Went you to the mall without me?"},
		{"Pass this phrase “I want to eat protein” to negative form. ","a) I didn’t eat protein","b) I don’t want to eat protein","c) I don’t eat protein"},
		{"Pass this phrase “You are in the wrong way” to negative form.","a) You aren’t in the wrong way","b) You don’t are in the wrong way","c) You aren’t in the right way"},
		{"Pass this phrase “They aren’t cool with us” to affirmative form. ","a) They are cool with us","b) They do are cool with us","c) They don’t are cool with us"},
		{"Pass this phrase “Did he say that we need to go?” to affirmative form.","a) He said that we need to go","b) He said that we need to went","c) He say that we need to went"},
		{"What is the right way to answer: “How old are you?”","a) I have 15 years old","b) I am 15 years old","c) I do 15 years"},
		{"What is the right way to answer: “What’s your name?”","- a) My name is fulano","b) My name are fulano","c) My name do fulano"}
	};

	int sair = 0;
	int casa = 0;
	int tela = MENU_PRINCIPAL;
	int tecla = 0;

	int pantanoX[] = { 0, 140, 340, 515, 640, 880, 1070 };
	int pantanoY[] = { 415, 280, 260, 210, 120, 120, 70 };
	int cidadeX[]  = { 20,  200, 380, 500, 650, 790, 955, 1040 };
	int cidadeY[]  = { 207, 207, 207, 135, 70, 70, 70, 5 };
	int reinoX[]   = {-13, 130, 260, 790 };
	int reinoY[]   = {-30, -30, 30, 330 };

	char pressSpace[100] = { "Pressione espaço para rolar os dados." };

	//Inicialização de libs do Allegro
	al_init();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
	theme = al_load_audio_stream("Sons/Theme.wav", 8, 2048);
	starting = al_load_audio_stream("Sons/Starting.wav", 8, 2048);

	al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	al_set_window_title(janela, "SmartGator");

	fonte = al_load_font("arial.ttf", 48, 0);
	fonteSpace = al_load_font("arial.ttf", 26, 0);
	

	// Declaração de imagens usadas
	// Se possível seguir o padrão (IMAGEM_NOMEDAIMAGEM)
	IMAGEM_SPLASHSCREEN = al_load_bitmap("Imagens/SplashScreen.png");
	IMAGEM_MENUINICIAL = al_load_bitmap("Imagens/MenuInicial.png");
	IMAGEM_TELAOPCOES = al_load_bitmap("Imagens/TelaOpcoes.png");
	IMAGEM_FASE1 = al_load_bitmap("Imagens/Fase_1.png");
	IMAGEM_FASE2 = al_load_bitmap("Imagens/Fase_2.png");
	IMAGEM_FASE3 = al_load_bitmap("Imagens/Fase_3.png");
	IMAGEM_PERSONAGEM = al_load_bitmap("Imagens/Personagem.png");
	IMAGEM_CARD = al_load_bitmap("Imagens/EsbocoCards_1.png");

	fila_eventos = al_create_event_queue();

	al_register_event_source(fila_eventos, al_get_keyboard_event_source());
	al_register_event_source(fila_eventos, al_get_mouse_event_source());
	al_register_event_source(fila_eventos, al_get_display_event_source(janela));

	al_draw_bitmap(IMAGEM_SPLASHSCREEN, 0, 0, 0);
	al_attach_audio_stream_to_mixer(starting, al_get_default_mixer());
	al_set_audio_stream_playmode(starting, ALLEGRO_PLAYMODE_ONCE);
	al_set_audio_stream_playing(starting, true);
	al_flip_display();
	al_rest(4.0);
	al_destroy_audio_stream(starting);


	al_draw_bitmap(IMAGEM_MENUINICIAL, 0, 0, 0);
	al_attach_audio_stream_to_mixer(theme, al_get_default_mixer());
	al_set_audio_stream_playmode(theme, ALLEGRO_PLAYMODE_LOOP);
	al_set_audio_stream_playing(theme, true);
	al_flip_display();
	
	al_register_event_source(fila_eventos, al_get_mouse_event_source());

	while (!sair) {
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
				int btn_jogar = botoesFunction(evento, 850, 1250, 230, 320);
				int btn_opcoes = botoesFunction(evento, 970, 1250, 380, 430);
				int btn_tutorial = botoesFunction(evento, 900, 1265, 500, 540);

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
				int btn_jogar = botoesFunction(evento, 850, 1250, 230, 320);
				int btn_opcoes = botoesFunction(evento, 970, 1250, 380, 430);
				int btn_tutorial = botoesFunction(evento, 900, 1265, 500, 540);

				if (btn_jogar) {
					tela = FASE_PANTANO;

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
			}
			break;
		case 2:
			if (evento.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				int btn_voltar = botoesFunction(evento, 30, 90, 90, 140);
				int btn_som_off = botoesFunction(evento, 520, 610, 260, 340);
				int btn_som_on = botoesFunction(evento, 670, 770, 260, 340);

				if (btn_voltar || btn_som_off || btn_som_on)
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
				int btn_voltar = botoesFunction(evento, 30, 90, 90, 140);
				int btn_som_off = botoesFunction(evento, 520, 610, 260, 340);
				int btn_som_on = botoesFunction(evento, 670, 770, 260, 340);

				if (btn_voltar)
				{
					al_draw_bitmap(IMAGEM_MENUINICIAL, 0, 0, 0);
					al_flip_display();
					tela = 1;
				}

				if (btn_som_off)
				{
					al_set_audio_stream_playing(theme, false);
				}

				if (btn_som_on)
				{
					al_set_audio_stream_playing(theme, true);
				}
			}
			break;
		case 3:
			al_draw_bitmap(IMAGEM_FASE1, 0, 0, 0);
			al_draw_bitmap(IMAGEM_PERSONAGEM, pantanoX[casa], pantanoY[casa], 0);
			al_draw_textf(fonteSpace, al_map_rgb(0, 0, 0), 995, 435, ALLEGRO_ALIGN_CENTRE, pressSpace);
			al_flip_display();

			al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

			if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (evento.keyboard.keycode) {
				case ALLEGRO_KEY_SPACE:
						tecla = 1;
					break;
				}
			}
			if (tecla) {

				switch (tecla) {
				case 1:
					srand(time(NULL));
					int x = 1 + (rand() % 6);
					int cardNumero = rand() % 20;
					char i[10];
					snprintf(i, 10, "%d", x);
					al_draw_textf(fonte, al_map_rgb(0, 0, 0), 1125, 480, ALLEGRO_ALIGN_CENTRE, i);
					al_flip_display();
					al_rest(2);
					casa += x;
					if (casa >= 7) {
						tela = FASE_CIDADE;
						casa = 0;
					}
					al_draw_bitmap(IMAGEM_PERSONAGEM, pantanoX[casa], pantanoY[casa], 0);
					al_flip_display();
					cardFunction(IMAGEM_CARD, 355, 0, &carta[cardNumero].perguntas, &carta[cardNumero].resposta1, &carta[cardNumero].resposta2, &carta[cardNumero].resposta3);
					break;
				}
				tecla = 0;
				break;
			}
			break;
		case 4:
			al_draw_bitmap(IMAGEM_FASE2, 0, 0, 0);
			al_draw_bitmap(IMAGEM_PERSONAGEM, cidadeX[casa], cidadeY[casa], 0);
			al_draw_textf(fonteSpace, al_map_rgb(0, 0, 0), 490, 635, ALLEGRO_ALIGN_CENTRE, pressSpace);
			al_flip_display();

			al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

			if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (evento.keyboard.keycode) {
				case ALLEGRO_KEY_SPACE:
					tecla = 1;
					break;
				}

			}
			if (tecla) {

				switch (tecla) {
				case 1:
					//dado = dadosFunction();
					//Mesma função do dado, mas funcionando aqui
					srand(time(NULL));
					int x = 1 + (rand() % 6);
					int cardNumero = rand() % 20;
					char i[10];
					sprintf_s(i, 10, "%d", x);

					al_draw_textf(fonte, al_map_rgb(0, 0, 0), 355, 135, ALLEGRO_ALIGN_CENTRE, i);
					al_flip_display();
					al_rest(2);
					casa += x;
					if (casa >= 8) {
						tela = FASE_REINO;
						casa = 0;
					}
					al_draw_bitmap(IMAGEM_PERSONAGEM, cidadeX[casa], cidadeY[casa], 0);
					cardFunction(IMAGEM_CARD, 355, 0, &carta[cardNumero].perguntas, &carta[cardNumero].resposta1, &carta[cardNumero].resposta2, &carta[cardNumero].resposta3);
					al_flip_display();

					break;

				}
				tecla = 0;
				break;
			}
			break;
		case 5:
			al_draw_bitmap(IMAGEM_FASE3, 0, 0, 0);
			al_draw_bitmap(IMAGEM_PERSONAGEM, reinoX[casa], reinoY[casa], 0);
			al_draw_textf(fonteSpace, al_map_rgb(0, 0, 0), 235, 422, ALLEGRO_ALIGN_CENTRE, pressSpace);
			al_flip_display();

			al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

			if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (evento.keyboard.keycode) {
				case ALLEGRO_KEY_SPACE:
					tecla = 1;
					break;
				}

			}
			if (tecla) {

				switch (tecla) {
				case 1:
					srand(time(NULL));
					int x = 1 + (rand() % 2);
					int cardNumero = rand() % 20;
					char i[10];
					sprintf_s(i, 10, "%d", x);

					al_draw_textf(fonte, al_map_rgb(0, 0, 0), 110, 470, ALLEGRO_ALIGN_CENTRE, i);
					al_flip_display();
					al_rest(2);
					casa += x;
					if (casa >= 4) {
						tela = MENU_PRINCIPAL;
					
					}
					al_draw_bitmap(IMAGEM_PERSONAGEM, reinoX[casa], reinoY[casa], 0);
					cardFunction(IMAGEM_CARD, 355, 0, &carta[cardNumero].perguntas, &carta[cardNumero].resposta1, &carta[cardNumero].resposta2, &carta[cardNumero].resposta3);
					al_flip_display();
					
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
