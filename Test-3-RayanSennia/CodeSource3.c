#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *fichier;
    int i;
    int n;
    long long nombre;

    srand(time(NULL));

    printf("Combien de nombres voulez pour chaque categorie : ");
    scanf("%d", &n);

    fichier = fopen("Test-3.txt", "w");

    if (fichier == NULL)
    {
        printf("Erreur lors de la creation du fichier.\n");
        return 1;
    }

    fprintf(fichier, "Nombres a 3 chiffres :\n");

    for (i = 0; i < n; i++)
    {
        nombre = 100 + rand() % 900;
        fprintf(fichier, "%lld\n", nombre);
    }

    fprintf(fichier, "\nNombres a 6 chiffres :\n");

    for (i = 0; i < n; i++)
    {
        nombre = 100000 + rand() % 900000;
        fprintf(fichier, "%lld\n", nombre);
    }

    fprintf(fichier, "\nNombres a 9 chiffres :\n");

    for (i = 0; i < n; i++)
    {
        nombre = 100000000LL + rand() % 900000000LL;
        fprintf(fichier, "%lld\n", nombre);
    }

    fprintf(fichier, "\nNombres a 12 chiffres :\n");

    for (i = 0; i < n; i++)
    {
        nombre = 100000000000LL + rand() % 900000000000LL;
        fprintf(fichier, "%lld\n", nombre);
    }

    fclose(fichier);

    printf("Le fichier Test-3.txt a ete genere avec succes.\n");

    return 0;
}
 