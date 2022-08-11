#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#include "exceptions.h"
#include "file.h"
#include "script.h"
#include "includes.h"
#include "interpreter.h"

/**
 * FORMAT:
 * csc <script>
 */

/**
 * @brief Main function
 * 
 * @param argc - argument count
 * @param argv - argument variable
 * @return int 
 */
int main(int argc, char *argv[])
{
    // check argument length
    if (argc != 2)
    {
        // create exception
        exception exception = {
            "Correct Usage: csc [script]",
            INCORRECT_USAGE
        };

        // throw exception
        _throw(&exception);
        exit(0);
    }

    // get script name
    char scriptname[256];
    strcpy(scriptname, argv[1]);

    // check if script exists
    if (!file_exists(scriptname))
    {
        // create exception
        exception exception = {
            "File not found.",
            FILE_NOT_FOUND
        };

        // throw exception
        _throw(&exception);
        exit(0);
    }

    // get script
    script script = { argv[1] };

    // split into tokens
    char *token = strtok(scriptname, ".");

    // get output name
    char output_name[256];
    sprintf(output_name, "%s.c", token);

    // get output
    output output = { output_name };

    // get ending token
    token = strtok(NULL, ".");

    // check for proper usage
    if (is_script(token))
    {
        // create exception
        exception exception = {
            "Inputted file is not a csc file.",
            INVALID_FILE_TYPE
        };

        // throw exception
        _throw(&exception);
        exit(0);
    }

    // interpret
    write_imports(script.name, output.name);
    copy_to_file(script.name, output.name);
    interpret(script.name, output.name);
}