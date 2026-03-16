#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mp3.h"
void convert(char *b)
{
    int temp = b[0];
    b[0] = b[3];
    b[3] = temp;
    temp = b[1];
    b[1] = b[2];
    b[2] = temp;
}

const char* tag_name(const char *tag)
{
    if (strcmp(tag, "TIT2") == 0)
    {
       return "Title";
    }
    if (strcmp(tag, "TPE1") == 0)
    {
       return "Artist";
    }
    if (strcmp(tag, "TALB") == 0) 
    {
        return "Album";
    }
    if (strcmp(tag, "TYER") == 0)
    {
        return "Year";
    }
    if (strcmp(tag, "TCON") == 0) 
    { 
        return "Genre";
    }
    if (strcmp(tag, "COMM") == 0) 
    {
    return "Comments";
    }
    return tag; 
}

void view(char *filename)
{
    FILE *fptr = fopen(filename, "rb");
    if (!fptr)
    {
        printf("Error: cannot open file %s\n", filename);
        return;
    }

    
    fseek(fptr, 10, SEEK_SET);

    printf("\n----- MP3 TAG VIEWER -----\n");
    printf("File : %s\n", filename);
    printf("--------------------------\n");
  while (!feof(fptr))
    {
        char tag[5];
        
        if (fread(tag, 1, 4, fptr) != 4)
            break;  
        
        tag[4] = '\0';

       
        if (tag[0] == '\0') 
            break;  
        int size;
        if (fread(&size, 1, 4, fptr) != 4)
            break;  
        
        convert((char *)&size);
        char flags[2];
    fread(flags, 1, 2, fptr);

   
    if (strcmp(tag, "TIT2") == 0 ||strcmp(tag, "TPE1") == 0 ||strcmp(tag, "TALB") == 0 ||strcmp(tag, "TYER") == 0 ||strcmp(tag, "TCON") == 0 ||strcmp(tag, "COMM") == 0)
    {
        char content[size + 1];
        fread(content, 1, size, fptr);
        content[size] = '\0';

        
        printf("%s: %s\n", tag_name(tag), content + 1);
    }
    else
     {
       
        fseek(fptr, size, SEEK_CUR);
    }
}
}
