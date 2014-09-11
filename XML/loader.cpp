#include "loader.h"

namespace tiny = tinyxml2;
Loader::Loader()
{
}

Loader::JobPtr Loader::jobPtrFromFile(string name)
{
    const string extension(".jox");
    const string folder("Objects/Jobs/");
    const string path = folder + name + extension;
    tiny::XMLDocument xmlDoc;
    auto error = xmlDoc.LoadFile(path.c_str());
    if(error != tiny::XML_NO_ERROR)
    {
        const string notFound = string(kErrorAt) + name;
        JobPtr errorJob(new Job(notFound));
        return errorJob;
    }
    return jobPtrFromNode(xmlDoc.FirstChildElement());
}

Loader::JobPtr Loader::jobPtrFromNode(tinyxml2::XMLElement *root)
{
    JobPtr output;
    if(isNotExpected(root,kJob))
    {
        output.reset(new Job(kUnexpectedRoot) );
        return  output;
    }
    auto currentElement = root->FirstChildElement(kNodeName);
    string jobName = currentElement->GetText();
    set<StatPtr> baseStats,growthStats,jobStats;
    currentElement = root->FirstChildElement(kNodeBaseStats);
    baseStats = statSetFromNode(currentElement);
    currentElement = root->FirstChildElement(kNodeGrowthStats);
    growthStats = statSetFromNode(currentElement);
    currentElement = root->FirstChildElement(kNodeJobStats);
    jobStats = statSetFromNode(currentElement);
    output.reset(new Job(jobName,baseStats,growthStats,jobStats));
    return output;
}

set<Loader::StatPtr> Loader::statSetFromNode(tinyxml2::XMLElement *root)
{
    set<StatPtr> output;
    auto current = root->FirstChildElement(kStat);
    while(current)
    {
        StatPtr newStat = statFromNode(current);
        output.insert(newStat);
        current = current->NextSiblingElement();
    }
    return output;
}

Loader::StatPtr Loader::statFromNode(tinyxml2::XMLElement *root)
{
    auto currentAttr = root->FirstAttribute();
    string id,text;
    int normal,current;
    bool hasCurrent = false;
    while(currentAttr)
    {
        string attrName(currentAttr->Name());
        if(attrName == kAttributeId)
            id = currentAttr->Value();
        else if (attrName == kAttributeText)
            text = currentAttr->Value();
        else if (attrName == kAttributeNormal)
            normal = currentAttr->IntValue();
        else if (attrName == kAttributeCurrent)
        {
            hasCurrent = true;
            current = currentAttr->IntValue();
        }
        currentAttr = currentAttr->Next();
    }
    current = hasCurrent?current:normal;
    StatPtr output(new Stat(id,text,normal,current) );
    return output;
}

Loader::UnitPtr Loader::unitFromFile(string unitId)
{
    const string extension(".unx");
    const string folder("Objects/Units/");
    const string path = folder + unitId + extension;
    tiny::XMLDocument xmlDoc;
    auto error = xmlDoc.LoadFile(path.c_str());
    if(error != tiny::XML_NO_ERROR)
    {
        const string errorAt = string(kErrorAt) + unitId;
        UnitPtr errorUnit(new Unit(errorAt));
        return errorUnit;
    }
    return unitFromNode(xmlDoc.FirstChildElement());
}

string Loader::textFromNode(string nodeName, tinyxml2::XMLElement *root)
{
    auto element = root->FirstChildElement(nodeName.c_str());
    if(element == nullptr)
        return kNodeNotFound;
    string output = element->GetText();
    return output;
}

StatSystem Loader::statSystemFromNode(tinyxml2::XMLElement *root)
{
    string jobName = textFromNode(kNodeBaseJob, root);
    JobPtr baseJob = jobPtrFromFile(jobName);
    jobName = textFromNode(kNodeCurrentJob,root);
    JobPtr currentJob = jobPtrFromFile(jobName);
    auto node = root->FirstChildElement(kNodeUnitStats);
    set<StatPtr> unitStats = statSetFromNode(node);
    node = root->FirstChildElement(kNodeLevels);
    map<JobPtr,int> levelMap = levelUpsFromNode(node);
    StatSystem output
    {
            move(levelMap),
            move(baseJob),
            move(currentJob),
            move(unitStats)
    };
    return output;
}

Loader::UnitPtr Loader::unitFromNode(tinyxml2::XMLElement *root)
{
    UnitPtr output;
    if(isNotExpected(root,kUnit))
    {
        output.reset(new Unit(kUnexpectedRoot));
        return output;
    }
    string id = textFromNode(kNodeId,root);
    auto node = root->FirstChildElement(kNodeStatSystem);
    StatSystem unitStatSystem = statSystemFromNode(node);
    node = root->FirstChildElement(kNodeSkillSet);
    SkillSet unitSkills;
    output.reset(new Unit{id,unitStatSystem,unitSkills} );
    return output;
}

map<Loader::JobPtr, int> Loader::levelUpsFromNode(tinyxml2::XMLElement *root)
{
    auto current = root->FirstChildElement();
    map<JobPtr,int> output;
    while(current)
    {
        pair<JobPtr,int> outputPair;
        auto attribute = current->FirstAttribute();
        while(attribute)
        {
            string attrName(attribute->Name());
            if(attrName == kJob)
                outputPair.first = jobPtrFromFile(attribute->Value());
            if(attrName == kLevels)
                outputPair.second = attribute->IntValue();
            attribute = attribute->Next();
        }
        output.insert(outputPair);
        current = current->NextSiblingElement();
    }
    return output;
}

bool Loader::isNotExpected(tinyxml2::XMLElement *element, string expected)
{
    string rootName = element->Value();
    return rootName != expected;
}
