#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <pthread.h>
# include "libft.h"

# define MAX_LIFE 5
# define EAT_T 1
# define THINK_T 1
# define REST_T 1
# define TIMEOUT 60 * 60 * 24
# define DAMAGE_PER_S 1
# define WIN_NAME "PHILO"
# define NBR_TEXTURES 15

/*
** Position baguette
*/

# define POS_BAGUETTE_NOR 0
# define POS_BAGUETTE_RIGHT 7
# define POS_BAGUETTE_LEFT 14

# define BAGUETTE_DISPO 1
# define BAGUETTE_INDISPO 0
# define ALIVE 1
# define DEAD 0

# define FONT_START "angelina.ttf"
# define FONT "BebasNeue.ttf"

typedef enum	e_state_philo
{
	STATE_PHILO_REST,
	STATE_PHILO_THINK,
	STATE_PHILO_EAT
}				t_state_philo;

/*
** E_INIT ini error
*/

typedef enum	e_err
{
	NONE = 0,
	E_INIT,
	E_WINDOW,
	E_SURFACE,
	E_RENDERER,
	E_TEXTURE,
	E_COPY_RENDERER,
	E_CLEAR_RENDERER,
	E_TTF_INIT,
	E_TTF_OPEN,
	E_TTF_SIZE,
	E_TTF_SURF,
	E_THREAD_CREATE,
	E_THREAD_JOIN,
}				t_err;

/*
** we can only use
** pthread_create.
** pthread_detach.
** pthread_join.
** pthread_mutex_init.
** pthread_mutex_destroy.
** pthread_mutex_trylock.
** pthread_mutex_lock.
** pthread_mutex_unlock.
*/

typedef struct	s_pos
{
	SDL_Rect	rect_d;
	SDL_Point	*center;
	double		angle;
}				t_pos;

typedef struct	s_texture
{
	SDL_Texture			*tex;
	SDL_Rect			rect_s;
	unsigned int		pos;
}				t_texture;

typedef struct	s_info_philo
{
	SDL_Texture			*tex;
	SDL_Rect			rect_s;
	SDL_Rect			rect_d;
	SDL_Color			sdl_color;
}				t_info_philo;

typedef struct	s_baguette
{
	int					pos;
	int					state;
	pthread_mutex_t		mutex_baguette;
}				t_baguette;

typedef struct	s_philosophers
{
	int						hp;
	int						state;
	int						timeout;
	char					name[124];
	pthread_t				thread;
	t_baguette				baguette;
	struct s_philosophers	*right;
	struct s_philosophers	*left;
}				t_philosphers;

/*
** typedef struct s_sdl t_sdl
** manage SDL
*/

typedef struct	s_system
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		ev;
	TTF_Font		*font;
	TTF_Font		*font_start;
}				t_system;

typedef struct	s_window
{
	int			width;
	int			height;
}				t_window;

/*
** typedef struct s_env t_env;
** Contain all pointer to another structs
*/

typedef struct	s_env
{
	t_system		sys;
	t_window		win;
	t_pos			pos[29];
	t_texture		texture[NBR_TEXTURES];
	t_philosphers	philosophers[7];
	t_info_philo	text[7];
	t_info_philo	start[2];
	int				state;
}				t_env;

/*
********************************************************************************
**									INIT
********************************************************************************
*/
/*
** initSDL pointer
*/
void			philo_init_system(t_system *sys);
/*
** Create window
*/
t_err			philo_init_env(t_env *e);
/*
** Create Display
*/
t_err			philo_init_display(t_env *env);
t_err			philo_init_rect(t_env *env);
t_err			philo_init_baguette(t_env *env);
t_err			philo_init_start(t_env *env);

void			philo_init_philosophers(t_env *env);
t_err			philo_add_philos(t_env *env);
t_err			philo_init_text_name(t_env *env, int index, char *name,
				SDL_Color textcolor);

t_err			philo_add_baguettes(t_env *env);

t_err			philo_init_text(t_env *env);
void			philo_init_color(t_env *env);

/*
********************************************************************************
**									PHILOSOPHERS
********************************************************************************
*/
t_err			philo_start_routine(t_env *env);
void			philo_take_damage(t_philosphers *philo);
int				philo_is_dead(t_philosphers *philo);
t_err			philo_join_thread(t_philosphers *philo);
int				take_is_own_baguette(t_philosphers *philo);
int				philo_take_right_baguette(t_philosphers *philo);
int				philo_eat(t_philosphers *philo);
/*
********************************************************************************
**									DISPLAY
********************************************************************************
*/
void			philo_display_philosophers(t_env *env);
void			philo_display_baguettes(t_env *env);
void			philo_display_text(t_env *env);
/*
********************************************************************************
**									SYSTEM
********************************************************************************
*/
t_err			philo_main_loop(t_env *env);
void			philo_sdl_exit(t_system *sys);
t_err			philo_error(t_env *env, t_err err);
void			philo_init_pos(t_pos *pos);
void			philo_init_pos_philo(t_pos *pos);
void			philo_init_pos_baguette_right(t_pos *pos);
void			philo_init_pos_baguette_left(t_pos *pos);
void			philo_init_pos_name(t_env *env);
t_err			philo_exit(t_env *env, t_err err);

/*
********************************************************************************
**									DEBUG
********************************************************************************
*/
void			philo_display_philo_console(t_philosphers *philo);

void			philo_space_char(char *dst, int nbr, unsigned int space);
#endif
