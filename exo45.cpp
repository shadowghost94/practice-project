#include <iostream>
using namespace std;

int main()
{
    /*programme qui demande à l'utilisateur d'entrer une valeur en chiffre compris entre 1 et 7 puis affiche ensuite le jour corresppondant*/

    char * jour[7]= {"Lundi","Mardi", "Mercredi", "jeudi", "Vendredi", "Samedi", "Diamnche"};
    int valeur;

    cout<<"Veuillez entrer le jour de la semaine (en chiffre): ";
    cin>>valeur;
    while(valeur<1 || valeur>7)
        {
            cout<<"veuillez entrer un chiffre compris entre 1 et 7: ";
            cin>>valeur;
        }

    cout<<"le jour corresppondant a la valeur entré est: "<<*(jour+(valeur-1))<<endl;

    return 0;
}
