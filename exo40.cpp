#include <iostream>
using namespace std;

void maxmin(int the_table[], int dim, int *max, int *min)
    {
        *max=the_table[0];
        for( int i=1; i<dim; i++ )
            {
                if( *max<the_table[i] ){ *max=the_table[i]; }else{ continue;}
            }

        *min=the_table[0];
        for( int i=1; i<dim; i++ )
            {
                if( *min>the_table[i] ){ *min=the_table[i]; }else{ continue;}

    }
};

int main()
{
    int my_table[8]={8,10,1,2,19,3,4,5};
    int maximum, minimum;
    maxmin( my_table, 8, &maximum, &minimum );

    cout<<"le maximum donne "<<maximum<<" et le minimum donne "<<minimum<<endl;

    return 0;
};
