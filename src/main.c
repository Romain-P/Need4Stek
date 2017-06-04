/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Sun Jun  4 19:46:44 2017 romain pillot
*/

#include "ai.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void	wrap(bool end, bool *running)
{
  if (end)
    {
      *running = false;
      exit(EXIT_SUCCESS);
    }
}

static bool	apply_ai(float rays[32])
{
  float		middle;
  bool		priority;

  middle = (rays[15] + rays[16]) / 2.0;
  fprintf(stderr, "gauche:%f\ndroite:%f\nmid:%f\n", rays[0], rays[31], middle);
  if (rays[0] < 200)
    send_message(MESSAGE_WHEELS_DIR, -1, 0.2);
  else if (rays[31] < 200)
    send_message(MESSAGE_WHEELS_DIR, -1, -0.2);
  send_message(MESSAGE_FORWARD, -1, 1);
}

int	main()
{
  bool	running;
  float	rays[32];

  running = true;
  setbuf(stdout, NULL);
  send_message(MESSAGE_START, -1, -1);
  while (running &&
	 !get_float_array(MESSAGE_INFO_LIDAR, -1, -1, rays))
    running = !apply_ai(rays);
  send_message(MESSAGE_STOP, -1, -1);
  return (EXIT_SUCCESS);
}
