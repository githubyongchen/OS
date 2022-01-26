/*
 * This program provides an example of how to parse arguments using getopt().
 * This program can be integrated into your 2nd programming project about the
 * find utility to parse multiple arguments. Note that this example uses a
 * short option for command-line arguments, e.g. -n instead of -name, -m
 * instead of -mmin, and this is acceptable in your program too.
 * 
 * Compile this code: gcc -o getopt-example getopt-example.c
 * 
 * Sample run: 
 * $./getopt-example -w Document -n foo -a delete 
 * $./getopt-example -w Document -n myfile -a delete 
 * $./getopt-example -w Document -m -10
 */

#include <stdio.h>
#include <unistd.h>

void 
find(char *where, char *name, char *action)
{
	/* Test arguments parsed. */
	printf("find %s %s %s\n", where, name, action);
}

int 
main(int argc, char **argv)
{
	int		w, n, m, i, a;
	char  *where, *name, *mmin, *inum, *action;
	while (1) {
		char		c;

		c = getopt(argc, argv, "w:n:m:i:a:");	/* A colon (‘:’) to
							 * indicate that it
							 * takes a required
							 * argument, e.g, -w
							 * testdir */
		if (c == -1) {
			/* We have finished processing all the arguments. */
			break;
		}
		switch (c) {
		case 'w':
			w = 1;
			where = optarg;
			printf("where: %s\n", optarg);
			break;
		case 'n':
			n = 1;
			name = optarg;
			printf("name: %s\n", optarg);
			break;
		case 'm':
			m = 1;
			mmin = optarg;
			printf("mmin: %s\n", optarg);
			break;
		case 'i':
			i = 1;
			inum = optarg;
			printf("inum: %s\n", optarg);
			break;
		case 'a':
			a = 1;
			action = optarg;
			printf("action: %s\n", optarg);
			break;
		case '?':
		default:
			printf("An invalid option detected.\n");
		}
	}

	/*
	 * Now you can pass the parameters to the find function. For example,
	 * if the action, where, name are all specified, then you can call
	 * find(where, name, action), but this depends on how you implement
	 * the find function.
	 */
	if (a == 1 && w == 1 && n == 1)
		find(where, name, action);

	/* The following codes are optional, but better to study it. */

	/*
	 * Now set the values of "argc" and "argv" to the values after the
	 * options have been processed above.
	 */
	argc -= optind;
	argv += optind;

	/*
	 * Now do something with the remaining command-line arguments, if
	 * necessary.
	 */
	if (argc > 0) {
		printf("There are %d command-line arguments left to process:\n", argc);
		for (i = 0; i < argc; i++) {
			printf("Argument %d: '%s'\n", i + 1, argv[i]);
		}
	}
	return 0;
}

