/*
 * Copyright (c) 1993 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * Most simple built-in commands are here.
 */

#include "futils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <pwd.h>
#include <grp.h>
#include <utime.h>
#include <errno.h>

int main(int argc, char **argv)
{
	char *cp;
	int gid;
	struct group *grp;
	struct stat statbuf;

	if (argc < 3) goto usage;

	cp = argv[1];
	if (isdecimal(*cp)) {
		gid = 0;
		while (isdecimal(*cp))
			gid = gid * 10 + (*cp++ - '0');

		if (*cp) {
			fprintf(stderr, "Bad gid value\n");
			goto usage;
		}
	} else {
		grp = getgrnam(cp);
		if (grp == NULL) {
			fprintf(stderr, "Unknown group name\n");
			goto usage;
		}

		gid = grp->gr_gid;
	}

	argc--;
	argv++;

	while (argc-- > 1) {
		argv++;
		if ((stat(*argv, &statbuf) < 0) ||
			(chown(*argv, statbuf.st_uid, gid) < 0))
				perror(*argv);
	}
	exit(0);

usage:
	fprintf(stderr, "usage: %s group_name file1 [file2] ...\n", argv[0]);
	exit(1);
}
