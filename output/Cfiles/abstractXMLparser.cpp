std::string generateHelpstr(const DHBW::filedata &xmldata) {
    string hilfetext;
    hilfetext += "Overall Description:\\n\"\n";
    for (int i = 0; i < xmldata.overallDescription.size(); ++i) {
        hilfetext += "\"" + data(xmldata.overallDescription)[i];
        hilfetext += "\\n\"\n";
    }
    hilfetext += "\n\"Sample Usage:\\n\"\n";

    for (int i = 0; i < xmldata.sampleUsage.size(); ++i) {
        hilfetext += "\"" + data(xmldata.sampleUsage)[i];
        hilfetext += "\\n\"\n";
    }
    hilfetext += "\n\"Options:\\n\"\n";

    for (int i = 0; i < xmldata.optarr.size(); ++i) {
        DHBW::opt optx = data(xmldata.optarr)[i];
        hilfetext += "\" ShortOpt: ";
        to_string(optx.shortOpt).empty() ? hilfetext += "Keine ShortOpt " : hilfetext += optx.shortOpt;
        hilfetext += " LongOpt: ";
        hilfetext += optx.longOpt.empty() ? "Keine LongOpt " : optx.longOpt;
        hilfetext += " Description: " + optx.description + "\\n\"\n";
    }
    hilfetext += " \n\"Kontaktdaten:\\n\"\n\"Autoren: " + xmldata.author + " Email: " + xmldata.email;
    return hilfetext;
}