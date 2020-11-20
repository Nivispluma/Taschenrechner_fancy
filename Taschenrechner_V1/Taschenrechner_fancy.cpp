// Taschenrechner.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//


#include "Taschenrechner_fancy.h"

using namespace std;

//-----------deklaration--------------------------



//-----------addieren-----------------------------

double addieren(double Add1, double Add2)
{
	double Summe;

	Summe = Add1 + Add2;

	return Summe;
}

//---------------subtrahieren------------------------

double subtrahieren(double Sub1, double Sub2)
{
	double Summe;

	Summe = Sub1 - Sub2;

	return Summe;
}

//--------multiplizieren------------------

double multiplizieren(double Fak1, double Fak2)
{
	double Ergebnis;

	Ergebnis = Fak1 * Fak2;

	return Ergebnis;
}

//------dividieren------------------------------

double dividieren(double Div1, double Div2)
{
	double Ergebnis;

	Ergebnis = Div1 / Div2;

	return Ergebnis;
}

//-----------Auswahl-----------------------------

int AuswahlOperation(char AuswahlRechenzeichen)
{
	int OperationInt;

	const char add = '+';
	const char sub = '-';
	const char mul = '*';
	const char div = '/';



	//Wenn der sting AuswahlRechenzeichen gleich ist, dann setzt den Int auf bestimmten wert damit später Case die Zahl verwenden kann

	if (AuswahlRechenzeichen == add) //Vergleiche Sting mit den oben definierten Strings &&&&& AuswahlRechenzeichen.compare(add) == 0
	{
		OperationInt = 0;
	}

	else if (AuswahlRechenzeichen == sub)
	{
		OperationInt = 1;
	}

	else if (AuswahlRechenzeichen == mul)
	{
		OperationInt = 2;
	}

	else if (AuswahlRechenzeichen == div)
	{
		OperationInt = 3;
	}

	else //Exception handeling 
	{
		OperationInt = 4;
	}

	return OperationInt;
}

//-----------rechnen------------------------------

double rechnen(double Zahl1, double Zahl2, char RechenOperator)
{
	//-----deklaration-----

	int Rechenzeichen = 4;
	int TempErgebnis = 0;

	//-----tatsächliche Funktion--------

	Rechenzeichen = AuswahlOperation(RechenOperator); //das ASCI-Zeichen der Rechenoperation wird interpretiert 

	switch (Rechenzeichen) // anhand der interpretierten Zahl wird die Rechenoperation ausgeführt 
	{
	case 0:
		TempErgebnis = addieren(Zahl1, Zahl2);
		break;
	case 1:
		TempErgebnis = subtrahieren(Zahl1, Zahl2);
		break;
	case 2:
		TempErgebnis = multiplizieren(Zahl1, Zahl2);
		break;
	case 3:
		TempErgebnis = dividieren(Zahl1, Zahl2);
		break;
	case 4:
		cout << endl << "Fehleingabe";
	}


	return TempErgebnis;
}

//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------

//--------Eingabeaufforderung-----------------------

void aufforderung()
{
	cout << "Folgen sie den Anweisungen in der Konsole!" << endl;
	return;
}

//--------Eingabe-----------------------------------

struct Uebergabe eingabe()
{
	//----deklaration----

	string ersteZahlString, zweiteZahlString;
	double ersteZahl, zweiteZahl;
	char RechenOperator;

	//-----AUS und EINgabe

	cout << "Erste Zahl: ";
	cin >> ersteZahlString;
	ersteZahl = parsing(ersteZahlString);
	cout << "Rechenoperation: ";
	cin >> RechenOperator;
	cout << "Zweite Zahl: ";
	cin >> zweiteZahlString;
	zweiteZahl = parsing(zweiteZahlString);
	cout << endl << endl;

	//Erstellen des "Structs" zur Übergabe 

	struct Uebergabe Temp = { ersteZahl, zweiteZahl, RechenOperator };

	return Temp;
}

//------------Ausgabe----------------------------

void AusgabeErgebnis(double ausgabe)
{
	cout << "das Ergebnis ist: " << ausgabe;
}

//-----------parsing--------------------------

//Beide Funktion gehören zu Parsing 

double FaktorZahl(double AlteZahl, double NeueZahl) // Schiebt die alte Zahl um eine dezimalstelle nach vorne und addiert dann die neue Zahl darauf
{													// aus 99 wird dann 990, dann wird die neue einstellige natürliche Zahl addiert 
	AlteZahl = AlteZahl * 10;
	AlteZahl = AlteZahl + NeueZahl;
	return AlteZahl;
}


double parsing(string EingabeZahl)
{
	//string EingabeZahl; //Zahlen die eingegeben oder übergeben werden
	string VergleichZahlen; //reihe von zahlen, die verglichen werden
	string Hilfe; //Hilfstrings, weil string.compare scheisse ist 
	string Hilfe2;

	VergleichZahlen = "0123456789";

	int laengeString, gesuchteZahl, neueZahl;
	laengeString = 0;
	gesuchteZahl = 0;

	//Laufvariablen
	int indexString = 0;
	int index2 = 0;

	//Troubleshooting
	//cout << "eingabe Zahlenkette" << endl;
	//cin >> EingabeZahl; // Einlesen des Strings 

	laengeString = EingabeZahl.length(); //Länge des strings für die Schleife 


	//--------Trennung durch Rechenzeichen--------

	/*if (EingabeZahl.find('+'))

	for (int index = laengeString; index > 0; index--)
	{

	}*/

	//--------Raussuchen der richtigen Zahl-------

	for (int index = laengeString; index > 0; index--) //Alle zeichen im String abklappern
	{


		index2 = 0; //neu setzenLaufvariable 

		do //Zeichen im Vergleichsstring anschauen
		{

			Hilfe2 = VergleichZahlen[index2];
			Hilfe = EingabeZahl[indexString];

			//Troubleshooting
			//cout << "Hilfe 1: " << Hilfe<<endl;
			//cout << "Hilfe 2: " << Hilfe2<<endl<<endl;

			if (Hilfe.compare(Hilfe2) == 0) //Wenn die Zeichen an der Stelle gleich sind, dann ist das eine neue Zahl
			{
				neueZahl = stoi(Hilfe); //Zahl im String to Int 
				gesuchteZahl = FaktorZahl(gesuchteZahl, neueZahl);

				//Troubleshooting
				//cout << "test"<<endl;
				index2 = 15;
			}

			index2++;

		} while (index2 < 10); //druchlaufen aller zeichen in "string VergleichZahlen"

		indexString++;
	}

	//Troubleshooting
	//cout << "Die Zahl ist: " << gesuchteZahl;

	return gesuchteZahl;
}
/*
{
	//string EingabeZahl;
	int laengeString, gesuchteZahl;
	laengeString = 0;
	gesuchteZahl = 0;

	//Troubleshooting zeug

	//cout << "eingabe Zahlenkette" << endl;
	//cin >> EingabeZahl;

	laengeString = EingabeZahl.length();

	//Troubleshooting zeug
	//cout << laengeString << endl;

	int indexString = 0;

	//--------Trennung durch Rechenzeichen--------

	if (EingabeZahl.find('+'))
	{
		string HilfeRechenzeichen;
		HilfeRechenzeichen = "+";
	}
	else if (EingabeZahl.)

		for (int index = laengeString; index > 0; index--)
		{

		}

	//--------Raussuchen der richtigen Zahl-------

	for (int index = laengeString; index > 0; index--)
	{


		string VergleichZahlen;
		string Hilfe;

		VergleichZahlen = "0123456789";

		int index2 = 0;

		do
		{
			string Hilfe2;
			Hilfe2 = VergleichZahlen[index2];
			Hilfe = EingabeZahl[indexString];

			//Troubleshooting zeug
			//cout << "Hilfe 1: " << Hilfe << endl;
			//cout << "Hilfe 2: " << Hilfe2 << endl << endl;

			if (Hilfe.compare(Hilfe2) == 0)
			{
				int ARM = stoi(Hilfe);
				gesuchteZahl = FaktorZahl(gesuchteZahl, ARM);

				//Troubleshooting zeug
				//cout << "test" << endl;

				index2 = 15;
			}

			index2++;

		} while (index2 < 10);

		indexString++;
	}

	//Troubleshooting zeug
	//cout << "Die Zahl ist: " << gesuchteZahl;

	return gesuchteZahl;
}*/

//--------------------------------------------------

int main()
{
	//---deklaration----
	double TempErgebnis, tempZahl1, tempZahl2;
	char tempRechnenzeichen;

	//--------------

	aufforderung();

	struct Uebergabe eingabeTMP = eingabe();

	tempZahl1 = eingabeTMP.Nummer1;
	tempZahl2 = eingabeTMP.Nummer2;
	tempRechnenzeichen = eingabeTMP.Operator;

	TempErgebnis = rechnen(tempZahl1, tempZahl2, tempRechnenzeichen);

	AusgabeErgebnis(TempErgebnis);
	return 0;
}

//--------------------------------------------------













