#ifndef _STRING
#define _STRING
#include "entete.h"

class String
{
private:
    enum TypActMem{ New=1, Delete= -1};
    char * chaine;
    int nbCarac;
    int tailleMem;
    static int nbInstances;
    static int memInstances;
    char * alloue (int Longeur);
    void gereVarClasse ( TypActMem Action );

public:
    //constructeurs
    String ( const char * Chn ="");
    String ( int tailleChn );
    String ( const char Carac );

    //destructeur
    ~String(){};

    //Accesseurs
    int NbCarac() const;
    int Capacite() const;
    const char * Chaine();
    static int NbInstances();
    static int MemInstances();

    //Fonctions membres opérateurs d'indexation
    char & operator [](int i);
    char operator [] ( int i )const;

    //Fonction membres opérateurs d'affectation
    String & operator = (const String & Source);

    //Fonction amie opérateur de concaténation des chaines
    friend String operator + (const String & source1, const String & source2);

    //Fonctions amies opérateurs de comparaison
    friend int operator != (const String & source1, const String & source2);
    friend int operator == (const String & source1, const String & source2);
    friend int operator > (const String & source1, const String & source2);
    friend int operator < (const String & source1, const String & source2);
    friend int operator >= (const String & source1, const String & source2);
    friend int operator <= (const String & source1, const String & source2);

    //Fonctions opératuers d'entrées/sorties amies
    friend ostream & operator << (ostream & stream, const String & Source);
    friend istream & operator >> (istream & stream, String & Source );

    //Affcihe des valeurs des variables de la classe
    static void AffciheVarClasses (ostream & Stream);

    //Fonctions de manipulation des chaines de caractères
    String SubString (int Debut, int nbCarac) const;
    int StringString (const String & Cherche ) const;
    int StringChar (char Carac ) const;
    void ToUpper();
};

#endif
