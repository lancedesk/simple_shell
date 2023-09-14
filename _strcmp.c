#include "lance.h"

/**
 * _strcmp - Compare two strings lexicographically.
 *
 * This function compares the two input strings,
 * `strn1` and `strn2`,
 * character by character, until a mismatch
 * is found or one of the strings
 * reaches its null terminator.
 * It returns an integer less than, equal to,
 * or greater than zero, depending on whether
 * `strn1` is found to be
 * lexicographically less than, equal to,
 * or greater than `strn2`.
 *
 * @strn1: The first string to compare.
 * @strn2: The second string to compare.
 *
 * Return: An integer less than, equal to,
 * or greater than zero,
 * depending on the comparison result.
*/

int _strcmp(const char *strn1, const char *strn2)
{
  int result, strn1_result, strn2_result;
  
  while (*strn1 && (*strn1 == *strn2))
  {
    strn1++;
    strn2++;
  }

  strn1_result = *(unsigned char *)strn1;
  strn2_result = *(unsigned char *)strn2;

  result =  strn1_result - strn2_result;
  return (result);
}