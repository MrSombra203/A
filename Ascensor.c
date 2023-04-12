#include <stdio.h>

int main() {
  int piso_actual = 0;
  int piso_llamada, piso_seleccionado, i;

  while (1) {
    printf("\nMenú de opciones:\n");
    printf("a. Llamar ascensor\n");
    printf("b. Seleccionar piso\n");
    printf("c. Mostrar piso actual\n");
    printf("d. Salir\n");

    char opcion;
    printf("Elija una opción: ");
    scanf(" %c", &opcion);

    switch(opcion) {
      case 'a':
        printf("Ingrese el piso desde donde llama al ascensor (0-9): ");
        scanf("%d", &piso_llamada);

        if (piso_llamada == piso_actual) {
          printf("El ascensor ya está en el piso %d\n", piso_actual);
        } else if (piso_llamada < 0 || piso_llamada > 9) {
          printf("Piso inválido\n");
        } else {
          printf("Ascensor en piso %d\n", piso_actual);
          if (piso_llamada < piso_actual) {
            for (i = piso_actual - 1; i >= piso_llamada; i--) {
              printf("Ascensor en piso %d\n", i);
            }
          } else {
            for (i = piso_actual + 1; i <= piso_llamada; i++) {
              printf("Ascensor en piso %d\n", i);
            }
          }
          piso_actual = piso_llamada;
          printf("Ascensor llegó al piso %d\n", piso_actual);
        }
        break;

      case 'b':
        printf("Ingrese el piso al que desea ir (0-9): ");
        scanf("%d", &piso_seleccionado);

        if (piso_seleccionado == piso_actual) {
          printf("El ascensor ya está en el piso %d\n", piso_actual);
        } else if (piso_seleccionado < 0 || piso_seleccionado > 9) {
          printf("Piso inválido\n");
        } else {
          printf("Ascensor en piso %d\n", piso_actual);
          if (piso_seleccionado < piso_actual) {
            for (i = piso_actual - 1; i >= piso_seleccionado; i--) {
              printf("Ascensor en piso %d\n", i);
            }
          } else {
            for (i = piso_actual + 1; i <= piso_seleccionado; i++) {
              printf("Ascensor en piso %d\n", i);
            }
          }
          piso_actual = piso_seleccionado;
          printf("Ascensor llegó al piso %d\n", piso_actual);
        }
        break;

      case 'c':
        switch(piso_actual) {
          case 0:
            printf("El ascensor está en planta baja\n");
            break;
          case 1:
            printf("El ascensor está en el primer piso\n");
            break;
          case 2:
            printf("El ascensor está en el segundo piso\n");
            break;
          case 3:
            printf("El ascensor está en el tercer piso\n");
            break;
            case 4:
            printf("El ascensor está en el cuarto piso\n");
            break;
            case 5:
            printf("El ascensor está en el quinto piso\n");
            break;
            case 6:
            printf("El ascensor está en el sexto piso\n");
            break;
            case 7:
            printf("El ascensor está en el septimo piso\n");
            break;
            case 8:
            printf("El ascensor está en el octavo piso\n");
            break;
            case 9:
            printf("El ascensor está en el noveno piso\n");
            break;
        }
        
        break;
        
        case 'd':
        printf("Usted salió del ascensor\n");
        return 0;
    }
  }
}