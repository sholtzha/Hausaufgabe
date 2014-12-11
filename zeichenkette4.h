#include <string.h>

class ClZeichenkette
   {
private:
   char *text;
   int laenge;
   void verbinde ( const ClZeichenkette &zk1, const ClZeichenkette &zk2 );
   void ladeZk ( istream &eingabe);

public:
   // alternative Konstruktoren mit verschiedenen Signaturen (Werte-Polymorphie)
   ClZeichenkette() { text=NULL; laenge=0; } // bei Aufruf ohne anfangswert wird "leere" Instanz erzeugt
   ClZeichenkette(const char *anfangswert); // sonst mit entsprechender Zeichenkette

   char *kette() { return text; } // Wert der private-Variable text zurückgeben
   int anzahl() { return laenge; } // Wert der private-Variable laenge zurückgeben

   // Operator "<<" der Klassse ostream überladen
   friend ostream & operator << (ostream &ausgabe, ClZeichenkette &zk)
      {
       // Wert der text-Variable zurückgeben
      ausgabe << zk.text;
      return ausgabe;
      }

   // Operator ">>" der Klasse istream überladen
   friend istream & operator >> (istream &eingabe, ClZeichenkette &zk)
      {
      zk.ladeZk(eingabe); // Memberfunktion ladeZk mit eingegebener Zeichenkette aufrufen
                          // -> Benutzereingabe in Objekt speichern
      return eingabe;
      }

   // Operator "+" überladen
   ClZeichenkette operator+ (const ClZeichenkette & zk2)
      {
      ClZeichenkette neuzk; // neue Instanz der Klasse ClZeichenkette erzeugen
      neuzk.verbinde(*this, zk2);   // Memberfunktion "verbinde" von aktuellem Objekt aufrufen, mit zweitem als Variable
      return neuzk; // Gesamtzeichenkette zurückgeben
      }
   } ;
