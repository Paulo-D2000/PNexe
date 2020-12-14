#include <iostream>
#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include "../external/stb_image.h"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "PNexe Decoder: ";
        std::cout << "No files! Usage: encoded.png or drop the image\nAdicione um arquivo! Uso: encoded.png ou arraste a imagem\n";
        return -1;
    }

    int CHANNEL_NUM;
    int width;
    int height;

    uint8_t* pix = stbi_load(argv[1], &width, &height, &CHANNEL_NUM, 3);
    std::ofstream outfile("out.exe", std::ofstream::binary);
    int size = width * height * CHANNEL_NUM;
    char* buffer = new char[size];

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; ++i)
        {
           int index = i + j * width;
           index *= 3;
           buffer[index + 0] = pix[index + 0];
           buffer[index + 1] = pix[index + 1];
           buffer[index + 2] = pix[index + 2];
        }
    }

    outfile.write(buffer, size);

    std::cout << "\nDone! Output file: out.exe\nFinalizado! Resultado: out.exe\n";

    delete[] buffer;
    stbi_image_free(pix);
    outfile.close();
    return 0;
}
