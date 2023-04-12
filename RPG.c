#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicialización de variables
    int vida = 100;
    int opcion_arma;
    int opcion_situacion;
    int enemigo_vida;
    int enemigo_dano;
    int recuperar_vida;
    int aumentar_vida;
    int mejorar_dano;
    char nombre_personaje[50];

    // Ingreso del nombre del personaje
    printf("Ingresa el nombre de tu personaje: ");
    scanf("%s", nombre_personaje);
    printf("Bienvenido %s, comencemos el juego.\n", nombre_personaje);

    // Selección del arma
    printf("Selecciona tu arma:\n");
    printf("1) Espada (50 de daño)\n");
    printf("2) Hacha (70 de daño)\n");
    printf("3) Arco (30 de daño)\n");
    printf("Opción: ");
    scanf("%d", &opcion_arma);

    // Validación de la opción del arma
    while (opcion_arma < 1 || opcion_arma > 3) {
        printf("Opción inválida. Selecciona tu arma:\n");
        printf("1) Espada (50 de daño)\n");
        printf("2) Hacha (70 de daño)\n");
        printf("3) Arco (30 de daño)\n");
        printf("Opción: ");
        scanf("%d", &opcion_arma);
    }

    // Selección aleatoria de la primera situación
    srand(time(0));
    opcion_situacion = rand() % 5 + 1;

    // Bucle para las dos situaciones
    for (int i = 1; i <= 2; i++) {
        // Asignación de valores según la situación
        switch (opcion_situacion) {
            case 1:
                enemigo_vida = 60;
                enemigo_dano = 30;
                printf("\nUn monstro se aparecio en tu camino, enfrentas a un goblin!\n");
                break;
            case 2:
                enemigo_vida = 120;
                enemigo_dano = 45;
                printf("\nUn ser enorme aparece, enfrentas a un golem de piedra!\n");
                break;
            case 3:
                enemigo_vida = 70;
                enemigo_dano = 33;
                printf("\nUna sobra cae en tu camino, enfrentas a un ladrón!\n");
                break;
            case 4:
                enemigo_vida = 69;
                enemigo_dano = 40;
                printf("\nUn olor invade el bosque, enfrentas a un trol!\n");
                break;
            case 5:
                enemigo_vida = 200;
                enemigo_dano = 49;
                printf("\nEl fuego primordial a caido del cielo para devorarte, enfrentas a un dragon!\n");
                break;
        }

        // Bucle para la pelea
        while (vida > 0 && enemigo_vida > 0) {
            // Mostrar la vida del personaje y enemigo
            printf("\n%s: %d de vida\n", nombre_personaje, vida);
            printf("Enemigo: %d de vida\n", enemigo_vida);

            // Selección de la acción del personaje
            printf("Selecciona tu acción:\n");
            printf("1) Atacar\n");
            printf("2) Recuperar   3) Aumentar vida\n");
        printf("4) Mejorar daño\n");
        printf("Opción: ");
        int accion;
        scanf("%d", &accion);

        // Validación de la acción
        while (accion < 1 || accion > 4) {
            printf("Opción inválida. Selecciona tu acción:\n");
            printf("1) Atacar\n");
            printf("2) Recuperar\n");
            printf("3) Aumentar vida\n");
            printf("4) Mejorar daño\n");
            printf("Opción: ");
            scanf("%d", &accion);
        }

        // Acción del personaje
        switch (accion) {
            case 1:
                enemigo_vida -= (opcion_arma == 1) ? 50 : (opcion_arma == 2) ? 70 : 30;
                printf("Atacas al enemigo.\n");
                break;
            case 2:
                recuperar_vida = rand() % 21 + 10;
                vida += recuperar_vida;
                if (vida > 100) {
                    vida = 100;
                }
                printf("Recuperas %d de vida.\n", recuperar_vida);
                break;
            case 3:
                aumentar_vida = rand() % 11 + 5;
                vida += aumentar_vida;
                printf("Aumentas tu vida en %d.\n", aumentar_vida);
                break;
            case 4:
                mejorar_dano = rand() % 11 + 5;
                if (opcion_arma == 1) {
                    printf("Mejoras tu espada en %d de daño.\n", mejorar_dano);
                } else if (opcion_arma == 2) {
                    printf("Mejoras tu hacha en %d de daño.\n", mejorar_dano);
                } else {
                    printf("Mejoras tu arco en %d de daño.\n", mejorar_dano);
                }
                break;
        }

        // Acción del enemigo
        if (enemigo_vida > 0) {
            vida -= enemigo_dano;
            printf("El enemigo te ataca.\n");
        }
    }

    // Verificación del resultado de la pelea
    if (vida <= 0) {
        printf("\n¡Has perdido toda tu vida! ¡Fin del juego!\n");
        break;
    } else {
        printf("\n¡Has vencido al enemigo! ¡Felicidades!\n");
    }

    // Selección aleatoria de la siguiente situación
    if (i == 1) {
        opcion_situacion = rand() % 5 + 1;
        printf("Prepárate para la siguiente pelea.\n");
    }
}

// Mostrar la vida final del personaje
printf("\n%s, has terminado el juego con %d de vida.\n", nombre_personaje, vida);

return 0;
}