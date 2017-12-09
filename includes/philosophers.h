#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <SDL2/SDL.h>
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

# define POS_BAGUETTE_NOR 0
# define POS_BAGUETTE_RIGHT 7
# define POS_BAGUETTE_LEFT 14


typedef enum	e_state_philo
{
	STATE_PHILO_REST,
	STATE_PHILO_THINK,
	STATE_PHILO_EAT
}				t_state_philo;

#if 0
# define STATE_REST 0
# define STATE_THINK 1
# define STATE_EAT 2
#endif
# define BAGUETTE_DISPO 1
# define BAGUETTE_INDISPO 0

# define ALIVE 1
# define DEAD 0
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

typedef struct 	s_pos
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

typedef struct s_baguette
{
	int			pos; // 0 normal ; 7  right; 14 left
	int			state;
	int			mutex;
}				t_baguette;


typedef struct s_philosophers
{
	int						hp;
	int						state;
	int						timeout;
	char					name[124];
	pthread_t				thread;
	pthread_mutex_t		 	mutex_hp;
	pthread_mutex_t		 	mutex_b_right;
	pthread_mutex_t		 	mutex_b_left;
	pthread_mutex_t		 	mutex_right;
	pthread_mutex_t		 	mutex_left;
	pthread_mutex_t		 	mutex_state;
	pthread_mutex_t		 	mutex_eat;
	pthread_mutex_t		 	mutex_timeout;
	t_baguette				baguette;
	struct s_philosophers	*right;
	struct s_philosophers 	*left;
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
}				t_env;

/*
********************************************************************************
**									INIT
********************************************************************************
*/
/*
** initSDL pointer
*/
void	philo_init_system(t_system *sys);
/*
** Create window
*/
t_err	philo_init_env(t_env *e);
/*
** Create Display
*/
t_err	philo_init_display(t_env *env);
t_err	philo_init_rect(t_env *env);
t_err	philo_init_baguette(t_env *env);

void	philo_init_philosophers(t_env *env);
t_err	philo_add_philos(t_env *env);

t_err	philo_add_baguettes(t_env *env);

/*
********************************************************************************
**									PHILOSOPHERS
********************************************************************************
*/
t_err	philo_start_routine(t_env *env);
void	philo_take_damage(t_philosphers *philo);
int		philo_is_dead(t_philosphers *philo);
t_err	philo_join_thread(t_philosphers *philo);

int		take_is_own_baguette(t_philosphers *philo);
int		philo_take_right_baguette(t_philosphers *philo);
int		philo_eat(t_philosphers *philo);
/*
********************************************************************************
**									DISPLAY
********************************************************************************
*/
void	philo_display_philosophers(t_env *env);
void	philo_display_baguettes(t_env *env);
/*
********************************************************************************
**									SYSTEM
********************************************************************************
*/
t_err	philo_main_loop(t_env *env);
void	philo_sdl_exit(t_system *sys);
void	philo_error(t_env *env, t_err err);
void	philo_init_pos(t_pos *pos);
t_err	philo_exit(t_env *env, t_err err);

/*
********************************************************************************
**									DEBUG
********************************************************************************
*/
void		philo_display_philo_console(t_philosphers *philo);
#endif
