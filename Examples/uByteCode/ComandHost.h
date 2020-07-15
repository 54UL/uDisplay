#ifndef COMANDHOST_H
#define COMANDHOST_H
#include <cstdint.h>

#define MAX_COMMANDS 32
#define MAX_NEMONIC_CHARS 4
#define cmword uint8_t 

typedef struct 
{
    const char commandString [MAX_NEMONIC_CHARS];
    cmword (*commandFunction)();
}CommandPair;

static CommandPair*[MAX_COMMANDS] RegisteredInstructions;
void BindCommand(const char* commandName,const CommandPair command):
void TickLoop(cmword command);

#endif