//
//This empty method body for the classabstractXMLparser.h was created by Jonas Heiss on 07/18/2022
//

#ifndef abstractXMLparser_H
#define abstractXMLparser_H

#include <string>

namespace DHBW {

//Erstellt einen Rumpf zum einlesen von Argumente aus der Kommandozeile.
//Es kann sowohl mit innenliegenden Container wie externer Klassenanbindung eine Datenhaltung erfolgen.
        
//Sobald ein Methodenaufruf abstrakt ist, wird die Basisklasse abstrakt.
//Fuer die Formatierung der generierten Dateien wird astyle verwendet.

class abstractXMLparser{

 public:
 std::string workingdir;


void getOpts(int argc, char **argv);

//Diese Hilfe ausgeben und beenden
void printhelp();

//Gibt die Version des Programms aus und beendet
void printversion();

//Gibt XML an die eingelesen werden soll
virtual void loadXML(- -)=0;

//Erstellt eine Cfile aus der eingelesen XML
virtual void makeCFile(- -)=0;

//Erzeugt Header file zur CFile
virtual void makeHFile(- -)=0;

}
;}

#endif