//
//This empty method body for the classabstractXMLparser.h was created by Jonas Heiss on 07/21/2022
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
const std::string helptext="Overall Description:"
"Erstellt einen Rumpf zum einlesen von Argumente aus der Kommandozeile."
"Es kann sowohl mit innenliegenden Container wie externer Klassenanbindung eine Datenhaltung erfolgen."
"Sobald ein Methodenaufruf abstrakt ist, wird die Basisklasse abstrakt."
"Fuer die Formatierung der generierten Dateien wird astyle verwendet."

"Sample Usage:"
"getoptgen [options] ... QUELLE"
"getoptgen [--out-path] ... QUELLE"

"Options:"
" ShortOpt: h LongOpt: help Description: Diese Hilfe ausgeben und beenden"
" ShortOpt: v LongOpt: - Description: Gibt die Version des Programms aus und beendet"
" ShortOpt: g LongOpt: generate Description: Gibt XML an die eingelesen werden soll"
 
"Kontaktdaten:"
"Autoren: Jonas Heiss Email: Jonas.Heiss@AliExpress.com";const std::string version="tba";std::string path;


void parseOptions(int argc, char **argv);

//Diese Hilfe ausgeben und beenden
void printhelp();

bool isSethelptext();

//Gibt die Version des Programms aus und beendet
void printversion();

bool isSetversion();

//Gibt XML an die eingelesen werden soll
virtual void generate(std::string path)=0;

std::string getValueOfpath();

bool isSetpath();

}
;}

#endif