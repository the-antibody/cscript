#include "file.h"

/**
 * @brief Check if a file exists
 * 
 * @param filename - the file name
 * @return true 
 * @return false 
 */
bool file_exists(const char *filename)
{
    // get stat
    struct stat buffer;
    return stat(filename, &buffer) == 0;
}

/**
 * @brief Copy lines to the compiled file
 * 
 * @param scriptname - script name
 * @param compiledname - compiled script name
 */
void copy_to_file(const char *scriptname, const char *compiledname)
{
    // open for appending
    FILE *script = fopen(scriptname, "rb");
    FILE *compiled = fopen(compiledname, "a");

    // starter
    fprintf(compiled, "int main(int argc, char *argv[])\n");
    fprintf(compiled, "{\n");

    // print every line into compiled file
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), script))
    {
        // create line buffer
        char line[256];
        strcpy(line, buffer);

        if (strcmp(buffer, "") != 0 && strcmp(buffer, " ") != 0 && strcmp(buffer, "\n") != 0 && strcmp(strtok(buffer, " "), "import") != 0)
            // put line
            fprintf(compiled, "    %s", line);
    }

    // print return and closing bracket
    fprintf(compiled, "\n    return 0;\n");
    fprintf(compiled, "}");

    // close file
    fclose(script);
    fclose(compiled);
}