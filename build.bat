cd src
g++ -c AudioEngine.cpp Audio.cpp Shader.cpp Sprite.cpp Texture.cpp Window.cpp -I../include -I../include/glad -I../include/stbImage -I../include/miniAudio -I../include/glm

cd ..

ar rcs lib/multimedia.lib src/*.o
del src\*.o