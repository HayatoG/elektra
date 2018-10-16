#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Constantes.h"


void botoesMenuIniciar(ALLEGRO_EVENT e, int x1, int x2, int y1, int y2) {
	return e.mouse.x >= x1 && e.mouse.x <= x2 && e.mouse.y >= y1 && e.mouse.y <= y2;
}

void error_msg(char *text) {
	al_show_native_message_box(NULL, "ERRO",
		"Ocorreu o seguinte erro e o programa sera finalizado:",
		text, NULL, ALLEGRO_MESSAGEBOX_ERROR);
}


//Deveria estar funcionando, mas não funciona, coloquei no main, para descobrirmos depois
void dadosFunction(){
	srand(time(NULL));
	int x = 1 + (rand() % 6);
	char i[10];
	sprintf_s(i, 10, "%d", x);
	printf("%s", i);
	return i;
}


/*void cards() {
//Para cada card existente, ele deve criar uma imagem, ou chama-lá, se possivel dinamicamente e aleatoriamente
	for (int i = 0; i <= 20; i++) {
		IMAGEM_CARD[i]= al_load_bitmap("Imagens/Card.png");
	}

}*/