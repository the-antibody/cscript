#include "includes.h"

/**
 * @brief Write imports to the compiled script
 * 
 * @param scriptname - script name
 * @param compiledname - compiled script name
 */
void write_imports(const char *scriptname, const char *compiledname)
{
    // open files
    FILE *script = fopen(scriptname, "rb");
    FILE *compiled = fopen(compiledname, "wb");

    // create buffer
    char buffer[256];

    // loop through every line
    while (fgets(buffer, sizeof(buffer), script))
    {
        // get import token
        char *import_token = strtok(buffer, " ");

        // check if is an import
        if (strcmp(import_token, "import") == 0)
        {
            // set import token
            import_token = strtok(NULL, " ");

            // check for new line
            if (import_token[strlen(import_token) - 1] == '\n')
                import_token[strlen(import_token) - 1] = '\0';

            // print to file
            fprintf(compiled, "#include <%s.h>\n", import_token);
        }
    }

    // include standard io
    fprintf(compiled, "#include <stdio.h>\n\n");

    // close files
    fclose(script);
    fclose(compiled);
}