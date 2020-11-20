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

//-----------rechnen------------------------------

double rechnen(double Zahl1, double Zahl2, int Rechenzeichen)
{
	//-----deklaration-----

	double TempErgebnis = 0;

	//-----tatsächliche Funktion--------

	switch (Rechenzeichen) // anhand der codierten Zahl "Rechenzeichen" wird die entsprechende Rechenoperation ausgeführt 
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

//------------Ausgabe----------------------------

void AusgabeErgebnis(double ausgabe)
{
	cout << "das Ergebnis ist: " << ausgabe << endl << endl << endl << endl;
}

//--------Eingabeaufforderung-----------------------

void aufforderung() // ganz ez nur die Ausgabe, dass man lesen soll
{
	cout << "Folgen sie den Anweisungen in der Konsole!" << endl;
	return;
}

//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------


//--------Eingabe-----------------------------------

struct ParsingExtern eingabe()
{
	string eingabe;
	cout << endl << "Geben sie ihre Rechnung mit zwei Zahlen und einem Rechenoperator an" << endl;
	cin >> eingabe;

	
	struct ParsingExtern TempUebergabe = parsing(eingabe); //der string wird gelesen und dann am rechenzeichen auseinander genommen

	return TempUebergabe;
}


//-----------parsing--------------------------

double ParsingZahl(string UebergabeTeilString)
{
	//string EingabeZahl; //Zahlen die eingegeben oder übergeben werden
	string VergleichZahlen; //reihe von zahlen, die verglichen werden
	string Hilfe; //Hilfstrings, weil string.compare scheisse ist 
	string Hilfe2;

	VergleichZahlen = "0123456789"; //Initialisierung des Vergleichstrings 

	int laengeString, gesuchteZahl, neueZahl;
	laengeString = 0;
	gesuchteZahl = 0;
	

	//Laufvariablen
	int indexString = 0;
	int index2 = 0;

	laengeString = UebergabeTeilString.length();

	for (int index = laengeString; index > 0; index--) //Alle zeichen im String abklappern
	{


		index2 = 0; //neu setzenLaufvariable 

		do //Zeichen im Vergleichsstring anschauen
		{

			Hilfe2 = VergleichZahlen[index2];
			Hilfe = UebergabeTeilString[indexString];

			if (Hilfe.compare(Hilfe2) == 0) //Wenn die Zeichen an der Stelle gleich sind, dann ist das eine neue Zahl
			{
				neueZahl = stoi(Hilfe); //Zahl im String to Int 
				gesuchteZahl = FaktorZahl(gesuchteZahl, neueZahl);

				index2 = 15;
			}

			index2++;

		} while (index2 < 10); //druchlaufen aller zeichen in "string VergleichZahlen"

		indexString++;
	}

	return gesuchteZahl;
}

struct ParsingIntern Rechenzeichen(string Uebergabe)
{
	//-----deklaration-------

	//string Zeichenkette;

	string gesuchtesZeichen;
	gesuchtesZeichen = "+-*/";

	int index1, index2;
	size_t TrennungOrt;
	int WelchesRechenzeichen; // + = 0 ; - = 1 ; * = 2 ; / = 3


	index1 = 0;
	index2 = 0;
	WelchesRechenzeichen = 4; //damit INT einen wert hat und sich nicht beschwert 

	//-----tatsächliches Programm-------

	do
	{
		//size_t ist ne art Variable

		size_t found = Uebergabe.find(gesuchtesZeichen[index2]); //suche eines der rechenzeichen aus dem string, je nach laufvariable
		if (found != string::npos)
		{
			index1 = 1;
			WelchesRechenzeichen = index2; //die größe von index 2 bestimmt dann, welches codierte rechenzeichen es tatsächlich im string ist 
			TrennungOrt = found;

		}

		else
		{
			index1 == 1;

		}
		index2++;

	} while (index1 == 0);

	struct ParsingIntern Temp; //TrennungOrt, WelchesRechenzeichen
	Temp.codRechenzeichen = WelchesRechenzeichen;
	Temp.Trennung = TrennungOrt;


	return Temp;
}

//-----

double FaktorZahl(double AlteZahl, double NeueZahl) // Schiebt die alte Zahl um eine dezimalstelle nach vorne und addiert dann die neue Zahl darauf
{													// aus 99 wird dann 990, dann wird die neue einstellige natürliche Zahl addiert 
	AlteZahl = AlteZahl * 10;
	AlteZahl = AlteZahl + NeueZahl;
	return AlteZahl;
}

//------

struct ParsingExtern parsing(string EingabeZahl)
{
	int laengeString, RechenOperator;
	RechenOperator = 5;
	laengeString = 0;


	// Hilfsdouble 

	double Temp1 = 0;
	double Temp2 = 0;

	laengeString = EingabeZahl.length(); //Länge des strings für die Schleife 

	struct ParsingIntern TempStringSplit = Rechenzeichen(EingabeZahl);

	RechenOperator = TempStringSplit.codRechenzeichen;



	//--------Trennung durch Rechenzeichen--------

		//----deklaration------

	//string EingabeZahl; // <------
	string ersterNeuerString;
	string zweiterNeuerString;

	size_t TrennungsOrt;
	size_t HilfeBeiTrennung;

	//----Funktion-----

	int laenge = EingabeZahl.length(); // <-----

	struct ParsingIntern TempSplitString = Rechenzeichen(EingabeZahl); // <------

	TrennungsOrt = TempSplitString.Trennung;

	HilfeBeiTrennung = laenge - TrennungsOrt + 1;

	ersterNeuerString = EingabeZahl.substr(0, TrennungsOrt); // <-----
	zweiterNeuerString = EingabeZahl.substr(TrennungsOrt + 1, HilfeBeiTrennung); //<-----

	//--------Raussuchen der richtigen Zahl-------

	Temp1 = ParsingZahl(ersterNeuerString);
	Temp2 = ParsingZahl(zweiterNeuerString);


	//Parsing Extern: Zahl1, Zahl2, Operator;
	struct ParsingExtern TempReturn; // = { Temp1, Temp2, RechenOperator };
	TempReturn.Nummer1 = Temp1;
	TempReturn.Nummer2 = Temp2;
	TempReturn.Operator = RechenOperator;



	return TempReturn;
}

//--------------------------------------------------

int main()
{
	//---deklaration----
	double TempErgebnis, tempZahl1, tempZahl2;
	int tempRechnenzeichen;

	//--------------
	do {
		aufforderung();

		struct ParsingExtern eingabeTMP = eingabe();

		tempZahl1 = eingabeTMP.Nummer1;
		tempZahl2 = eingabeTMP.Nummer2;
		tempRechnenzeichen = eingabeTMP.Operator;

		TempErgebnis = rechnen(tempZahl1, tempZahl2, tempRechnenzeichen);

		AusgabeErgebnis(TempErgebnis);
	} while (true);
	return 0;
}

//--------------------------------------------------













