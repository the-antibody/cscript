#pragma once

#ifndef FILE_H
#define FILE_H
#endif

#ifndef is_script
#define is_script(str) (strcmp(str, "csc") != 0)
#endif

#include <stdbool.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

// functions
bool file_exists(const char *filename);
void copy_to_file(const char *scriptname, const char *filename);