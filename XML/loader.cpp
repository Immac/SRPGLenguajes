#include "loader.h"

namespace tiny = tinyxml2;
Loader::Loader()
{
}

Loader::JobPtr Loader::loadJob(string name)
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
    return makeJob(xmlDoc.FirstChildElement());
}

Loader::JobPtr Loader::makeJob(tinyxml2::XMLElement *root)
{
    JobPtr output;
    if(isNotExpected(root,kJob))
    {
        output.reset(new Job(kUnexpectedRoot) );
        return  output;
    }
    auto currentElement = root->FirstChildElement(kNodeName);
    string jobName = currentElement->GetText();
    vector<StatPtr> baseStats,growthStats,jobStats;
    currentElement = root->FirstChildElement(kNodeBaseStats);
    baseStats = makeStatSet(currentElement);
    currentElement = root->FirstChildElement(kNodeGrowthStats);
    growthStats = makeStatSet(currentElement);
    currentElement = root->FirstChildElement(kNodeJobStats);
    jobStats = makeStatSet(currentElement);
    output.reset(new Job(jobName,baseStats,growthStats,jobStats));
    return output;
}

vector<Loader::StatPtr> Loader::makeStatSet(tinyxml2::XMLElement *root)
{
    vector<StatPtr> output;
    auto current = root->FirstChildElement(kStat);
    while(current)
    {
        StatPtr newStat = makeStat(current);
        output.push_back(newStat);
        current = current->NextSiblingElement();
    }
    return output;
}

Loader::StatPtr Loader::makeStat(tinyxml2::XMLElement *root)
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

Loader::UnitPtr Loader::loadUnit(string unitId)
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
    return makeUnit(xmlDoc.FirstChildElement());
}

string Loader::getText(string nodeName, tinyxml2::XMLElement *root)
{
    auto element = root->FirstChildElement(nodeName.c_str());
    if(element == nullptr)
        return kNodeNotFound;
    string output = element->GetText();
    return output;
}

StatSystem Loader::makeStatSystem(tinyxml2::XMLElement *root)
{
    string jobName = getText(kNodeBaseJob, root);
    JobPtr baseJob = loadJob(jobName);
    jobName = getText(kNodeCurrentJob,root);
    JobPtr currentJob = loadJob(jobName);
    auto node = root->FirstChildElement(kNodeUnitStats);
    vector<StatPtr> unitStats = makeStatSet(node);
    node = root->FirstChildElement(kNodeLevels);
    map<JobPtr,int> levelMap = makeLevelUps(node);
    StatSystem output
    {
            move(levelMap),
            move(baseJob),
            move(currentJob),
            move(unitStats)
    };
    return output;
}

SkillSet Loader::makeSkillSet(tinyxml2::XMLElement *root)
{

    auto current = root->FirstChildElement();
    auto firstAttr = root->FirstAttribute();
    string attrName = firstAttr->Name();
    string skillSetName = firstAttr->Value();
    SkillSet output(skillSetName);
    if(attrName != kName)
        return output;
    while (current)
    {
        string nodeName = current->Name();
        if(nodeName == kFileAction)
        {
            ActionPtr tempAction = loadAction(current->GetText());
            output.Actions.actions.insert(move(tempAction));
        }
        else if (nodeName == kNodeSkillSet)
        {
            SkillSet tempSkillSet = makeSkillSet(current);
            output.SkillSubset.insert(SkillSetPtr( new SkillSet(tempSkillSet) ));
        }
        current = current->NextSiblingElement();
    }
    return output;
}

Loader::ActionPtr Loader::makeAction(tinyxml2::XMLElement *root)
{
    ActionPtr output;
    auto current = root->FirstChildElement() ;

    if(isNotExpected(root,kNodeAction))
    {
       output.reset(new ActionAttack(kUnexpectedRoot));
       return  output;
    }
    auto attribute = current->FirstAttribute();
    string formula,id;
    while(attribute)
    {
       string attrName = attribute->Name();
       if(attrName == kAttributeId)
            id = attribute->Value();
       else if (attrName == kFormula)
            formula = attribute->Value();
       attribute = attribute->Next();
    }
    current = current->FirstChildElement() ;
    set<string> subjectStats,objectStats,affectedStats;
    while(current)
    {
       string nodeName = current->Name();
       if(nodeName == kNodeSubjectStat)
           subjectStats.insert(current->GetText());
       else if (nodeName == kNodeObjectStat)
           objectStats.insert(current->GetText());
       else if (nodeName == kNodeAffectedStat)
           affectedStats.insert(current->GetText());
        current = current->NextSiblingElement();
    }
    ParticipantStats partakingStats
    {
       move(subjectStats),move(objectStats),move(affectedStats)
    };
    output.reset(new ActionAttack{move(id),
                                      move(partakingStats),
                                      move(formula)});
    return output;
}

Loader::ActionPtr Loader::loadAction(string name)
{
    const string extension(".acx");
    const string folder("Objects/Actions/");
    const string path = folder + name + extension;
    tiny::XMLDocument xmlDoc;
    auto error = xmlDoc.LoadFile(path.c_str());
    if(error != tiny::XML_NO_ERROR)
    {
        const string notFound = string(kErrorAt) + name;
        ActionPtr actionError(new ActionAttack(notFound));
        return actionError;
    }
    return makeAction(xmlDoc.FirstChildElement());
}

set<string> Loader::makeParticipantStat(tinyxml2::XMLElement *root)
{
    set<string> output;
    auto current = root->FirstChildElement();
    while(current)
    {
        string statName = current->GetText();
        output.insert(statName);
        current = current->NextSiblingElement();
    }
    return move(output);
}

Loader::UnitPtr Loader::makeUnit(tinyxml2::XMLElement *root)
{
    UnitPtr output;
    if(isNotExpected(root,kUnit))
    {
        output.reset(new Unit(kUnexpectedRoot));
        return output;
    }
    string id = getText(kNodeId,root);
    auto node = root->FirstChildElement(kNodeStatSystem);
    StatSystem unitStatSystem = makeStatSystem(node);
    node = root->FirstChildElement(kNodeSkillSet);
    SkillSet unitSkills = makeSkillSet(node);
    output.reset(new Unit{id,unitStatSystem,unitSkills} );
    return output;
}

map<Loader::JobPtr, int> Loader::makeLevelUps(tinyxml2::XMLElement *root)
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
                outputPair.first = loadJob(attribute->Value());
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
