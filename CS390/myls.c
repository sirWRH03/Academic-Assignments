#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>

int main (int argc, char *argv[])
{
    bool listAll = false;
    char *strPath = ".";
    DIR *dirName;
    struct dirent *entry;

    if ( argc > 1 && strcmp(argv[1], "-a") == 0)
    {
        if (argc > 2)
        {
            strPath = argv[2];
        }
    }
    else if (argc > 1)
    {
        strPath = argv[1];
    }

    if ((dirName = opendir(strPath)) != NULL)
    {
        while ((entry = readdir(dirName)) != NULL)
        {
            if (!listAll && entry->d_name[0] == '.')
            {
                continue;
            }
            printf("%s\n", entry->d_name);
        }
        closedir(dirName);
    }
    else
    {
        printf("Directory could not be displayed.\n");
    }

    return 0;
}