#include "libft.h"
#include "philosophers.h"

int		main(int ac, char **av)
{
	(void)ac, (void)av;
	ft_putstr("Hello world!\n");
	//Demarrer SDL 
	SDL_Init( SDL_INIT_EVERYTHING ); 
		 
	//Quitter SDL 
	SDL_Quit(); 
	return (0);
}
