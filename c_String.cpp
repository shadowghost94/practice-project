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

int operator == ( const String & Source1, const String & Source2 )
    {
        //opérateur égal
        return ( !( Source1 != Source2 ));
    }

int operator > ( const String & Source1, const String & Source2 )
    {
        return ( strcmp( Source1.chaine, Source2.chaine ) >0 );
    }

int operator < ( const String & Source1, const String & Source2 )
    {
        return ( strcmp(Source1.chaine, Source2.chaine) <0 );
    }

int operator >= ( const String & Source1, const String & Source2 )
    {
        return (!(Source1<Source2));
    }

int operator <= ( const String & Source1, const String & Source2 )
    {
        //opérateur inférieur ou égal à
        return (! (Source1>Source2));
    }

istream& operator >> ( istream & Flot, String & Source )
    {
        //opérateur de saisi dans une flux
        int TailleMax = 80;
        char c;
        String Temp ( TailleMax );
        Source = "";
        while( Flot.get(c) && c!='\n' )
            {
                Flot.putback(c);
                Flot.get( Temp.chaine, temp.tailleMem, '\n');
                Temp.nbCarac = strlen( Temp.chaine );
                Source+= Temp;
            }

        return Flot;
    }

ostream& operator << ( ostream & Flot, const String & Source )
    {
        return Flot<<"Chaine:\""<<Source.chaine<<"\"de "<<Source.nbCarac<<" et pouvant contenir "<<Source.Capacite();
    }

void String::AfficheVarClasses( ostream & Flot )
    {
        //fonction d'aafichage des varibles de classes
        Flot<<String::nbInstances<<" instances occupant "<<String::memInstances<<" octets"<<endl;
    }

String String::SubString( int Debut, int NbCarac=0 )const
    {
        //extrait une sous chaine de nbCarac depuis la position debut
        NbCarac = ( NbCarac>0? min( NbCarac, nbCarac ):nbCarac);

        String Temp(NbCarac);
        strncpy (Temp.chaine, chaine+Debut, NbCarac);
        Temp.chaine[NbCarac] = '\0';
        Temp.nbCarac= NbCarac;

        return temp;
    }

int String::StringString( const String & Cherche ) const
    {
        /*Renvoie la position du début de la chaine Cherche dans l'objet récepteur,
         ou une valeur négative si Cherche n'est pas trouvé */
        return ( strstr( chaine, Cherche.chaine )-chaine);

    }

int String::StringChar( char Carac )const
    {
        /*retourne la position du caractère recherché Carac ou une valeur
            négative si ce n'est pas trouvé*/
        return ( strchr(chaine,Carac)-chaine );

    }

void String::ToUpper()
    {
        //met la chaine de caractère pointée par le membre chaine en majuscules
        if( nbCarac== 0 )return;
        for( char * Ptr = chaine; *Ptr != '\0'; Ptr++)
            {
                if( isalpha(*Ptr) ) *Ptr=toupper(*Ptr);
                else
                    if(! isdigit(*Ptr) ) *Ptr=' ';
            }
        Ptr--;
        if( *Ptr ==' '){ *Ptr= '\0'; nbCarac--; }
    }
