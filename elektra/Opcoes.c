#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Constantes.h"

void telaOpcoes() {
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
			return;
		}
	}
}