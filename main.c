#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */

/*int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}*/
/*#include "main.h"*/
int check_path(char *path, char **pathArray, char **tokenArray);
int main(int argc, char **argv)
{
        char *input = NULL, *path = NULL;
        size_t size = 0;
        char *tokenArray[20], *pathArray[20];
        int ret_value = 0, i;
        (void)argc;
        (void)argv;
        while (1)
        {
                i = 0;
                while (environ[i] != NULL)
                {
                        if (strncmp(environ[i], "PATH=", 5) == 0)
                        {
                                path = strdup((environ[i] + 5));
                                break;
                        }
                        i++;
                }
                tokenize_string(path, ":", pathArray);
                if (isatty(STDIN_FILENO))
                        write(STDOUT_FILENO, "Shell $ ", 8);
                if (getline(&input, &size, stdin) == -1)
                {
                        free(input);
                        free(path);
                        exit(EXIT_SUCCESS);
                }
                tokenize_string(input, " \n\t", tokenArray);
                if (!tokenArray[0])
                {
                        free(path);
                        continue;
                }
                if (strcmp(tokenArray[0], "exit") == 0)
                {
                        free(input);
                        free(path);
                        exit(EXIT_SUCCESS);
                }
                if (access(tokenArray[0], X_OK) == 0)
                        execute(path, tokenArray[0], tokenArray);
                else
                        ret_value = check_path(path, pathArray, tokenArray);
        }
        return (ret_value);
}
