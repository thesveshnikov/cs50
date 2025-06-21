#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    BYTE buffer[512];
    int count = 0;
    FILE *img = NULL;

    while (fread(buffer, sizeof(BYTE), 512, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL) fclose(img);
            char filename[8];
            sprintf(filename, "%03i.jpg", count++);
            img = fopen(filename, "wb");
        }
        if (img != NULL) fwrite(buffer, sizeof(BYTE), 512, img);
    }

    fclose(file);
    if (img != NULL) fclose(img);
    return 0;
}
