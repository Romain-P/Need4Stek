/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Sat Jun  3 23:18:07 2017 romain pillot
*/

#include "ai.h"
#include <stdlib.h>

static t_message const	messages[] = {
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

int	main(int ac, char **args)
{
  
  return (EXIT_SUCCESS);
}
