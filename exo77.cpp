
#include <iostream>
using namespace std;

class set_int
{
    int *ptr;
    int nbr_elem=0;

public:
    //constructeur qui alloue de l'espace mémoire pour un tableau et affecte son premier élément au pointeur ptr
    set_int( int nbre=10 )
    {
        ptr= new int [nbre];//allocation dynamique de l'emplacement mémoire nécessaire pour nbre élément
    }

    //fonction d'ajout d'un élément au tableau et incrémentation de cet élément
    void add_elem( int elem )
    {
        //on affecte la valeur à ajouter à l'emplacement voulue
        //ensuite on incrémente le nombre d'élément
        ptr[nbr_elem]= elem;
        nbr_elem += 1;
    }

    //fonction permettant de connaitre le nombre d'élément dans le tableau alloué par le constructeur
    int nbreElem() { return nbr_elem; }

    //test d'appartenace d'un élément au tableau allouer par le constructeur
    int appartenance( int entier )
    {
        //on crée une variable index qu'on peut ou pas initialiser à 0
        //ensuite dans une boucle, si on rencontre une correspondance
        //on ajoute 1 à index et la boucle s'arrête. sinon la boucle continue d'affecter 0 à index
        //a la fin on retourne le contenu de index

        int index=0;
        for( int i=0; i<nbr_elem; i++)
        {
            if( ptr[i]==entier ){ index=1; break;}else{ index=0; }
        }
        return index;
    }

    void affichage()
    {
        for(int i=0; i<nbr_elem; i++)
        {
            cout<<*(ptr+i)<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    int appart;
    set_int mon_objet(6);//création de l'objet

    mon_objet.add_elem(3);//ajout d'un élément
    mon_objet.add_elem(5);//ajout d'un élément
    mon_objet.add_elem(1);//ajout d'un élément
    mon_objet.add_elem(2);//ajout d'un élément
    mon_objet.add_elem(4);//ajout d'un élément

    mon_objet.affichage();

    //test d'appartenance
    appart= mon_objet.appartenance(8);
    cout<<appart<<endl;
}
