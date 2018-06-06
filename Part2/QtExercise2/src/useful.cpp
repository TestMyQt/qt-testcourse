#include "useful.h"

useful::~useful()
{

}

void useful::hello(QString helloText)
{
    // BEGIN SOLUTION
    emit usefulSignal(helloText);
    // END SOLUTION
    // Write emit code here
}
