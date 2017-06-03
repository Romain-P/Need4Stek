/*
** sender.c for  in /home/romain.pillot/projects/n4s/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Jun  3 20:26:15 2017 romain pillot
** Last update Sat Jun  3 23:24:49 2017 romain pillot
*/

#include "ai.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

static char	**get_data(const int answer_len)
{
  char		*str;
  char		**split;
  int		len;

  if (!(str = scan_line(0)))
    return (NULL);
  split = str_split(str, ':');
  len = 0;
  while (split && split[len] && ++len);
  if (len != 4 + answer_len)
    {
      FREE(split);
      return (NULL);
    }
  return (split);
}

static void	send_message_private(const t_message *msg,
				     const int param_int,
				     const float param_float)
{
  if (msg->param_type == NONE)
    printf("%s\n", msg->data);
  else if (msg->param_type == FLOAT_PARAM)
    printf("%s:%f\n", msg->data, param_float);
  else if (msg->param_type == INTEGER_PARAM)
    printf("%s:%d\n", msg->data, param_int);
}

void	send_message(const t_message *msg,
		     const int param_int,
		     const float param_float)
{
  char	**split;

  send_message_private(msg, param_int, param_float);
  split = get_data(0);
  if (str_equals(split[1], COMMAND_FAILURE))
    printf("error: %s\n", split[2]);
  TAB_FREE(split);
}

float	get_float(const t_message *msg,
		  const int param_int,
		  const float param_float)
{
  char	**split;
  float	value;

  if (msg->answer_type != FLOAT)
    {
      printf("sender: %s\n", "invalid answer type");
      return (0.0);
    }
  send_message_private(msg, param_int, param_float);
  if (!(split = get_data(1)) || str_equals(split[1], COMMAND_FAILURE))
    printf("error: %s\n", split ? split[2] : "internal");
  else
    value = atof(split[3]);
  TAB_FREE(split);
  return (value);
}

void	get_float_array(const t_message *msg,
			const int param_int,
			const float param_float,
			float array[32])
{
  char	**split;
  int	i;

  if (msg->answer_type != FLOAT_ARRAY)
    {
      printf("sender: %s\n", "invalid answer type");
      return ;
    }
  send_message_private(msg, param_int, param_float);
  if (!(split = get_data(32)) || str_equals(split[1], COMMAND_FAILURE))
    printf("error: %s\n", split ? split[2] : "internal");
  else
    {
      i = -1;
      while (++i < ARRAY_SIZE && split[i + 3])
	array[i] = atof(split[i + 3]);
    }
  TAB_FREE(split);
}
