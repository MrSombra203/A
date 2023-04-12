#include <stdio.h>
#include <math.h>
int main() {
    float x, y, r;
    int puntaje;
    const float radio1 = 2.5, radio2 = 5.0, radio3 = 7.5, radio4 = 10.0;
    printf("Ingrese las coordenadas (x,y) separadas por un espacio: ");
    scanf("%f %f", &x, &y);
    r = sqrt(x*x + y*y);
    if (r <= radio1) {
        puntaje = 5;
    } else if (r <= radio2) {
        puntaje = 3;
    } else if (r <= radio3) {
        puntaje = 2;
    } else if (r <= radio4) {
        puntaje = 1;
    } else {
        puntaje = 0;
    }
    if (puntaje > 0) {
        printf("¡Acertaste el blanco con un puntaje de %d!\n", puntaje);
    } else {
        printf("Lo siento, ¡fallaste el blanco!\n");
    }
    printf("Puntaje obtenido: %d\n", puntaje);
    return 0;
}