/*tache1
nom et prenon: zikiou fatima amira g1*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int main()
{
    FILE *f, *out;
    unsigned long long tab[N], nombre, compteur = 0;
    unsigned long long j;
    int i;

    srand((unsigned int)time(NULL));

    f = fopen("primes10.txt", "r");

    if (f == NULL)
    {
        printf("Erreur : fichier primes10.txt introuvable.\n");
        return 1;
    }

    while (fscanf(f, "%llu", &nombre) == 1)
    {
        compteur++;

        if (compteur <= N)
        {
            tab[compteur - 1] = nombre;
        }
        else
        {
            j = ((unsigned long long)rand()
                 * ((unsigned long long)RAND_MAX + 1ULL)
                 + rand()) % compteur;

            if (j < N)
                tab[j] = nombre;
        }
    }

    fclose(f);

    if (compteur < N)
    {
        printf("Pas assez de nombres dans le fichier.\n");
        return 1;
    }

    out = fopen("Random100.txt", "w");

    if (out == NULL)
    {
        printf("Erreur de creation du fichier.\n");
        return 1;
    }

    for (i = 0; i < N; i++)
        fprintf(out, "%llu\n", tab[i]);

    fclose(out);

    printf("100 nombres selectionnes.\n");
    printf("Resultat : Random100.txt\n");

    return 0;
}
