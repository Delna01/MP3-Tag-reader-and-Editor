#include <stdio.h>
#include <string.h>
#include "mp3.h"

void print_help()
{
    printf("Usage:\n");
    printf("./a.out -v <file.mp3> -> View tags\n");
    printf("./a.out -e <file.mp3> -t/-a/-A/-y/-g/-c new -> Edit tag\n\n");
    printf("Options:\n");
    printf("-t -> Title\n");
    printf("-a -> Artist\n");
    printf("-A -> Album\n");
    printf("-y -> Year\n");
    printf("-g -> Genre\n");
    printf("-c -> Comments\n");
    printf("-h -> Help\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        print_help();
        return 1;
    }


    if (!strcmp(argv[1], "-h"))
    {
        print_help();
        return 0;
    }

    if (!strcmp(argv[1], "-v"))
    {
        if (argc < 3 || strstr(argv[2], ".mp3") == NULL)
        {
            printf("Error: Provide .mp3 file\n");
            return 1;
        }

        view(argv[2]);
        return 0;
    }

    if (!strcmp(argv[1], "-e"))
    {
        if (argc < 5 || strstr(argv[2], ".mp3") == NULL)
        {
            printf("Error: Usage -> ./a.out -e <file.mp3> -t/-a/-A/-y/-g/-c new -> Edit tag\n");
            return 1;
        }

        char file[100], tag[5];
        strcpy(file, argv[2]);

        if (!strcmp(argv[3], "-t")) strcpy(tag, "TIT2");
        else if (!strcmp(argv[3], "-a")) strcpy(tag, "TPE1");
        else if (!strcmp(argv[3], "-A")) strcpy(tag, "TALB");
        else if (!strcmp(argv[3], "-y")) strcpy(tag, "TYER");
        else if (!strcmp(argv[3], "-g")) strcpy(tag, "TCON");
        else if (!strcmp(argv[3], "-c")) strcpy(tag, "COMM");
        else
        {
            printf("Error: Invalid tag option\n");
            return 1;
        }

        edit(file, tag, argv[4]);
        printf("Tag updated successfully!\n");

        return 0;
    }

    printf("Invalid option! Try -h for help.\n");
    return 1;
}

