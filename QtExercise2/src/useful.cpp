#include "useful.h"

useful::~useful()
{

}

void useful::hello(QString helloText)
{
    emit usefulSignal(helloText);
}
