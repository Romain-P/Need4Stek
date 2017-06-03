/*
** str_length.c for  in /home/romain.pillot/projects/ghoulc/src/str
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 03:27:08 2017 romain pillot
** Last update Sun May 28 03:28:16 2017 romain pillot
*/

#include "util.h"

int     str_length(const char *str)
{
  int	i;

  i = 0;
  while (str && str[i] && ++i);
  return (i);
}
