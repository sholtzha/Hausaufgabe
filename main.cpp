#include <iostream>
using namespace std;
#include "zeichenkette4.h"

int main()
{

// 3 Instanzen der Klasse ClZeichenkette anlegen
ClZeichenkette zk1, zk2, zk3;

cout << "Bitte geben Sie eine beliebig lange erste Zeichenkette ein:";
cin >> zk1; // Aufruf des überladenen ">>" Operators
cout << "Bitte geben Sie eine beliebig lange zweite Zeichenkette ein:";
cin >> zk2; // s.o.

zk3 = zk1 + zk2; // Aufruf des überladenen "+" Operators von zk1 aus, mit Variable zk2

/* Soll so implementiert werden, dass '+' als 'Verkettung' definiert ist.
   D.h.: Aus den Ketten 'abc' + 'def' wird: 'abcdef' */

cout << zk1 << " + " << zk2 << " = " << zk3 << endl; // Aufruf des überladenen "<<" Operators

{
	int x;
	cin >> x;
}

}

