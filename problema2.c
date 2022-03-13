#include <stdio.h>
#include <stdlib.h>
int numar_nebuni(int t[100][100], int m, int n, int x[100], int y[100]){
    int i,j,k,copt[100][100],nr=0;
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            copt[i][j]=t[i][j];
    for(i=0;i<n;i++) {
        j=x[i];
        k=y[i];
        while(j>0||k>0) {
        //mergem oblic stanga sus
            j--;
            k--;
            if(copt[j][k]==1)
                nr++;
        }
        j=x[i];
        k=y[i];
        while(j<m-1||k<m-1) {
        //mergem oblic dreapta jos
            j++;
            k++;
            if(copt[j][k]==1)
                nr++;
        }
        j=x[i];
        k=y[i];
        while(j<m-1||k>0) {
        //mergem oblic stanga jos
            j++;
            k--;
            if(copt[j][k]==1)
                nr++;
        }
        j=x[i];
        k=y[i];
        while(j>0||k<m-1) {
        //mergem oblic dreapta sus
            j--;
            k++;
            if(copt[j][k]==1)
                nr++;
        }
	copt[x[i]][y[i]]=2;
    }
    return nr;
}
int main()
{
    int n,m,x,y,i,j,k,l,tabla[100][100],xretin[100],yretin[100],nrperechi=0,coptabla[100][100],ok=0;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
            tabla[i][j]=0;
    for(i=0;i<n;i++) {
        scanf("%d%d",&x,&y);
        xretin[i]=x;
        yretin[i]=y;
        tabla[x][y]=1;
    }
    nrperechi=numar_nebuni(tabla,m,n,xretin,yretin);
    printf("%d\n",nrperechi);
    if(nrperechi==1) {
        for(i=0;i<n;i++) {
            x=xretin[i];
            y=yretin[i];
            coptabla[x][y]=0;
            for(k=0;k<m;k++)
                for(l=0;l<m;l++) {
                    if(coptabla[k][l]==0)
                        coptabla[k][l]=1;
                    if(numar_nebuni(coptabla,m,n,xretin,yretin)==0)
                        ok=1;
                    coptabla[k][l]=0;
                }
            coptabla[x][y]=1;
        }
    }
    if(ok==1) printf("DA\n");
    else printf("NU\n");

}

