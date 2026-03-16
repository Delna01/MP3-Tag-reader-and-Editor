#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mp3.h"

void edit(char *filename, char *edit_tag, char *new_value)
{
    
    FILE *fptr_old = fopen(filename, "rb");
    if (!fptr_old)
    {
        printf("Error: cannot open file %s\n", filename);
        return;
    }

    
    char filename1[] = "new.mp3";
    FILE *fptr_new = fopen(filename1, "wb");
    if (!fptr_new)
    {
        printf("Error: cannot create temporary file\n");
        fclose(fptr_old);
        return;
    }

    
    char header[10];
    fread(header, 1, 10, fptr_old);
    fwrite(header, 1, 10, fptr_new);

    int tag_edited = 0;

    
    while (!feof(fptr_old))
    {
        char tag[5];
        
       
        if (fread(tag, 1, 4, fptr_old) != 4)
            break;
        
        tag[4] = '\0';

        
        if (tag[0] == '\0')
        {
            fwrite(tag, 1, 4, fptr_new);
            break;
        }

        int size;
        if (fread(&size, 1, 4, fptr_old) != 4)
            break;

        
        int original_size = size;
        convert((char *)&original_size);
        
        char flags[3];
        fread(flags, 1, 2, fptr_old);
        flags[2] = '\0';

        if (strcmp(tag, edit_tag) == 0 && !tag_edited)
        {
            int new_size = strlen(new_value) + 1; 
            int new_size1 = new_size;
            convert((char *)&new_size1);
            
   
            fwrite(tag, 1, 4, fptr_new);
            fwrite(&new_size1, 1, 4, fptr_new);
            
            
            fwrite(flags, 1, 2, fptr_new);
            
            
            char encoding = 0; 
            fwrite(&encoding, 1, 1, fptr_new);
            fwrite(new_value, 1, strlen(new_value), fptr_new);
            
            
            fseek(fptr_old, original_size, SEEK_CUR);
            
            tag_edited = 1;
        }
        else
        {
            
            fwrite(tag, 1, 4, fptr_new);
            fwrite(&size, 1, 4, fptr_new);
            fwrite(flags, 1, 2, fptr_new);
    
            char *data = malloc(original_size);
            if (data)
            {
                fread(data, 1, original_size, fptr_old);
                fwrite(data, 1, original_size, fptr_new);
                free(data);
            }
        }
    }

    
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fptr_old)) > 0)
    {
        fwrite(buffer, 1, bytes_read, fptr_new);
    }

    fclose(fptr_old);
    fclose(fptr_new);

  
    if (tag_edited)
    {
       
        if (remove(filename) != 0)
        {
            printf("Error: cannot delete old file\n");
            return;
        }
        
        
        if (rename(filename1, filename) != 0)
        {
            printf("Error: cannot rename file\n");
            return;
        }
        
        printf("Tag '%s' updated successfully!\n", edit_tag);
    }
    else
    {
        
        remove(filename1);
        printf("Error: Tag '%s' not found!\n", edit_tag);
    }
    

}