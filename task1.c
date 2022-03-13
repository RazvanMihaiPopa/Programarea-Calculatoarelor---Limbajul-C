#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct site {
    char url[51], titlu[51];
    int nr_de_acc, checksum, l_cod;
    char *continut;
} site;
int main()
{
    int i, sz = 3, ok = 0, p = 101, j;
    site *sitehtml = malloc(sz * sizeof(site));
    FILE *master, *siteuri;
    char s[31], st[101], aux[101], *buc;
    master = fopen("master.txt", "r");
    if(master == NULL) {
        printf("Nu se poate deschide la citire master.txt\n");
        return 1;
    }
    for(i = 0; fgets(s, 31, master); i++) { // citesc fiecare linie din master.txt
        if(i + 1 > sz) { // daca este cazul, realoc dinamic
            sz = sz + 3;
            sitehtml = realloc(sitehtml, sz * sizeof(site));
        }
        s[strlen(s) - 1] = '\0'; // deoarece s-ar citi cu tot cu \n, voi pune caracterul NULL in locul sau.
        siteuri = fopen(s, "r");
        if(siteuri == NULL) {
            printf("Nu se poate deschide la citire site-ul %d\n", i);
            return 1;
        }
        // pe prima linie fiecare cuvant este separat prin spatiu, deci pot folosi fscanf sa introduc datele in structura
        fscanf(siteuri, "%s %d %d %d", sitehtml[i].url, &sitehtml[i].l_cod, &sitehtml[i].nr_de_acc, &sitehtml[i].checksum);
        while(fgets(st, 101, siteuri) != NULL) { // citesc fiecare linie a unui site
            //daca gasesc <title> pe o linie, cum acesta are 7 caractere, voi copia in st sirul de la adresa st+7
            if(strstr(st, "<title>") != NULL) {
                strcpy(aux, st + 7);
                strcpy(st, aux);
                st[strlen(st) - 9] = '\0'; // cum '</title>' are 8 caractere, in locul caracterului '<' voi pune caracterul NULL
                strcpy(sitehtml[i].titlu, st);
            }
            if(ok == 1) {
                p = p + 101; // vom realoca dinamic pentru fiecare linie noua
                sitehtml[i].continut = realloc(sitehtml[i].continut, sizeof(site) * p * sizeof(char));
                if(strstr(st, "</p>") != NULL) { // cand gasim '</p>' punem caracterul NULL in locul '<' si ok devine 0
                    st[strlen(st) - 5] = '\0';
                    ok = 0;
                }
                strcat(sitehtml[i].continut, st);
            }
            if(strstr(st, "<p") != NULL)  {
                sitehtml[i].continut = malloc(sizeof(site) * p * sizeof(char)); 
                buc=strstr(st, ">"); // pe linia pe care gasim '<p'vom retine si adresa unde se afla '>' 
                int t = buc - st; // retin diferenta de adrese pentru a elimina din sir tagul ce contine p
                strcpy(aux, st + t + 1);
                strcpy(st, aux);
                if(strstr(st, "</p>") != NULL) {
                    st[strlen(st) - 5] = '\0'; // daca '</p>' se afla pe acceasi linie voi pune in locul '<' caracterul NULL
                    strcpy(sitehtml[i].continut, st);
                }
                else ok = 1; // ok este 1 cat timp suntem in tagul '<p>', adica in continut
                strcpy(sitehtml[i].continut, st);
            }
        }
        fclose(siteuri);
    }
    for(j = 0; j < i; j++) {
        printf("%s %d %s\n", sitehtml[j].url, sitehtml[j].nr_de_acc, sitehtml[j].titlu);
        free(sitehtml[j].continut); // eliberam memoria alocata dinamic
    }
    free(sitehtml);
    fclose(master);
}