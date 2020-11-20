#pragma once

#include <iostream>
#include <string>

using namespace std;

struct ParsingIntern //bleibt innerhalb der parsing() funktion
{
	int codRechenzeichen;
	size_t Trennung;
};

struct ParsingExtern //für die kommunikation nach aussen
{
	double Nummer1, Nummer2;
	int Operator;
};


double rechnen(double, double, int);  //Rechnen übergibt die zahlen an die jeweilige rechenoperation
	double addieren(double, double);	// die rechenarten sind selbsterklärend 
	double subtrahieren(double, double);
	double multiplizieren(double, double);
	double dividieren(double, double);


struct ParsingExtern eingabe(); //main interagiert mit eingabe()
	struct ParsingExtern parsing(string); //parsing nimmt den eingelesenen string auf, und zertrennt ihn später dann
		struct ParsingIntern Rechenzeichen(string); //extrahiert die Art und Position des Rechenzeichens 
		double ParsingZahl(string); //interpretiert die zerlegten Strings als zahl
			double FaktorZahl(double, double); //eine art schieberegister

void aufforderung(); // eingabeaufforderung zu beginn des programms 
void AusgabeErgebnis(double); // ausgabe 



int main();
