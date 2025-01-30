#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    int min1 = 1, max1 = 4;
    int min2 = 0, max2 = 1;
    int nCamere;

    printf("Inserire il numero di camere: ");
    scanf("%d", &nCamere);


    int camere[nCamere];
    int posti[nCamere];
    int libero[nCamere];

    int capienzaTotale = 0;


    for (int i = 0; i < nCamere; i++) {
        camere[i] = i + 1;
    }


    for (int i = 0; i < nCamere; i++) {
        posti[i] = rand() % (max1 - min1 + 1) + min1;
        if (posti[i] == 1)
            printf("la camera %d ha %d posto\n", i + 1, posti[i]);
        else
            printf("la camera %d ha %d posti\n", i + 1, posti[i]);
    }
    for (int i = 0; i < nCamere; i++) {
        libero[i] = rand() % (max2 - min2 + 1) + min2;
        if (libero[i] == 0) {
            printf("la camera %d e' libera\n", i + 1);
        } else {
            printf("la camera %d e' occupata\n", i + 1);
        }
    }


    for (int i = 0; i < nCamere; i++) {
        capienzaTotale += posti[i];
    }
    printf("La capienza totale e' %d\n", capienzaTotale);


    printf("Inserire la camera desiderata: ");
    int cameraScelta;
    scanf("%d", &cameraScelta);

    int cameraTrovata = 0;

    for (int i = 0; i < nCamere; i++) {
        if (cameraScelta == camere[i]) {
            cameraTrovata = 1;
            if (libero[i] == 0) {
                printf("Hai occupato la camera %d\n", cameraScelta);
                libero[i] = 1;
            } else {
                printf("La camera %d e' gia' occupata\n", cameraScelta);
            }
            break;
        }
    }

    if (!cameraTrovata) {
        printf("Errore: la camera %d e' inesistente\n", cameraScelta);
    }
    int camere1Posto = 0;
    int camere2Posti = 0;
    int camere3Posto = 0;
    int camere4Posti = 0;
    for (int i = 0; i < nCamere; i++) {
        if (posti[i] == 1)
            camere1Posto++;
        else if (posti[i] == 2)
            camere2Posti++;
        else if (posti[i] == 3)
            camere3Posto++;
        else if (posti[i] == 4)
            camere4Posti++;
    }

    printf("le camere con 1 posto sono %d\n", camere1Posto);
    printf("le camere con 2 posto sono %d\n", camere2Posti);
    printf("le camere con 3 posto sono %d\n", camere3Posto);
    printf("le camere con 4 posto sono %d\n", camere4Posti);


    printf("Inserire il numero di persone: ");
    int nPersone;
    scanf("%d", &nPersone);

    cameraTrovata = 0;

    for (int i = 0; i < nCamere; i++) {
        if (libero[i] == 0 && posti[i] == nPersone) {
            cameraTrovata = 1;
            if (libero[i] == 0) {
                printf("Hai occupato la camera %d\n", i + 1);
                libero[i] = 1;
                break;
            }
        }
    }
    if (!cameraTrovata) {
        printf("non c'e nessuna camera disponibile");
    }

    return 0;
}
