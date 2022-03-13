#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int is_anagram(char *s1, char *s2) //verifica daca doua siruri de caracterek primite ca parametru sunt anagrame
{
    int i,j,nr=0;
    char cop2[50],aux[50];
    strcpy(cop2,s2); //facem o copie a sirului s2 pentru ca il vom modifica
    if(strlen(s1)==strlen(s2))
    {
        for(i=0;i<strlen(s1);i++)
        {
        int ok=1;
        for(j=0;j<strlen(cop2)&&ok==1;j++)
                if(s1[i]==cop2[j]) //gasim caracterele comune
                {
                strcpy(aux,cop2+j+1);
                strcpy(cop2+j,aux); //eliminam caracterul gasit din al doilea sir
                j=0;
                ok=0; //modificam ok pentru ca am gasit un caracter comun pentru a trece la urmatorul i
                nr++;
                }
        }
    }
    if(nr==strlen(s2)) return 1; // am aflat numarul de caractere comune si il comparam cu lungimea sirului
    else return 0;
}
double compute_grade(char *s1, char *s2) //calculeaza gradul a doua siruri de caractere primite ca parametru
{
    if(is_anagram(s1,s2)==0)
        return -1; // daca nu sunt anagrame returnam gradul -1
    double grad,nrdif=0,p;
    p=strlen(s1);
    for(int i=0;i<p;i++) if(s1[i]!=s2[i]) nrdif=nrdif+1;
    grad=nrdif/p;
    return grad; //afland caracterele diferite intre ele, le-am impatit la numarul total de caractere si astfel am aflat gradul
}

int main()
{
   int n,i,j;
   double v[1000];
   scanf("%d", &n);
   char s1[50],s2[50],p[1000][100],aux[100];
   for(i=0;i<n;i++)
   {
       scanf("%s%s",s1,s2);
      {
       v[i]=compute_grade(s1,s2); // vector care contine gradele anagramelor
       strcpy(p[i],s1);
       strcat(p[i]," ");
       strcat(p[i],s2); //am retinut intr-un vector de caractere pe cate o linie cate o anagrama
      }
   }
   for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
        if(v[i]<v[j]) //daca gradul lui v[i] mai mic decat gradul lui v[j] interschimbam gradele si sirurile intre pozitiile i si j
        {
            double aux1=v[i];
            v[i]=v[j];
            v[j]=aux1;
            strcpy(aux,p[i]);
            strcpy(p[i],p[j]);
            strcpy(p[j],aux);
        }
        if(v[i]==v[j]&&strcmp(p[i],p[j])<0) //daca gradele sunt egale ordonam descrescator lexico-grafic
        {
            strcpy(aux,p[i]);
            strcpy(p[i],p[j]);
            strcpy(p[j],aux);
        }
    }
   for(i=0;i<n;i++)
    printf("%s\n",p[i]);
   return 0;
}

