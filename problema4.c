#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// functie pentru transformarea unui numar din baza 10 in baza 2
void dec_to_bin (int n, char *s) {
    if(n%2==1)
        strcpy(s,"1");
    else
        strcpy(s,"0");
    n=n/2;
    char aux[100]={'\0'};
    while(n!=0) {
        if(n%2==1) {
            strcpy(aux,s);
            strcpy(s,"1");
            strcat(s,aux);
        }
        else {
            strcpy(aux,s);
            strcpy(s,"0");
            strcat(s,aux);
        }
        n=n/2;
    }
    while(strlen(s)!=8) {
        strcpy(aux,s);
        strcpy(s,"0");
        strcat(s,aux);
    }
}
// functie pentru transformarea unui numar din baza 2 in baza 10
int bin_to_dec(char *s) {
    int n=0,i=0;
    float j=0.5;
    for(i=strlen(s)-1; i>=0; i--) {
        if(s[i]=='1')
            n=n+j*2;
        j=j*2;
    }
    return n;
}
// functie pentru inmultirea a doua matrice patratice, de dimensiune 8x8
void inmultire_matrici(int mi[8][8], int m1[8][8], int m2[8][8]) {
    int i=0,j=0,k=0;
    for(i=0; i<8; i++)
        for(j=0; j<8; j++) {
            mi[i][j]=0;
            for(k=0; k<8; k++) {
                mi[i][j]=mi[i][j]+m1[i][k]*m2[k][j];
            }
        }
}
// functie pentru aflarea transpusei unei matrice patratice, de dimensiune 8x8
void transpusa_matricei(int a[8][8], int atr[8][8]) {
    int i=0,j=0;
    for(i=0; i<8; i++)
        for(j=0; j<8; j++) {
            atr[i][j]=a[j][i];
        }
}
int sum_X_0(int m[][8])
{
    int i=0,j=0,nr1=0,nr2=0,nr3=0,nr4=0,nr5=0,nr6=0,nr7=0,nr8=0,nr9=0,nr10=0,nr11=0,nr12=0,nr13=0,nr14=0,nr15=0,nr16=0,sum=0;
    for(i=0; i<4; i++) { //aflam daca sunt linii care contin numai 1 sau coloane care contin numai 1 din cele 4 mini-matrici formate prin impartirea celei mari in 4
        nr1=0;
        nr2=0;
        nr3=0;
        nr4=0;
        nr5=0;
        nr6=0;
        nr7=0;
        nr8=0;
        for(j=0; j<4; j++) {
            /*parcurgere linii*/
            if(m[i][j]==1)
                nr1++;
            if(m[i+4][j]==1)
                nr2++;
            if(m[i][j+4]==1)
                nr3++;
            if(m[i+4][j+4]==1)
                nr4++;
            /*parcurgere coloane*/
            if(m[j][i]==1)
                nr5++;
            if(m[j+4][i]==1)
                nr6++;
            if(m[j][i+4]==1)
                nr7++;
            if(m[j+4][i+4]==1)
                nr8++;
        }
        if(nr1==4)
            sum++;
        if(nr2==4)
            sum++;
        if(nr3==4)
            sum++;
        if(nr4==4)
            sum++;
        if(nr5==4)
            sum++;
        if(nr6==4)
            sum++;
        if(nr7==4)
            sum++;
        if(nr8==4)
            sum++;
    }
    for(i=0; i<4; i++) //aflam daca diagonala principala sau secundara contin numai 1 in matricea din stanga sus
        for(j=0; j<4; j++) {
            if(i==j&&m[i][j]==1) // i=j pentru diagonala principala
                nr9++;
            if(i+j==3&&m[i][j]==1) // i+j=n-1 pentru diagonala secundara
                nr10++;
        }
    if(nr9==4)
        sum++;
    if(nr10==4)
        sum++;
    for(i=4; i<8; i++) //aflam daca diagonala principala sau secundara contin numai 1 in matricea din dreapta sus
        for(j=0; j<4; j++) {
            if(i-4==j&&m[i][j]==1)
                nr11++;
            if(i+j==7&&m[i][j]==1) //i+j=8-1
                nr12++;
        }
    if(nr11==4)
        sum++;
    if(nr12==4)
        sum++;
    for(i=4; i<8; i++) //aflam daca diagonala principala sau secundara contin numai 1 in matricea din dreapta jos
        for(j=4; j<8; j++) {
            if(i==j&&m[i][j]==1)
                nr13++;
            if(i+j==11&&m[i][j]==1) // i+j=12-1
                nr14++;
        }
    if(nr13==4)
        sum++;
    if(nr14==4)
        sum++;
    for(i=0; i<4; i++) //aflam daca diagonala principala sau secundara contin numai 1 in matricea din stanga jos
        for(j=4; j<8; j++) {
            if(i==j-4&&m[i][j]==1)
                nr15++;
            if(i+j==7&&m[i][j]==1) // i+j=8-1
                nr16++;
        }
    if(nr15==4)
        sum++;
    if(nr16==4)
        sum++;
    return sum; // sum este suma formata prin adunarea punctelor obtinute in cazul in care gasim linii, coloane sau diagonale care contin numai 1 din cele 4 mini-matrici
}
int main() {
    int n=0,a[8][8]={{0}},tr[8][8]={{0}},atr[8][8]={{0}},apatrat[8][8]={{0}},i=0,j=0,pa=0,pa2=0,patr=0,e=0;
    char s[8][9]={{0}};
    for(i=0;i<8;i++)
        for(j=0;j<8;j++) {
            a[i][j]=0;
            tr[i][j]=0;
            atr[i][j]=0;
            apatrat[i][j]=0;
        }
    for(i=0; i<8; i++) {
        scanf("%d", &n);
        dec_to_bin(n,s[i]); // fiecare numar n transformat in baza 2 este retinut intr-un vector sir de caractere
    }
    for(i=0; i<8; i++)
        for(j=0; j<8; j++) { //transform vectorul sir de caractere intr-o matrice
            if(s[i][j]=='0')
                a[i][j]=0;
            if(s[i][j]=='1')
                a[i][j]=1;
        }
    transpusa_matricei(a,tr);
    inmultire_matrici(atr,a,tr);
    inmultire_matrici(apatrat,a,a);
    for(i=0; i<8; i++)
        for(j=0; j<8; j++) { //dupa ce inmultim matricile, ne folosim de logica booleana ca sa avem numai 0 si 1 (astfel un numar in baza 2)
            if(apatrat[i][j]!=0) apatrat[i][j]=1;
            if(atr[i][j]!=0) atr[i][j]=1;
        }
    pa=sum_X_0(a); //pa este scorul pentru matricea A
    pa2=sum_X_0(apatrat); //pa2 este scorul pentru matricea A patrat
    patr=sum_X_0(atr); //patr este scorul pentru matricea (A * A transpus)
    if(pa>=patr&&pa>=pa2) {
        for(i=0; i<8; i++) { //daca pa este cel mai mare scor, transformam numerele in baza 2 in numere in baza 10
            e=bin_to_dec(s[i]);
            printf("%d\n", e);
        }
    }
    else if(patr > pa && patr >= pa2) {
            char s2[9]={'\0'};
            for(i=0; i<8; i++) {
                for(j=0; j<8; j++)
                    if(atr[i][j]==0)
                        s2[j]='0';
                    else
                        s2[j]='1';
                e=bin_to_dec(s2);
                printf("%d\n", e);
            }
         }
    else {
        char s3[9]={'\0'};
        for(i=0; i<8; i++) {
            for(j=0; j<8; j++)
                if(apatrat[i][j]==0)
                    s3[j]='0';
                else
                    s3[j]='1';
            e=bin_to_dec(s3);
            printf("%d\n",e);
        }
    }
}


