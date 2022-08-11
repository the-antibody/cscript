#include "interpreter.h"

/**
 * @brief Interpret the script
 * 
 * @param scriptname - the script name
 * @param compiledname - the compiled name
 */
void interpret(const char *scriptname, const char *compiledname)
{
    // create command string & script buffer
    char command[256];
    char script[256];
    strcpy(script, scriptname);

    // get cwd
    char cwd[256];
    getcwd(cwd, sizeof(cwd));

    // compile
    sprintf(command, "cd %s && gcc %s -o %s", cwd, compiledname, strtok(script, "."));
    system(command);

    // run
    sprintf(command, "cd %s && ./%s", cwd, strtok(script, "."));
    system(command);

    // delete
    sprintf(command, "cd %s && rm %s && rm %s", cwd, compiledname, strtok(script, "."));
    system(command);
}