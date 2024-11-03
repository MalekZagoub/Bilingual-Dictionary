#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char a[27];
    char b[27];
} traduction;
 char *recherche(traduction *dico, int n, char *s) {
    int debut = 0;
    int fin = n - 1;
    while (debut <= fin) {
        int milieu = (debut + fin) / 2;
        int cmp = strcmp(dico[milieu].a, s);
        if (cmp == 0) {
            return dico[milieu].b; // trouv�
        } else if (cmp < 0) {
            debut = milieu + 1; // le mot recherch� est apr�s le milieu
        } else {
            fin = milieu - 1; // le mot recherch� est avant le milieu
        }
    }
    return NULL; // non trouv�
}

int nombre_espaces(char *s) {
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            n++;
        }
    }
    return n;
}
char **decoupe(char *s) {
   int n=nombre_espaces(s)+1;
   char **mots = (char **) malloc((n + 1) * sizeof(char *));
    int i = 0;
    char *mot = strtok(s, " "); // d�coupe la cha�ne en mots en utilisant l'espace comme d�limiteur
     while (mot != NULL) {
        mots[i] = strdup(mot); // alloue une nouvelle chaine de caract�res pour le mot et l'ajoute au tableau
        i++;
        mot = strtok(NULL, " ");
        }
    mots[n] = NULL; // derni�re chaine �gale � NULL
    return mots;
}
char *reconstruit(char **tab){
   int n=0 ; //nombtre de caract�res dans la chaine finale
    for(int i=0;tab[i]!=NULL;i++){
        n+=strlen(tab[i])+1; // ajoute la longuer du mot et un caract�re d espace
    }
    char*s = malloc(n*sizeof(char));//alloue la m�moire pour la chaine finale
    s[0]='\0'; // initilalisation de la chaine finale � une chaine vide
    for(int i=0;tab[i]!=NULL;i++){
        strcat(s,tab[i]);// ajoute le mot � la chaine finale
        if (tab[i+1]!=NULL)
        {
            strcat(s,""); // ajoite un espace sauf pour le dernier mot
        }

    }
    return s;
}
char *traducteur (traduction *dico, int n, char *s){
    char**tab=decoupe(s); // d�coupe la chaine en mots
    char ** trad = reconstruit(tab);
    free(tab); // lib�re la m�moire alloue� pour le tableau de mots
    return trad;

}


int main(){
    traduction dico[]={ {"G�nie", "Engineering"},
        {"R�seau", "Network"},
        {"T�l�com", "Telecom"},
        {"Informatique", "Computer Science"},
        {"Cours", "Classes"},
        {"De", "Of"},
        {"Langage", "Language"},
        {"Programmation", "Programming"},
        {"Est", "Is"},
        {"Cool", "Cool"}};

         int n = sizeof(dico);
         char s[] = "G�nie R�seau T�l�com est cool";
         char *traduit = traducteur(dico,n,s);
         printf("Traduction de \"%s\" : \"%s\"\n", s, traduit);
         free (traduit);
         return 0;
         }

