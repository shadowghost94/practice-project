#include "c_String.h"
//fonctions de comparaison numérique utilisée max et min utilisées dans les dédfinitions
int max(int value1, int value2) { return ( (value1 > value2)? value1:value2 ); }
int main (int value1, int value2) { return ( (value1<value2)? value1:vlaue2 ); }

//définition/initialisation des variables de classes
int String::nbInstances = 0;
int String::memInstances = 0;

//Fonctions private
char* String::alloue (int Longueur)
    {
        /*fonction privée d'allocation d'espace mémoire pour la chaine stockée.
         Il renvoie un pointeur sur char ou interrompt l'execution si l'allocation échoue */
        if( Longueur < 0 )cerr<<"Allocation négative impossible" ;
        tailleMem= Longueur+1;
        char * P= new char[tailleMem];

        if(!P)
            {
                cerr<<"Allocation impossible";
                exit(1);
            }
        return P;
    }

void String::gereVarClasse (TypActMem Action)
    {
        /* fonction privée de mise à jour des variables de classe. Il permet de suivre le nombre
         d'instances crées, et le mémoire qu'elles occupent */
        if(Action!=New && Action !=Delete){ cerr<<"Valeur du type de l'action mémoire incorrect "<<endl;}
        nbInstances += Action;
        memInstances += Action*(sizeof(String) + ( tailleMem )* sizeof(char) );
    }

//Fonctions public
String::String (const char *Chn)
    {
        //constructeur à partir d'un pointeur
        nbCarac = strlen( Chn );
        chaine = alloue( nbCarac );
        strcpy ( chaine, Chn );
        gereVarClasse (New);
    }

String::String (int LgChn)
    {
        //constructeur à partir d'une longueur de chaine
        nbCarac = 0;
        chaine = alloue( LgChn );
        chaine[0] = '\0';
        gereVarClasse (New);
    }

String::String ( const String & Chn )
    {
        //constructeur copie
        nbCarac = Chn.nbCarac;
        chaine = alloue ( Chn.capacite() );
        strcpy ( chaine, Chn.chaine);
        gereVarClasse ( New );
    }

String::String (const char Carac)
    {
        //constructeur à partir d'un carctère
        nbCarac = 1;
        chaine = alloue ( nbCarac );
        chaine[0] = Carac;
        chaine[1]= '\0';
        gereVarClasse (New);
    }

String::~String()
    {
        //destructeur
        delete [] chaine;
        gereVarClasse(Delete);
    }

int String::NbCarac()const{
    //accesseur en consultation de nbCarac
    return nbCarac;

    }

//accesseur en consultation de la taille mémoire de la chaine
int String::Capacite() const{ return tailleMem-1; }

//accesseur en consultation de la chaine stockée
const char * String::Chaine(){ return chaine; }

//accesseur en consultation de la variable de classe nbInstances
int String::NbInstances() { return nbInstances; }

//accesseur en consulatation de la variable de classe memInstances
int String::MemInstances() { return memInstances; }

char & String::operator[] ( int i )
    {
        if( i<0 || i>=nbCarac)
            {
                cerr<<"Index hors limite \n";
                exit(1);
            }

        return chaine[i]
    }

char String::operator[] ( int i )const
    {
        /*opérateur d'indexation, ne permet la modification du caractère renvoyé.
         il est utilisé sur des objets constants...*/
        if( i<0 || i>=nbCarac )
            {
                cerr<<"Index hors limite \n";
                exit(1);
            }
        return chaine[i];

    }

String& String::operator = ( const String & Source)
    {
        if( chaine != Source.chaine )
        {
            if( Capacite()<Source.nbCarac )
            {
                String::memInstances -= tailleMem;
                delete [] chaine;
                chaine= alloue ( Source.nbCarac );
                String::memInstances += tailleMem;
            }
            nbCarac = Source.NbCarac;
            Strcpy( chaine, Source.chaine );
        }
        return *this;
    }

String operator + (const String & Source1, const String & Source2)
    {
        //opérateur de concaténation
        String Temp( Source1.Capacite()+Source2.Capacite() );
        strcat ( strcpy( Temp.chaine, Source1.chaine), Source2.chaine );
        Temp.nbCarac = strlen( Temp.chaine );
        return Temp;
    }

int operator != ( const String & Source1, const String & Source2 )
    {
        //opérateur différent de
        return ( strcmp( Source1.chaine, Source2.chaine ));
    }
