#include "lance.h"
#include "helpers.h"

/**
 * _construct_full_path - Constructs a full path by combining
 * two strings with a '/' separator.
 *
 * This function takes two strings as input and constructs a full path
 * by combining them with a forward slash ('/') as a separator.
 *
 * @directory: The directory component of the full path.
 * @file: The file name component of the full path.
 *
 * Return: A dynamically allocated string containing
 * the full path constructed by combining
 * the directory and file, or NULL on memory allocation error.
 */

char *_construct_full_path(const char *directory, const char *file)
{
    char *full_path;
    size_t dir_len, file_len;

    dir_len = _strlen(directory);
    file_len = _strlen(file);

    /* Allocate memory for the full path (directory + "/" + file + '\0') */
    full_path = (char *)malloc(dir_len + file_len + 2);

    if (full_path == NULL)
    {
        perror("malloc");
        return (NULL);
    }

    /* Copy the directory and file to the full path */
    _strcpy(full_path, directory);
    _strcat(full_path, "/");
    _strcat(full_path, file);

    return (full_path);
}

