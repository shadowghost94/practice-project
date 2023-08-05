#include <iostream>
using namespace std;

int main()
{
    int dimension, *adt1, *adt2;

    cout<<"Ce programme alloue dynamiquement de la mémoire pour stocker les valeurs d'un tableau. Il les affche pour ensuite le supprimer plus-tard "<<endl<<endl;
    cout<<"veuillez entrer la taille du tableau à allouer dynamiquement: ";
    cin>>dimension;

    while(dimension<0)
    {
        cerr<<"veuillez entrer une valeur positive: ";
        cin>>dimension;
    }

    adt1= new int [dimension];

    cout<<"Espace allouer avec succès! "<<endl;
    cout<<"Vous devez maintenant remplir le tableau avec des valeur ("<<dimension<<" valeurs)"<<endl;

    for(int i=0; i<dimension; i++)
        {
            cout<<"valeur "<<i+1<<": ";
            cin>>*(adt1+i);
        }

    //creattion du nouveau tableau
    adt2= new int [dimension];

    //affectation du carré des éléments du premier tableau au nouveau tableau
    for(int i=0; i<dimension; i++)
        {
            int val1=*(adt1+i);

            *(adt2+i)= val1*val1;
        }
    delete adt1;

    cout<<"voici les carrés: ";
    for(int i=0; i<dimension; i++){ cout<<*(adt2+i)<<" "; }

    delete adt2;
}
