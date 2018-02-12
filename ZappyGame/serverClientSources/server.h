/*
** server.h for server in /home/lardet_e/zappy
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Wed May  7 15:30:07 2014 lardet
** Last update Sun Jul 20 20:05:34 2014 Fabien Casoni
*/

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<sys/time.h>
#include	<string.h>
#include	<math.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<time.h>

#ifndef _SERVER_H_
# define _SERVER_H_

#define _TRUE_ 0
#define _FALSE_ -1

typedef enum		e_type
  {
    FOOD = 0,
    LINEMATE = 1,
    DERAUMERE = 2,
    SIBUR = 3,
    MENDIANE = 4,
    PHIRAS = 5,
    THYSTANE = 6
  }			type;

typedef enum		e_orient
  {
    N = 1,
    E = 2,
    S = 3,
    O = 4
  }			Orientation;

typedef struct		s_ressources
{
  struct s_ressources	*next;
  unsigned int		x;
  unsigned int		y;
  unsigned int		flag;
  type			type_ress;
}			t_ressources;

typedef struct		s_action
{
  int			id;
  int			ress;
  int			timer;
  int			timer_micro;
  char			msg[412];
}			t_action;

typedef struct		s_player
{
  struct s_player	*next;
  int			fd;
  unsigned int		x;
  unsigned int		y;
  int			inventory[7];
  Orientation		orient;
  t_action		act[10];
  int			i_tim;
  struct timeval	life;
  unsigned int		id;
  unsigned int		level;
}			t_player;

typedef struct		s_egg
{
  struct timeval	life;
  int			x;
  int			y;
  struct timeval	ready;
  int			id;
  struct s_egg		*next;
}			t_egg;

typedef struct		s_team
{
  t_player		*begin;
  t_egg			*egg_list;
  t_player		*player;
  struct s_team		*next;
  unsigned int		nb_client_permitted;
  char			*name;
  int			all_fd[FD_SETSIZE];
  int			all_i;
  int			wait_client[10];
  char			*wait_name[10];
  int			i_wait;
}			t_team;

typedef struct		s_map
{
  unsigned int		x;
  unsigned int		y;
}			t_map;

typedef struct		s_server
{
  t_team		*begin_team;
  t_ressources		*begin_ress;
  t_map			*map;
  t_team		*team;
  t_ressources		*ress;
  int			delay;
  int			lvl_req[7][7];
  struct timeval	save_tv;
  int			listenFd;
  int			t[FD_SETSIZE];
  int			nb_client;
  int			i;
  int			fd_graphic;
  fd_set		readf;
  struct sockaddr_in    svrAdd;
  unsigned int		nb_client_permitted;
}			t_server;

typedef struct		s_communication
{
  char			*list[9];
  int			(*func_ptr[9])(char *, int, t_server *);
}			t_communication;

typedef struct		s_communication2
{
  char			*list[11];
  int			(*func_ptr[11])(char *, int, t_server *);
}			t_communication2;

typedef struct		s_execute
{
  int			id[11];
  int			(*func_ptr[11])(t_player *, t_server *);
}			t_execute;

//strtowordtab
int			my_strlen(char *);
int			count_word(char *);
char			**strtowordtab(char *);

//create
int			create_ress(int, char **, t_server *);
int			create_random_ress(t_server *, type, int, int);
int			create_pos_ress(t_server *, type, int, int);
char			*fill_str(t_player *);
void			manage_food(t_player *, int, int);

//parser
t_server		*pars_arg(int, char **);
int			fill_map(char **, t_server *);
int			fill_name(char **, t_server *);
int			fill_rest(char **, int, t_server *);

//execute_command
void			execute_command(int, t_player *, t_server *);
t_execute		*init_command();
int			eggs_exec(t_player *, t_server *);

//execute_actions_1
int			avance_exec(t_player *, t_server *);
int			left_exec(t_player *, t_server *);
int			right_exec(t_player *, t_server *);
int			see_exec(t_player *, t_server *);
int			inventory_exec(t_player *, t_server *);

//execute_actions_2
int			take_exec(t_player *, t_server *);
int			put_exec(t_player *, t_server *);
int			expulse_exec(t_player *, t_server *);
int			broadcast_exec(t_player *, t_server *);

//func_player
int			func_player(char *, int, t_server *);
t_player		*add_end_player(t_team *, t_server *, int);
t_player		*add_head_player(t_team *, t_server *, int);
int			add_player(t_team *, int *, t_server *, int);
int			player_already_exist(int, t_server *);

//player_actions
int			inventory(char *, int, t_server *);
int			take(char *, int, t_server *);
int			put(char *, int, t_server *);
int			add_in_inventory(unsigned int, t_server *, t_player *);
int			put_down(int, int, t_server *);

//expulse
int			expluse(char *, int, t_server *);
int			broadcast(char *, int, t_server *);
void			loop_player_orient(t_player *, t_player *, int *,
					   t_server *);
int			push_player(t_player *, t_player *);
void			fill_expulse(t_player *, t_server *, int);

//message
int			message_inventory(int, t_server *, t_player *, int);
int			message_out_inventory(int, t_server *, t_player *, int);
int			message_player(int, t_player *, t_server *, t_team *);
int			message_expulse(char *, t_player *, t_server *, t_player *);

//wait_client
int			fd_already_exist(int, t_team *);
int			if_wait_client(char *, int, t_server *, t_team *);
void			reorder_waiting(t_team *);
t_team			*team_exist_with_fd(int, t_server *);

//wait_client2
void			if_wait_client2(t_team *, int);
t_team			*take_team(int, t_server *);
void			add_fd(t_team *, int);

//func_team
int			team_is_ok(char *, t_team *);
int			team_exist(char *, t_server *);
int			add_in_list_team(t_server *, char *);
void			fill_nb_client_team(t_server *);
t_team			*team_check(char *, t_server *);

//others_events
t_communication2	*init_event();
int			others_events(char *, int, t_server *);
int			next_check(int, char *, int, t_server *);
char			**fill_tab();
int			next_check2(t_team *, t_server *, char *, int);

//incant2
int			incantation(char *, int, t_server *);

//manip
t_player		*search_player_by_fd(int, t_server *);
t_player		*search_by_id(int, t_server *);
int			search_by_fd(int, t_server *);
void			advance_with_orientation(t_server*, t_player *);

//movement
int			right(char *, int, t_server *);
int			advance(char *, int, t_server *);
int			left(char *, int, t_server *);
void			change_orientation_left(t_player *);
void			change_orientation_right(t_player *);

//server
int			init(t_server *);
int			print_message(t_server *);
int			init_select(t_server *);
int			init_accept(t_server *);
int			launcher(t_server *);

//erase.c
void			erase_fd(t_server *, int);

//func_server
void			sigint_handler(int);
t_communication		*init_comm();
int			communication(char *, int, t_server *);
int			init_graphic(char *, int, t_server *);

//erase_player
void			free_player(t_player *, t_server *);
void			erase_player(t_player *, t_team *, int *);
int			loop_erase_player(t_player *, t_player *);

//functions2_ptr
int			size_map(char *, int, t_server *);
int			content_case(char *, int, t_server *);
int			content_map(char *, int, t_server *);
int			name_team(char *, int, t_server *);
int			position_player(char *, int, t_server *);

//functions_ptr
int			level_player(char *, int, t_server *);
int			inventory_player(char *, int, t_server *);
int			ask_time_unit(char *, int, t_server *);
int			update_time_unit(char *, int, t_server *);
int			findNumber(char *);

//content_func
int			check_ress(int, int, char *, t_server *);
void			check_player(int, int, char *, t_server *);
int			content_case2(int, int, int, t_server *);
int			count_arg(char **);

//strtowordtab
int			my_strlen(char *);
int			count_word(char *);
char			**strtowordtab(char *);

//content_func2.c
char			**fill_ress_tab();
void			check_ress_cli(int, int, char *, t_server *);
void			check_player_cli(int *, unsigned int, char *,
					 t_server *);
void			check_xy(int *, int *, t_server *);
void			check_coord(int *, t_server *);

//see_func.c
int			see(char *, int, t_server *);
void			see_north(t_player *, char *, t_server *);
void			see_south(t_player *, char *, t_server *);
void			see_east(t_player *, char *, t_server *);
void			see_west(t_player *, char *, t_server *);

//requirement.c
int			set_lvl_requirements(t_server *);
void			set_lvl_requirements2(t_server *);
void			set_lvl_requirements3(t_server *);

//incant.c
int			check_incant_player(t_server *, t_player *, char *);
int			check_incant_ress(t_server *, t_player *);
void			clean_ress(t_server *, t_player *);
void			level_up_players(t_server *, t_player *);
int			lvl_up_exec(t_player *, t_server *);

//life
void			fill_life(t_player *, t_server *);
void			update_life(t_server *);
int			player_die(t_player *, t_server *);
void			update_life_with_add(t_player *, t_server *);
void			update_life_with_put(t_player *, t_server *);

//manage_life
void			manage_life_1(t_player *, int, t_server *,
				    struct timeval);
void			manage_life_2(t_player *, int, t_server *,
				    struct timeval);
void			manage_life_3(t_player *, t_server *);
void			manage_life_4(t_player *, int, t_server *);
void			manage_life_5(t_player *, t_server *);

//manage_life_2
void			manage_life_2_next(t_player *, t_server *,
				      struct timeval, int);

//egg.c
int			find_free_id(t_server *);
int			check_id(t_player *, t_team *, t_server *, int *);
char			*find_team(t_server *, unsigned int);
int			add_eggs(t_server *, int, int);
int			fork_player(char *, int, t_server *);
void			add_new(t_server *, t_egg *, t_egg *, int);

//TIMER

//check_timer
void			check_rest_timer(t_server *, struct timeval);
void			check_timer_player(t_server *, int *, int *);
struct timeval		check_timer(t_server *);
void			fill_timeout(t_player *, int, t_server *, int);

//reorder_timer
void			reorder_array(t_server *);
void			reorder_array_player(t_player *, t_server *);
void			reorder_array_real(t_server *, t_player *, int *);

//timer
void			sub_timer(t_player *, t_server *, struct timeval, int);
void			sub_all_timer(t_server *);
void			sub_check_timer(t_player *, t_server *);
void			sub_all_timer_tv(t_server *, struct timeval);
void			sub_check_timer_tv(t_player *, struct timeval,
					   t_server *);
//broadcast.c
void	       		init_ptr(int (*[9])(int, int, int, int));
int		       	direction_broadcast(int *, int);
int	       		center(int, int, int, int);
int		       	north(int, int, int, int);
int	       		north_west(int, int, int, int);

//broadcast_func.c
int			west(int, int, int, int);
int	       		south_west(int, int, int, int);
int    			south(int, int, int, int);
int    			south_east(int, int, int, int);
int    			east(int, int, int, int);

//broadcast_func2.c
int		       	north_east(int, int, int, int);
void			send_message(t_server *, t_player *);

#endif
