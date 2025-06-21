#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");
    float factor = atof(argv[3]);

    BYTE header[44];
    fread(header, sizeof(BYTE), 44, input);
    fwrite(header, sizeof(BYTE), 44, output);

    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    fclose(input);
    fclose(output);
}
