/*
** str_reduce.c for  in /home/romain.pillot/projects/ghoulc/src/str
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu May 25 09:31:45 2017 romain pillot
** Last update Thu May 25 09:32:17 2017 romain pillot
*/

char    *str_reduce(char *str, const char c)
{
  int   i;
  int   j;

  i = (j = 0);
  while (str && str[i])
    {
      if (c ? str[i] != c : str[i] != ' ' && str[i] != '\t')
	{
	  if (i && j && (c ? str[i - 1] == c :
			 str[i - 1] == ' ' || str [i - 1] == '\t'))
	    str[j++] = c ? c : ' ';
	  str[j++] = str[i++];
	}
      else
	i++;
    }
  if (str)
    str[j] = 0;
  return (str);
}
