/**
 * rpmatch -- A simple wrapper around rpmatch(3) libc function
 *
 * Copyright (C) 2014 Denis Ollier
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>
 *
 * To compile this program, run: $CC -o rpmatch rpmatch.c
 *
 * Usage:
 *   rpmatch response
 *   rpmatch option
 *
 * Options
 *   -h, --help     Display this help and exit
 *   -v, --version  Display version information and exit
 */

#define _SVID_SOURCE     /* rpmatch(3) is exposed through the SysV Interface Definition */
#define _DEFAULT_SOURCE  /* _SVID_SOURCE is replaced by _DEFAULT_SOURCE since glibc 2.19 */

#include <getopt.h>   /* getopt_long(3) */
#include <locale.h>   /* setlocale(3)   */
#include <stdio.h>    /* fprintf(3)     */
#include <stdlib.h>   /* exit(3)        */
#include <string.h>   /* strncpy(3)     */

#define RPMATCH_ERROR_USAGE 3

static char response[BUFSIZ];

static void
rpmatch_usage(const char *argv0, FILE *stream)
{
    fprintf(
      stream,
      "Usage:\n"
      "  %s response\n"
      "  %s option\n"
      "\n",
      argv0, argv0
    );

    fputs(
      "Determine if the answer to a question is affirmative or negative.\n"
      "Response parsing is done using rpmatch(3) function.\n"
      "\n"
      "Options:\n"
      "  -h, --help     display this help and exit\n"
      "  -V, --version  display version information and exit\n"
      "\n"
      "Exit status:\n"
      "  - 0 for a recognized positive response (\"yes\")\n"
      "  - 1 for a recognized negative response (\"no\")\n"
      "  - 2 when the value of response is unrecognized\n",
      stream
    );
}

static void
rpmatch_version(void)
{
    fputs("rpmatch 1.0.0-rc1\n", stdout);
}

static void
rpmatch_process_command_line(int argc, char **argv)
{
    int opt = 0;

    #define SHORTOPTS "hV"
    static struct option longopts[] = {
      {"help",    no_argument, NULL, 'h'},
      {"version", no_argument, NULL, 'V'},
      {NULL,      0,           NULL, 0}
    };

    /* Process keyword arguments */
    while ((opt = getopt_long(argc, argv, SHORTOPTS, longopts, NULL)) != EOF)
    {
        switch (opt)
        {
            case 'h':
                rpmatch_usage(argv[0], stdout);
                exit(EXIT_SUCCESS);
                break;
            case 'V':
                rpmatch_version();
                exit(EXIT_SUCCESS);
                break;
            case '?':
                rpmatch_usage(argv[0], stderr);
                exit(RPMATCH_ERROR_USAGE);
                break;
            default :
                break;
        }
    }

    /* Process positional arguments */
    if (optind == argc)
    {
        fputs("You must specify a response to process.\n\n", stderr);
        rpmatch_usage(argv[0], stderr);
        exit(RPMATCH_ERROR_USAGE);
    }
    else
    {
        strncpy(response, argv[optind], BUFSIZ - 1);
        response[BUFSIZ - 1] = '\0';
    }
}

int
main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    /* Parse and check command line options */
    rpmatch_process_command_line(argc, argv);

    /**
     * Return:
     *   - 0 if response is yes
     *   - 1 if response is no
     *   - 2 else
     */
    return 1 - rpmatch(response);
}

/* vi: set ft=c et sw=4 ts=4: */
