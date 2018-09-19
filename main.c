// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

// Para utilizarmos o fprintf
#include <stdio.h>


// Atributos da tela
const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

int main(void)
{
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *splash_screen = NULL;
    ALLEGRO_BITMAP *imagem2= NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;

    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }

    if (!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return -1;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }

    splash_screen = al_load_bitmap("Imagens/SplashTeste.png");
    imagem2 = al_load_bitmap("Imagens/Tela1.png");
    if (!splash_screen)
    {
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }

    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return -1;
    }

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    al_draw_bitmap(splash_screen, 0, 0, 0);
    al_flip_display();
    al_rest(3.0);
    al_draw_bitmap(imagem2, 0, 0, 0);
    al_flip_display();

    while (1)
    {
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
