//
// Created by elias on 6/8/2022.
//

#include "readXML.h"
#include <xercesc/util/XMLString.hpp>
#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
XERCES_CPP_NAMESPACE_USE

#include <locale>
#include <codecvt>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace DHBW;

bool cmp (const opt& i,const opt& j)
{
    string checki;
    string checkj;
    if(i.longOpt.empty()){
        checki = i.shortOpt;
    }
    else{
        checki = i.longOpt;
    }
    if(j.longOpt.empty()){
        checkj = j.shortOpt;
    }
    else{
        checkj = j.longOpt;
    }
    return (checki<checkj);
}
class SimpleSAXParser : public HandlerBase {
public:
    void startDocument() override {
    }
    void endDocument() override {
        sort(classdata.optarr.begin(), classdata.optarr.end(), &cmp);
    }

    void startElement(const XMLCh* const name, AttributeList& attributes) override {
        start = XMLString::transcode(name);


        for (XMLSize_t i = 0; i < attributes.getLength(); ++i)
            setStruct(start, XMLString::transcode(attributes.getName(i)), XMLString::transcode(attributes.getValue(i)));
    }

    void endElement(const XMLCh* const name) override {
        string end;
        end = XMLString::transcode(name);
        if(end == "Option")
        {
            classdata.optarr.push_back(options);
            clearoptions();
            options.hasargs = no_argument;
        }
    }

    void characters(const XMLCh* const chars, const XMLSize_t length) override {
        setStruct(start, XMLString::transcode(chars));
    }
    filedata getClassdata()
    {
        return classdata;
    }
private:
    string start;
    filedata classdata;
    opt options;
    wstring_convert<codecvt_utf8_utf16<char16_t>,char16_t> converter{};

    void clearoptions()
    {
        options.Ref = 0;//standardmäßig 0 wird genutzt für excludes
        options.shortOpt = '-';
        options.longOpt = "";
        options.interface = '-';
        options.exclusions.clear();//Ref der Opts die nicht mit dieser aufgerufen werden dürfen
        options.convertTo = '-'; //Datentyp des folgeparameters
        options.deafaultValue = '-';
        options.connectedtoInternalMethodName = "";
        options.connectedtoExternalMethodName = "";
        options.hasargs = no_argument;
        options.description = '-';
    }
    void getExclusions(const string& value)
    {
        for(char i : value)
        {
            if(i != ',')options.exclusions.push_back(i);
        }
    }
    void setStruct(const string& name, const string& key, string value)
    {
        if(name == "Author")
        {
            if(key == "Name")classdata.author = value;
            else if(key == "Phone")classdata.telephonenumber = value;
            else if(key =="Mail")classdata.email = value;
        }

        else if(name=="GetOptSetup") classdata.SignPerLine = value;
        else if(name == "Option")
        {
            if(key == "Ref")options.Ref = stoi(value);
            else if(key == "ShortOpt")options.shortOpt = value.at(0);
            else if(key == "LongOpt")options.longOpt = value;
            else if(key == "Exclusion")getExclusions(value);
            else if(key == "ConnectToInternalMethod")options.connectedtoInternalMethodName = value;
            else if(key == "ConnectToExternalMethod")options.connectedtoExternalMethodName = value;
            else if(key == "Description")options.description = value;
            else if(key == "DefaultValue")options.deafaultValue = value;
            else if(key == "interface")options.interface = value;
            else if(key == "convertTo")options.convertTo = value;
            else if(key == "HasArguments"){
                if(value == "Required")options.hasargs = required_argument;
                else if(value == "optional")options.hasargs = optional_argument;
            }
        }
    }

    void setStruct(const string& startelement, const string& value)
    {

        if(value != "\n\t" && value != "\n\t\t"&&value.substr(0,1)!="\n") {
            if(startelement == "HeaderFileName")classdata.hfilename = value;
            else if(startelement=="Version")classdata.version=value;
            else if(startelement == "SourceFileName")classdata.cfilename = value;
            else if(startelement == "NameSpace")classdata.nameSpaceName = value;
            else if(startelement == "ClassName")classdata.classname = value;
            else if(startelement == "Block")classdata.overallDescription.push_back(value);
            else if(startelement == "Sample")classdata.sampleUsage.push_back(value);



        }
    }
};



void readXML(const string& path, DHBW::filedata& tofill)
{
    const char *charpath = path.c_str();
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cerr << "Error during initialization! :\n"
             << message << "\n";
        XMLString::release(&message);
    }

    SAXParser* parser = {nullptr};
    parser = new SAXParser;


    int errorCount = {0};
    try
    {
        //Das eigentliche Parsen der Datei
        SimpleSAXParser handler;
        parser->setDocumentHandler(&handler);
        parser->parse(charpath);
        errorCount = parser->getErrorCount();
        tofill = handler.getClassdata();

    }
    catch (const OutOfMemoryException&)
    {
        XERCES_STD_QUALIFIER cerr << "OutOfMemoryException" << XERCES_STD_QUALIFIER endl;
    }
    catch (const XMLException& toCatch)
    {
        char* message = XMLString::transcode(toCatch.getMessage());
        cerr << "XMLException: " << message << endl;
    }
    catch(...) {
        cerr << "Unbekannter Fehler" << endl;
    }

    //Parser sauber beenden
    delete parser;
    //Terminate muss immer am Schluss stehen
    XMLPlatformUtils::Terminate();
}