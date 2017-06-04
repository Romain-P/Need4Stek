/*
** sender.c for  in /home/romain.pillot/projects/n4s/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sat Jun  3 20:26:15 2017 romain pillot
** Last update Sun Jun  4 18:29:02 2017 romain pillot
*/

#include "ai.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

static t_message const  messages[] = {
  {"START_SIMULATION", NONE, NO_ANSWER},
  {"STOP_SIMULATION", NONE, NO_ANSWER},
  {"CAR_FORWARD", FLOAT_PARAM, NO_ANSWER},
  {"CAR_BACKWARD", FLOAT_PARAM, NO_ANSWER},
  {"WHEELS_DIR", FLOAT_PARAM, NO_ANSWER},
  {"GET_INFO_LIDAR", NONE, FLOAT_ARRAY},
  {"GET_CURRENT_SPEED", NONE, FLOAT},
  {"GET_CURRENT_WHEELS", NONE, FLOAT},
  {"CYCLE_WAIT", INTEGER_PARAM, NO_ANSWER},
  {"GET_CAR_SPEED_MAX", NONE, FLOAT},
  {"GET_CAR_SPEED_MIN", NONE, FLOAT},
  {"GET_INFO_SIMTIME", NONE, LONG_LONG}
};

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

bool	send_message(const int msg_id,
		     const int param_int,
		     const float param_float)
{
  char	**split;
  bool	end;

  send_message_private(&(messages[msg_id]), param_int, param_float);
  split = get_data(0);
  if (!split || str_equals(split[1], COMMAND_FAILURE))
    fprintf(stderr, "error: %s\n", split ? split[2] : "internal");
  if (split)
    fprintf(stderr, "received: %s\n", split[2]);
  end = split ? str_equals(split[tab_length(split) - 1], END) : false;
  TAB_FREE(split);
  return (end);
}

bool			get_float(const int msg_id,
				  const int param_int,
				  const float param_float,
				  float *value)
{
  char			**split;
  const t_message	*msg;
  bool			end;

  msg = &(messages[msg_id]);
  if (msg->answer_type != FLOAT)
    {
      fprintf(stderr, "sender: %s\n", "invalid answer type");
      return (false);
    }
  send_message_private(msg, param_int, param_float);
  if (!(split = get_data(1)) || str_equals(split[1], COMMAND_FAILURE))
    fprintf(stderr, "error: %s\n", split ? split[2] : "internal");
  else
    *value = atof(split[3]);
  end = split ? str_equals(split[tab_length(split) - 1], END) : false;
  TAB_FREE(split);
  return (end);
}

bool			get_float_array(const int msg_id,
					const int param_int,
					const float param_float,
					float array[32])
{
  char			**split;
  int			i;
  const t_message	*msg;
  bool			end;

  msg = &(messages[msg_id]);
  if (msg->answer_type != FLOAT_ARRAY)
    {
      fprintf(stderr, "sender: %s\n", "invalid answer type");
      return (false);
    }
  send_message_private(msg, param_int, param_float);
  if (!(split = get_data(32)) || str_equals(split[1], COMMAND_FAILURE))
    fprintf(stderr, "error: %s\n", split ? split[2] : "internal");
  else
    {
      i = -1;
      while (++i < ARRAY_SIZE && split[i + 3])
	array[i] = atof(split[i + 3]);
    }
  end = split ? str_equals(split[tab_length(split) - 1], END) : false;
  TAB_FREE(split);
  return (end);
}
