

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>


int			global; // In BSS (Block started by Symbol) Segment, automatically initialized to 0
extern char	**environ;

void	cleanup(void)
{
	printf("Call on exit: cleanup()\n");
}

int		main(int ac, char **av)
{
	pid_t	child_pid;
	int		status;
	int		local = 0;

	// create new process
	child_pid = fork();

	if (child_pid >= 0) // fork succeeded
	{
		if (child_pid == 0)
		{
			printf("Child Process!\n");
			atexit(cleanup);
			local++; // Increment local and global variables in child processes memory region
			global++; // Wont affect parents memory, proves that fork copies the parent processes text, static data and stack memory

			printf("Child PID = %d, Parent PID = %d\n", getpid(), getppid());
			printf("Childs local = %d, Childs global = %d\n", local, global);

			int	count = 0;

			printf("\n");
			while (environ[count] != NULL)
			{
				printf("Child Process :: [%s] \n ", environ[count]);
				count++;
			}
			char *cmd[] = {"whoami", (char*)0};
			return execv("/usr/bin/", cmd); // call whoami command (a builtin)
		}
		else // parent process
		{
			atexit(cleanup);
			printf("Parent Process!\n");
			printf("Parent PID = %d , Child PID = %d\n", getpid(), child_pid);
			wait(&status); // wait for child to exit and store childs exit status
			printf("Childs exit code: %d\n", WEXITSTATUS(status));

			printf("\n Parents local = %d, Parents global = %d\n", local, global);

			printf("Parent bye!\n");
			exit(0);
		}
	}
/*

	int	count = 0;

	printf("\n");
	while (environ[count] != NULL)
	{
		printf("Child Process :: [%s] \n ", environ[count]);
		count++;
	}

	char *val = getenv("USER");
	printf("\n\nCurrent value of environment variable USER is [%s]\n",  val);

	if (setenv("USER", "Felix", 1))
	{
		printf("Addes new value to existing environment variables\n");
		return (1);
	}

	printf("Succesfully added a new value");

	val = getenv("USER");
	printf("here it is %s\n", val);

	exit(0);

	return (0);

	*/
	}
