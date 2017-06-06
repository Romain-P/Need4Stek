/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Tue Jun  6 21:25:34 2017 romain pillot
*/

#include "ai.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void	turn_right(float angle, float speed)
{
  send_message(MESSAGE_WHEELS_DIR, -1, -angle);
  send_message(MESSAGE_FORWARD, -1, speed);
}

static void	turn_left(float angle, float speed)
{
  send_message(MESSAGE_WHEELS_DIR, -1, angle);
  send_message(MESSAGE_FORWARD, -1, speed);
}

static void	forward(float speed)
{
  send_message(MESSAGE_WHEELS_DIR, -1, 0);
  send_message(MESSAGE_FORWARD, -1, speed);
}

static void	apply_ai(float rays[32])
{
  float		warning;

  warning = rays[15] < 200 || rays[31] < 200 || rays[0] < 200 ? 0.4 : 0;
  if (rays[15] <= 80)
    return (send_message(MESSAGE_BACKWARD, -1, 1));
  if (rays[15] > 1200 && rays[0] > 150 && rays[31] > 150)
    return (forward(1));
  else if (rays[0] < 250 && rays[31] >= 250)
    return (turn_right(0.2 + warning, 0.5 - warning));
  else if (rays[31] < 250 && rays[0] >= 250)
    return (turn_left(0.2 + warning, 0.5 - warning));
  send_message(MESSAGE_WHEELS_DIR, -1, rays[0] >= rays[31] ?
	       rays[31] < 200 ? 0.7 : 0.2 :
	       rays[0] < 200 ? -0.7 : -0.2);
  send_message(MESSAGE_FORWARD, -1, 0.5 - warning);
}

int	main()
{
  float	rays[32];

  setbuf(stdout, NULL);
  send_message(MESSAGE_START, -1, -1);
  while (true)
    {
      get_float_array(MESSAGE_INFO_LIDAR, -1, -1, rays);
      apply_ai(rays);
    }
  return (EXIT_SUCCESS);
}
