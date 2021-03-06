/*
** util.h for  in /home/romain.pillot/projects/ghoulc/inc
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue May 23 14:02:04 2017 romain pillot
** Last update Tue Jun  6 21:17:14 2017 romain pillot
*/

#ifndef AI_H_
# define AI_H_

# define COMMAND_SUCCESS	("OK")
# define COMMAND_FAILURE	("KO")
# define END			("Lap Cleared")

# define ARRAY_SIZE		(32)

# define MESSAGE_START		(0)
# define MESSAGE_STOP		(1)
# define MESSAGE_FORWARD	(2)
# define MESSAGE_BACKWARD	(3)
# define MESSAGE_WHEELS_DIR	(4)
# define MESSAGE_INFO_LIDAR	(5)
# define MESSAGE_CURRENT_SPEED	(6)
# define MESSAGE_CURRENT_WHEELS	(7)
# define MESSAGE_CYCLE_WAIT	(8)
# define MESSAGE_SPEED_MAX	(9)
# define MESSAGE_SPEED_MIN	(10)
# define MESSAGE_INFO_SIMETIME	(11)

# include <stdbool.h>

typedef enum	s_answer
{
  NO_ANSWER,
  FLOAT_ARRAY,
  FLOAT,
  LONG_LONG
}		t_answer;

typedef enum	s_param
{
  NONE,
  INTEGER_PARAM,
  FLOAT_PARAM
}		t_param;

typedef struct		s_message
{
  const char		(* const data);
  const t_param		param_type;
  const t_answer	answer_type;
}			t_message;

/*
** Return true if track cleared
*/

void	get_float(const int msg_id,
		  const int param_int,
		  const float param_float,
		  float *value);

void	get_float_array(const int msg_id,
			const int _int,
			const float _float,
			float array[42]);

void	send_message(const int msg_id,
		     const int _int,
		     const float _float);

#endif /* !AI_H_ */
