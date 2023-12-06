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
int main(int ac, char **av)
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

    // Redirect stdout to a file descriptor (e.g., a pipe)
    int saved_stdout = dup(STDOUT_FILENO);
    int stdout_pipe[2];
    pipe(stdout_pipe);
    dup2(stdout_pipe[1], STDOUT_FILENO);
    close(stdout_pipe[1]);

    populate_env_list(info);
    read_history(info);
    hsh(info, av);

    // Restore original stdout
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    // Print the contents of stdout_pipe[0]
    char buffer[4096];
    ssize_t bytesRead;
    while ((bytesRead = read(stdout_pipe[0], buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    return (EXIT_SUCCESS);
}