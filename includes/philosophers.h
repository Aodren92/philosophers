#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <SDL2/SDL.h>
# include "libft.h"

# define MAX_LIFE 100
# define EAT_T 3
# define THINK_T 5
# define REST_T 2
# define TIMEOUT 60 * 60 * 24

# define DAMAGE_PER_S 1

# define WIN_NAME "PHILO"


# define NBR_TEXTURES 15
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
}				t_err;


typedef struct	s_texture
{
	SDL_Texture			*tex;
	SDL_Rect			rect_s;
	SDL_Rect			rect_d;


	double				angle;
	SDL_Point			*center;
	SDL_RendererFlip	flip;
}				t_texture;

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
	t_system	sys;
	t_window	win;
	t_texture	texture[NBR_TEXTURES];
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
/*
********************************************************************************
**									SYSTEM
********************************************************************************
*/
t_err	philo_main_loop(t_env *env);
void	philo_sdl_exit(t_system *sys);
void	philo_error(t_env *env, t_err err);
t_err	philo_exit(t_env *env, t_err err);

#endif
