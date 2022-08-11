#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#pragma once

#include <stdio.h>
#include <string.h>

// exceptions
enum exception_type {
    INCORRECT_USAGE,
    FILE_NOT_FOUND,
    INVALID_FILE_TYPE
};

// public accessible
typedef enum exception_type exception_type;

// exception structure
struct exception {
    char *message;
    exception_type type;
};

// public accessible
typedef struct exception exception;

/**
 * @brief Convert exception type to string
 * 
 * @param var - the variable to apply to
 * @param type - the exception type
 */
void to_string(char *var, exception_type type)
{
    // switch exception type
    switch (type)
    {
        // get messages
        case INCORRECT_USAGE: strcpy(var, "INCORRECT_USAGE_EXCEPTION"); break;
        case FILE_NOT_FOUND: strcpy(var, "FILE_NOT_FOUND_EXCEPTION"); break;
        case INVALID_FILE_TYPE: strcpy(var, "INVALID_FILE_TYPE_EXCEPTION"); break;
    }
}

/**
 * @brief Throw an exception
 * 
 * @param exception - the exception
 */
void _throw(exception *exception)
{
    // get exception type
    char type[100];
    to_string(type, exception->type);

    // throw
    printf("Error: %s\n%s\n", type, exception->message);
}

#endif
