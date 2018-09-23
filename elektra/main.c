// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Constantes.h"
#include <stdio.h>

int main(void)
{
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

	// Declaração de imagens usadas
	// Se possível seguir o padrão (IMAGEM_NOMEDAIMAGEM)
	IMAGEM_SPLASHSCREEN = al_load_bitmap("Imagens/SplashScreen.png");
	IMAGEM_MENUINICIAL = al_load_bitmap("Imagens/MenuInicial.png");

    // Declarar neste if com o || a cada imagem adicionada, para que caso haja erro, ele pare aqui.
    if (!IMAGEM_SPLASHSCREEN || !IMAGEM_MENUINICIAL){
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

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    al_draw_bitmap(IMAGEM_SPLASHSCREEN, 0, 0, 0);
    al_flip_display();
    al_rest(3.0);

    al_draw_bitmap(IMAGEM_MENUINICIAL, 0, 0, 0);
    al_flip_display();

    while (1){
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.05);

        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);

        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
