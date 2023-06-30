/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-tibaud.le-maout
** File description:
** error_handling
*/
#include "../include/fastatools.h"

static void display_h(void)
{
    printf("USAGE\n");
    printf("      ./FASTAtools option [k]\n\n");
    printf("DESCRIPTION\n");
    printf("      option 1: read FASTA from the standard input, write the");
    printf(" DNA sequence to the\n\t      standard output\n");
    printf("      option 2: read FASTA from the standard input, write the");
    printf(" RNA sequence to the\n\t      standard output\n");
    printf("      option 3: read FASTA from the standard input, write the");
    printf(" reverse complement\n\t      to the standard output\n");
    printf("      option 4: read FASTA from the standard input, write the");
    printf(" k-mer list to the\n\t      standard output\n");
    printf("      option 5: read FASTA from the standard input, write the");
    printf(" coding sequences\n\t      list to the standard output\n");
    printf("      option 6: read FASTA from the standard input, write the");
    printf(" amino acids list to\n\t      the standard output\n");
    printf("      option 7: read FASTA from the standard input containing ");
    printf("exactly 2 sequences,\n\t      align them and write the result");
    printf(" to the standard output\n");
    printf("      k: size of the k-mers for option 4\n");
    exit(0);
}

static void verif_option(char *opt, int argc, char **argv)
{
    if (strlen(opt) > 1)
        exit(84);
    if (opt[0] < 49 || opt[0] > 55)
        exit(84);
    if (opt[0] == 52 && argc != 3)
        exit(84);
    return;
}

static void check_k(char *k)
{
    int i = 0;

    while (k[i]) {
        if (k[i] <= '9' && k[i] >= '0')
            i++;
        else
            exit(84);
    }
    return;
}

int error_handling(global_t *data, int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        display_h();
    verif_option(argv[1], argc, argv);
    if (argc >= 3) {
        check_k(argv[2]);
        data->k = atoi(argv[2]);
    }
    return (0);
}
