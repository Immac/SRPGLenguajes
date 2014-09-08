#ifndef LOADER_H
#define LOADER_H
#include "tinyxml2.h"
#include "Elements/board.h"

class Loader
{
private:

    typedef shared_ptr<Job> JobPtr;
public:
    Loader();
    static JobPtr JobPtrFromFile(string jobName);
};

#endif // LOADER_H
