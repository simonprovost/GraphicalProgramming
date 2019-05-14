/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

void write_help_instruction(void)
{
	my_printf("############# Welcome in Lands Of Valoran #############\n\n"
	"Comment lancez le jeu ? {./my_rpg}\n"
	"Comment lancez le -h ? {./my_rpg -h}\n"
	"Comment connaitre la version du jeu ? {./my_rpg -v}\n"
	"\n\n########################## --help ##########################\n"
	"\n{MAIN_MENU} -->\n{OPTION} : Cette scène vous permettra :\n"
	" - bloquez le son du jeu\n - Changez le FrameRate du jeu\n"
	" - Changez les 'touches' de déplacement\n"
	"Ainsi que bien d'autres options..\n\n"
	"{CREDITS} : Cette scène vous permettra de savoir qui nous sommes..\n"
	"{NEW_GAME} : Cette scène vous permettra de débuté le jeu avec un "
	"personnage que vous aurez choisis.\n"
	"{IN GAME} Référé vous au bouton 'How To Play' dans l'option du jeu."
	);
}

int check_help_programm(char **av)
{
	if (!av)
		return (0);
	if (av[1] && my_strcmp(av[1], "-h") != 0 &&
	my_strcmp(av[1], "-v") != 0)
		return (84);
	else if (av[1] && my_strcmp(av[1], "-h") == 0) {
		write_help_instruction();
		return (1);
	}
	if (av[1] && my_strcmp(av[1], "-v") == 0) {
		my_printf("################### V 1 . 0 ###################\n");
		return (1);
	}
	return (0);
}

int error_handling_args(int ac, char **av, char **env)
{
	int my_errno = 0;

	if (ac > 2 || !env || !env[0])
		return (84);
	if ((my_errno = check_help_programm(av)) != 0)
		return (my_errno);
	return (0);
}
