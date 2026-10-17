
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

unsigned long long aleatoire(unsigned long long limite)
{
    unsigned long long base;
    unsigned long long plage;
    unsigned long long x;
    unsigned long long max_valide;

    base = (unsigned long long)RAND_MAX + 1ULL;
    plage = base * base;
    max_valide = plage - (plage % limite);

    do
    {
        x = (unsigned long long)rand() * base + rand();
    }
    while (x >= max_valide);

    return x % limite;
}

int main(void)
{
    FILE *f, *out;
    unsigned long long tab[N];
    unsigned long long nombre;
    unsigned long long compteur = 0;
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
            j = aleatoire(compteur);

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

    out = fopen("Random1000.txt", "w");

    if (out == NULL)
    {
        printf("Erreur de creation du fichier.\n");
        return 1;
    }

    for (i = 0; i < N; i++)
        fprintf(out, "%llu\n", tab[i]);

    fclose(out);

    printf("1000 nombres selectionnes parmi %llu nombres.\n",
           compteur);
    printf("Resultat : Random1000.txt\n");

    return 0;
}
