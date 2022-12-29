#include <stdio.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------------------------------------------------------------------
// iLyes Bensalah ing-info-grp 04 ,Sa c'est le projet demander , Convertisseur entre les bases (max la base 10),
//-----------------------------------------------------------------------------------------------------------------------------------------
//declaration des fonction
voidaffichage(int vect[],int z);
int mod(int result,int baseN);
int convBaseN(int nbr,int vect[],int baseN);
int powr(int baseI,int i);
int convBase10(int vect[],int nbr,int z);
voidverification(int vect[],int baseI,int z,int *verf);
voidseparateur(int nbr,int vect[],int *z);
//declaration des variables globales
int nbr,baseI,baseN,vect[100],verf,z;
//------------------------------------------------------------------------------------------------------------------------------------------
//////////////////////////////////////////////////Le programe principale//////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    printf("entrer le numero: ");
    scanf("%d",&nbr);
    separateur(nbr,vect,&z);//cette fonction separe le nombre et le met dans vect,si le nombre est 21 le resulat est |2|1|
    printf("entrer la base de ce numero: ");
    scanf("%d",&baseI);
    verification(vect,baseI,z,&verf);//cette fonction verifie que le nombre est vraiment dans la base entrer par l'utilisateur
    if(verf==1){printf("la base initial est fausse\n");main();}//si la base initial donner par l'utilisateur est fausse le programe redemare
    else//si non le programe termine l'execution
    {
     nbr=convBase10(vect,nbr,z);//cette fonction converte le nombre aux base 10 le resultat est met dans nbr
     printf("entrer la base pour la conversation: ");
     scanf("%d",&baseN);
     z=convBaseN(nbr,vect,baseN);//cette fonction converte le nbr aux base 'n' et met le resultat dans le vect,avec un return z pour avoir l'indice dans l'affichage
     printf("le resultat est: ");
     affichage(vect,z);//on utilisant z en peut s'avoir le nombre de case qu'il faut afficher
    }
return 0;}
//-------------------------------------------------------------------------------------------------------------------------------------------
///////////////////////////////////////////////////Les fonctions///////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------------------------------------------------
void affichage(int vect[],int z)
{
    for(int i=z-1;i>=0;i=i-1){printf("%d",vect[i]);}//on affiche du l'inverse pour avoir le resulat correct
}

int mod(int result,int baseN)
{//cette fonction mod donne le rest de la division du deux nombre
    do{result=result-baseN;}while(result>=0);
    result=result+baseN;
    return result;
}

int convBaseN(int nbr,int vect[],int baseN)
{//on utilise la division successive
    int result;
    result=nbr;
    int i=0;
    while(result!=0)
    { vect[i]=mod(result,baseN);//le rest de la division est mis dans le vect pour l'afficher apres
      result=(result/baseN);
      i=i+1;}
      return i;//return i c'est la valeur du z l'indice pour l'affichage
}

int powr(int baseI,int i)
{//cette fonction calcul base initial puissance i
  int power;
  power=1;
  for(int n=1;n<=i;n++){power=(baseI)*(power);}
  return power;
}

int convBase10(int vect[],int nbr,int z)
{
    int i;
    for(i=0;i<=z-1;i++){vect[i]=(vect[i])*(powr(baseI,i));}
    nbr=0;
    for(i=0;i<=z-1;i++){nbr=nbr+vect[i];}//en somme les valeur du vect dans nbr pour avoir le numero dans la base 10
    return nbr;
}

void verification(int vect[],int baseI,int z,int *verf)
{
    int i;*verf=0;
    for(i=0;i<=z-1;i++){if((vect[i])>=baseI){*verf=1;}}//verifiant les valeur du vect si sont superieur aux base ou non
}

void separateur(int nbr,int vect[],int *z)
{// separation de numero pour etre capable de verify la base est du transformer le nombre au base 10
      int i,n;
    *z=0;i=1;n=0;
    while(i<=nbr)
    {
     while((nbr%(i*10))!=0){nbr=nbr-i;n++;}
     vect[*z]=n;
     i=i*10;
     *z=*z+1;//pour avoir le nombre des cases dans le vect qu'il faut utiliser apres
     n=0;
    }
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------/*LA FIN*/-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------


