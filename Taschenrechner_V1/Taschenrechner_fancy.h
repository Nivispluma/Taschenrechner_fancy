#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Uebergabe
{
	double Nummer1, Nummer2;
	char Operator;
};

double addieren(double, double);
double subtrahieren(double, double);
double multiplizieren(double, double);
double dividieren(double, double);
double rechnen(double, double, char);
double FaktorZahl(double, double);

struct Uebergabe eingabe();

void aufforderung();
void AusgabeErgebnis(double);

double parsing(string);

int main();
