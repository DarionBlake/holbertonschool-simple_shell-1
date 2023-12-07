#include "shell.h"

/**
 * _handle_exit_arg - handles the exit argument
 * @info: Structure containing potential arguments.
 * Return: 1 on error, -2 on success
 */
static int _handle_exit_arg(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return 1;
		}
		info->err_num = exitcheck;
		return -2;
	}

	info->err_num = -1;
	return -2;
}

/**
 * _myexit - closes the shell
 * @info: Structure containing potential arguments.
 * Return: closes with a given exit status (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	return _handle_exit_arg(info);
}

/**
 * _change_directory - changes the current folder of the process
 * @info: Structure containing potential arguments.
 * @new_dir: Directory to change to.
 * Return: 0 on success, 1 on error
 */
static int _change_directory(info_t *info, const char *new_dir)
{
	char buffer[1024];
	int chdir_ret;

	chdir_ret = chdir(new_dir);

	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(new_dir), _eputchar('\n');
		return 1;
	}

	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "PWD", getcwd(buffer, 1024));

	return 0;
}

/**
 * _mycd - changes the current folder of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *dir, *home_dir;

	/* Get the current working directory */
	char *current_dir = getcwd(NULL, 0);
	if (!current_dir)
		_puts("TODO: Handle getcwd failure\n");

	/* If no argument provided, change to the home directory */
	if (!info->argv[1])
	{
		home_dir = _getenv(info, "HOME=");
		dir = home_dir ? home_dir : _getenv(info, "PWD=");
		_change_directory(info, dir ? dir : "/");
	}
	/* If the argument is "-", change to the previous directory (OLDPWD) */
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		dir = _getenv(info, "OLDPWD=");
		if (!dir)
		{
			_puts(current_dir);
			_putchar('\n');
			return 1;
		}

		_puts(dir), _putchar('\n');
		_change_directory(info, dir);
	}
	/* Change to the specified directory */
	else
		_change_directory(info, info->argv[1]);

	free(current_dir);
	return 0;
}

/**
 * _myhelp - displays help information
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	(void)info;
	_puts("help call works. Function not yet implemented\n");
	return 0;
}