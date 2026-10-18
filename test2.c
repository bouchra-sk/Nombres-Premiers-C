#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_CHIFFRES 3
#define MAX_CHIFFRES 12

typedef unsigned long long Entier;

int nombreChiffres(Entier n)
{
    int chiffres = 1;

    while (n >= 10)
    {
        n /= 10;
        chiffres++;
    }

    return chiffres;
}

int main()
{
    FILE *source, *destination;
    Entier n;
    Entier *selection[MAX_CHIFFRES + 1];
    unsigned long long vus[MAX_CHIFFRES + 1] = {0};
    int d;
    unsigned long long i, r;
    unsigned long long nb;

    /* Saisie du nombre par l'utilisateur */
    printf("Combien de nombres par taille (nombre de chiffres) ? ");
    if (scanf("%llu", &nb) != 1 || nb == 0)
    {
        printf("Erreur : valeur invalide.\n");
        return 1;
    }

    /* Allocation dynamique */
    for (d = MIN_CHIFFRES; d <= MAX_CHIFFRES; d++)
    {
        selection[d] = malloc(nb * sizeof(Entier));
        if (selection[d] == NULL)
        {
            printf("Erreur : memoire insuffisante.\n");
            return 1;
        }
    }

    srand((unsigned int)time(NULL));

    source = fopen("primes10.txt", "r");

    if (source == NULL)
    {
        printf("Erreur : impossible d'ouvrir primes10.txt\n");
        return 1;
    }

    while (fscanf(source, "%llu", &n) == 1)
    {
        d = nombreChiffres(n);

        if (d >= MIN_CHIFFRES && d <= MAX_CHIFFRES)
        {
            vus[d]++;

            if (vus[d] <= nb)
            {
                selection[d][vus[d] - 1] = n;
            }
            else
            {
                /* rand() est limite */
                r = (((unsigned long long)rand() << 15) ^ (unsigned long long)rand()) % vus[d];

                if (r < nb)
                    selection[d][r] = n;
            }
        }
    }

    fclose(source);

    destination = fopen("Test-2.txt", "w");

    if (destination == NULL)
    {
        printf("Erreur : impossible de creer Test-2.txt\n");
        return 1;
    }

    for (d = MIN_CHIFFRES; d <= MAX_CHIFFRES; d++)
    {
        if (vus[d] < nb)
        {
            printf("Attention : seulement %llu nombres a %d chiffres.\n",
                   vus[d], d);
        }

        fprintf(destination, "# Nombres a %d chiffres\n", d);

        for (i = 0; i < nb && i < vus[d]; i++)
        {
            fprintf(destination, "%llu\n", selection[d][i]);
        }

        free(selection[d]);
    }

    fclose(destination);

    printf("Selection terminee. Fichier Test-2.txt cree.\n");

    return 0;
}
