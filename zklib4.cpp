#include <iostream>
using namespace std;
#include <string.h>
#include "zeichenkette4.h"


// Konstruktor
ClZeichenkette::ClZeichenkette(
const char                    *anfangswert)
{
laenge=strlen(anfangswert); // Anzahl der Zeichen in laenge speichern
text=new char[laenge+1]; // neuen char-array mit der entsprechendem speicherplatz erzeugen
strcpy(text,anfangswert); // eingelesenen Wert in neuen char-array überschreiben
}

// restliche Member-Funktionen
void ClZeichenkette::verbinde(
const ClZeichenkette         &zk1,
const ClZeichenkette             &zk2)
{
laenge=strlen(zk1.text)+strlen(zk2.text); // laenge der neuen Gesamtzeichenkette in laenge speichern
text=new char[laenge+1]; // neuen char-array mit entsprechendem speicherplatz erzeugen
strcpy(text,zk1.text); // erste zeichenkette kopieren
strcpy(text+zk1.laenge,zk2.text); // zweite zeichenkette anhängen
}

void ClZeichenkette::ladeZk(
istream                    &eingabe)
{
char buffer[10];
char *teil=NULL, *ganzes=NULL;
int gesamt,i,j,k;

// buffer nur bis zum letzen Zeichen der eingelesenen Zeichenkette mit Zeichen füllen
// dabei immer nur 10 Zeichen einlesen und durch wechselweises übertragen zwischen aktuell-gesamten-"teil" und "ganzes" anfügen
for (gesamt=0;;)
    {
    for (i=0;i<9;i++) // immer 10 Zeichen
        {
        eingabe.get(buffer[i]); // einzelnes Zeichen laden
        if (buffer[i]=='\n') break; // wenn Ende der Zeichenkette erreicht beenden
        }
    if (buffer[i]=='\n') break;
    ganzes=new char[gesamt+i];  // char-array für gesamte zeichenkette neu anlegen
    for (j=0;j<gesamt;j++) ganzes[j]=teil[j]; // in "teil" zwischengespeicherte Zeichen (alle in den vorherigen Schritten eingelesenen Zeichen) in "ganzes" speichern
    for (k=0;k<i;k++,j++) ganzes[j]=buffer[k]; // neue Zeichen aus diesem Schritt anfügen
    gesamt+=i; // laenge für gesamte zeichenkette um Anzahl neuer Zeichen erhöhen
    if (teil!=NULL) delete teil; // "teil" reseten
    teil=ganzes; // "teil" enthält jetzt gesamte bisherige zeichen
    }

// Wert des gesamt-buffers in neue Text-Variable mit passender laenge kopieren
laenge=gesamt+i;
text=new char[laenge+1];
for (j=0;j<gesamt;j++) text[j]=teil[j];
for (k=0;k<i;k++,j++) text[j]=buffer[k];
text[j]='\0';
if (teil!=NULL) delete teil;
}
