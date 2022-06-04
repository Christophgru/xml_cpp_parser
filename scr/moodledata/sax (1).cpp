//g++ -o sax.exe sax.cpp -IC:\UserData\z180338\tools\xerces-c\include -LC:\UserData\z180338\tools\xerces-c\lib -lxerces-c.dll -std=c++20
#include <xercesc/util/XMLString.hpp>
#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
XERCES_CPP_NAMESPACE_USE

#include <locale>
#include <codecvt>
#include <string>
#include <iostream>
using namespace std;

class SimpleSAXParser : public HandlerBase {
public:
    virtual void startDocument() {
        cout << "Dokument beginnt!" << endl;
    }

    virtual void endDocument() {
        cout << "Dokument ist zu Ende!" << endl;
    }

    virtual void startElement(const XMLCh* const name, AttributeList& attributes) {
        cout << "Start-Element: " << converter.to_bytes(name) << endl;

        for (XMLSize_t i = 0; i < attributes.getLength(); ++i)
            cout << converter.to_bytes(attributes.getName(i)) << '=' << converter.to_bytes(attributes.getValue(i)) << endl;
    }

    virtual void endElement(const XMLCh* const name) {
        cout << "Element ist zu Ende: " << converter.to_bytes(name) << endl;
    }

    virtual void characters(const XMLCh* const chars, const XMLSize_t length) {
        cout << "Buchstaben (" << length << "):" << converter.to_bytes(chars, chars + length) << endl;
    }
private:
    wstring_convert<codecvt_utf8_utf16<char16_t>,char16_t> converter;
};

int main(int argc, char* argv[]) {
    try {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cerr << "Error during initialization! :\n"
             << message << "\n";
        XMLString::release(&message);
        return 1;
    }

    SAXParser* parser = {nullptr};
    parser = new SAXParser;

    int errorCount = {0};

    try
    {
        //Das eigendliche Parsen der Datei
        SimpleSAXParser handler;
        parser->setDocumentHandler(&handler);
        parser->parse(argv[1]);
        errorCount = parser->getErrorCount();
    }
    catch (const OutOfMemoryException&)
    {
        XERCES_STD_QUALIFIER cerr << "OutOfMemoryException" << XERCES_STD_QUALIFIER endl;
    }
    catch (const XMLException& toCatch)
    {
        char* message = XMLString::transcode(toCatch.getMessage());

        //XMLString::release(message);
        /*
        XERCES_STD_QUALIFIER cerr << "\nAn error occurred\n  Error: "
                                  << StrX(toCatch.getMessage())
                                  << "\n" << XERCES_STD_QUALIFIER endl;
                                  */
        cerr << "XMLException: " << message << endl;
    }
    catch(...) {
        cerr << "Unbekannter Fehler" << endl;
    }

    cout << "Anzahl Fehler: " << errorCount << endl;

    //Parser sauber beenden
    delete parser;
    //Terminate muss immer am Schluss stehen
    XMLPlatformUtils::Terminate();

    return 0;
}
