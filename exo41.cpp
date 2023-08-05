#include <iostream>
using namespace std;

int somme(int the_table[], int dim)
    {
        int sommes=0;
        for( int i=0; i<dim; i++)
            {
                sommes+=the_table[i];
            }

        return sommes;
    };

int main()
{
    int tableau[8]={ 8,10,1,2,19,3,4,5 };
    int sommes, dimension=8;

    sommes=somme(tableau, dimension);

    cout<<"la somme de tous les éléments du tableau donne "<<sommes<<endl;

    return 0;
}
