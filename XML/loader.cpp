#include "loader.h"
namespace tiny = tinyxml2;
Loader::Loader()
{
}

Loader::JobPtr Loader::JobPtrFromFile(string jobName)
{
    const string extension = ".jox";
    const string folder = "Objects/Jobs/";
    const string path = folder + jobName + extension;
    tiny::XMLDocument XmlDoc;
    auto error = XmlDoc.LoadFile(path.c_str());
    if(error != tiny::XML_NO_ERROR)
    {
        JobPtr errorJob(new Job());
        return errorJob;
    }


}
