#include <iostream>
#include <fstream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../external/stb_image_write.h"


int main(int argc, char* argv[]) {
    std::streampos size;
    char* memblock;

    if (argc != 2) {
        std::cout << "PNexe: ";
        std::cout << "No files! Usage: file.exe or drop the executable\nAdicione um arquivo! Uso: arquivo.exe ou arraste o executável\n";
        return -1;
    }

    std::ifstream file(argv[1], std::ios::in | std::ios::binary | std::ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char[size];
        file.seekg(0, std::ios::beg);
        file.read(memblock, size);
        file.close();

        int CHANNEL_NUM = 3;
        int width = 1 + sqrt(size/ CHANNEL_NUM);
        int height = width;

        uint8_t* pixels = new uint8_t[width * height * CHANNEL_NUM];

        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; ++i)
            {
                int index = i + j * width;
                index *= 3;
                if (index <= size) {
                    pixels[index + 0] = memblock[index+  0];
                    pixels[index + 1] = memblock[index + 1];
                    pixels[index + 2] = memblock[index + 2];
                }
                else {
                    pixels[index + 0] = 255;
                    pixels[index + 1] = 0;
                    pixels[index + 2] = 0;
                }
            }
        }

        stbi_write_png("encoded.png", width, height, CHANNEL_NUM, pixels, width * CHANNEL_NUM);

        std::cout << "\nDone! Output file: encoded.png\nFinalizado! Resultado: encoded.png\n";

        delete[] pixels;
        delete[] memblock;
    }
    else std::cout << "Unable to open file\nNao foi possivel abrir o arquivo";
    return 0;
}
