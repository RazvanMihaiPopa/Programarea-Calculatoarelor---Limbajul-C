#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct site {
    char url[51], titlu[51];
    int nr_de_acc, checksum, l_cod;
    char *continut;
} site; 
// functie ce indeplineste criteriile de ordonare cerute de problema si returneaza 1 daca va trebui sa interschimbam s1 cu s2 si 0 in caz contrar 
int comparare(char *s1, char *s2, int a1, int a2) {
    int p = strcmp(s1, s2); // folosesc strcmp pentru a compara alfabetic
    if(p == 0) { // daca site-urile au acelasi titlu, trec la criteriul doi de comparare
        if (a1 > a2) 
            return 0; 
        else 
            return 1;
    }
    else {
        if (p > 0)
            return 1; // s1>s2 lexico-grafic
        else
            return 0; // s1<s2 lexico-grafic
    }
}
void interschimbare_int(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
void interschimbare_char(char *a, char *b) {
    char aux[1000];
    strcpy(aux, a);
    strcpy(a, b);
    strcpy(b, aux);
}
void sortare(site *pagina, int k, int (*ptr)(char*,char*,int,int)) {
    int i, j;
    for (i = 0; i < k - 1 ; i++)
        for (j = i + 1; j < k ; j++)
            // interschimb site-urile care indeplinesc criteriile cerute de problema in functie de criteriile de comparare
            if(ptr(pagina[i].continut, pagina[j].continut, pagina[i].nr_de_acc, pagina[j].nr_de_acc) == 1) {
                interschimbare_int(&pagina[i].nr_de_acc, &pagina[j].nr_de_acc);
                interschimbare_int(&pagina[i].l_cod, &pagina[j].l_cod);
                interschimbare_int(&pagina[i].checksum, &pagina[j].checksum);
                interschimbare_char(pagina[i].titlu, pagina[j].titlu);
                interschimbare_char(pagina[i].url, pagina[j].url);
                interschimbare_char(pagina[i].continut, pagina[j].continut);
            } 
}
int main()
{
    int i, sz = 3, ok = 0, p = 101, j, k = 0, max = 0;
    int (*cmp)(char*, char*, int, int) = comparare;
    site *sitehtml = malloc(sz * sizeof(site));
    FILE *master, *siteuri;
    char s[31], st[101], aux[101], *buc, cuvinte[1000];
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
        if(p>max) // retinem dimensiunea maxima a continutului
            max=p;
        fclose(siteuri);
    }
    site *sitegasit = malloc(i * sizeof(site));
    fgets(cuvinte, 1001, stdin); // citim cuvinte pana la intalnirea newline
    char *cuv = strtok(cuvinte, " "); // folosim strtok pentru a separa cuvintele
    char copiecuv[151][151]; // luam un vector sir de caractere pentru a retine cuvintele
    int x = 0, y;
    while(cuv != NULL) {
        strcpy(copiecuv[x], cuv);
        cuv = strtok(NULL, " ");
        x++; // in x retin numarul de cuvinte
    }
    int l1 = strlen(copiecuv[x - 1]); 
    copiecuv[x - 1][l1 - 1] = '\0'; // elimin ultimul endline din matricea de cuvinte
    for (j = 0; j < i; j++) {
        for(y = 0; y < x; y++) {
                char aux1[1001], aux2[1001];
                int l2 = strlen(copiecuv[y]);
                buc = strstr(sitehtml[j].continut, copiecuv[y]); // retin adresa unde gasesc cuvantul, daca il gasesc
                if(buc != 0) {
                    int t = buc - sitehtml[j].continut;
                    strcpy(aux1, sitehtml[j].continut + t - 1);
                    aux1[1] = '\0'; // in aux1 am retinut caracterul de dinaintea cuvantului gasit
                    strcpy(aux2, sitehtml[j].continut + t + l2);
                    aux2[1] = '\0'; // in aux2 am retinut caracterul de dupa cuvantul gasit
                    if(strstr(" ,.!", aux1) != NULL && strstr(" ,.!", aux2) != NULL) { // verificam daca nu cumva cuvantul gasit se afla de fapt in alt cuvant
                        sitegasit[k].nr_de_acc = sitehtml[j].nr_de_acc;
                        sitegasit[k].checksum = sitehtml[j].checksum;
                        sitegasit[k].l_cod = sitehtml[j].l_cod;
                        strcpy(sitegasit[k].titlu, sitehtml[j].titlu);
                        strcpy(sitegasit[k].url, sitehtml[j].url);
                        sitegasit[k].continut = malloc(sizeof(char) * max * sizeof(site));
                        strcpy(sitegasit[k].continut, sitehtml[j].continut);
                        k++; // in k retin numarul cuvintelor gasite
                        break; // cand am gasit un cuvant intr-un site, nu va mai trebui sa caut altul, deci trec la urmatorul site
                    }
                }
        }
    }
    sortare(sitegasit, k, cmp);
    for (j = 0; j < k; j++)
        printf("%s\n", sitegasit[j].url);
    for (j = 0; j < k; j++)
        free(sitegasit[j].continut);
    for (j = 0; j < i; j++)
        free(sitehtml[j].continut);
    free(sitehtml);
    free(sitegasit);
    fclose(master);
}