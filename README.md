# PNexe
C++ Based Steganography & In-Memory Execution of .exe (PE) files hidden as png images!

![Output sample](https://github.com/Paulo-D2000/PNexe/blob/main/Demo/demo.gif)

//EN - US //
*ATENTION! I DON'T RESPONSABILIZE FOR YOUR ACTS, THIS CODE IS ONLY FOR EDUCATIONAL PURPOSES!"


This code will do in memory execution of PE data stored as valid png file.

Dependencies (Used in pre-built demo, already on the bin folder):\
libgcc_s_dw2-1.dll\
libgcc_s_seh-1.dll\
libstdc++-6.dll

Build instructions:\
```git clone https://github.com/Paulo-D2000/PNexe.git --recursive```\
```mkdir build```\
```g++ Encoder/main.cpp -I./external/ -fpermissive -O2 -o build/Encoder```\
```g++ Decoder/main.cpp ./external/RunPE-X86--X64-/RunPE.cpp -I./external/RunPE-X86--X64-/ -I./external/ -fpermissive -O2 -o build/Decoder```\
```g++ Demo/demo_msgbox.cpp -fpermissive -o build/MsgBox```


Encoder.exe -> Usage: file.exe or drop the executable to "Encoder.exe" -> generates the .png\
Decoder.exe -> Usage: encoded.png or drop the image to "Decoder.exe" -> will execute the .png PE data

// Inside Demo/bin folder there are the compiled tools and one simple messagebox executable "MsgBox.exe" for testing //

// PT - BR // 

*ATENÇÃO! NÃO RESPONSABILIZO POR SEUS ATOS, ESTE CÓDIGO É APENAS PARA FINS EDUCACIONAIS! "


Este codigo faz execução na memória de um PE ( arquivo .exe executavel) salvo como uma imagem png válida.

Dependências (Usadas na demo pré-compilada, já estão na pasta bin):\
libgcc_s_dw2-1.dll\
libgcc_s_seh-1.dll\
libstdc++-6.dll

Instruções para compilação:\
```git clone https://github.com/Paulo-D2000/PNexe.git --recursive```\
```mkdir build```\
```g++ Encoder/main.cpp -I./external/stb -fpermissive -O2 -o build/Encoder```\
```g++ Decoder/main.cpp ./external/RunPE-X86--X64-/RunPE.cpp -I./external/RunPE-X86--X64-/ -I./external/stb/ -fpermissive -O2 -o build/Decoder```\
```g++ Demo/demo_msgbox.cpp -fpermissive -o build/MsgBox```

Encoder.exe -> Uso: arquivo.exe ou arraste o executável em cima de "Encoder.exe"\
Decoder.exe -> Uso: encoded.png ou arraste a imagem em cima de "Decoder.exe"

// Dentro da pasta Demo/bin estão presentes as ferramentas compiladas e um gerador de mensagem "MsgBox.exe" para testes //
