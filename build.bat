cd src
g++ -c Audio.cpp AudioEngine.cpp Shader.cpp Sprite.cpp Texture.cpp Keyboard.cpp Mouse.cpp Window.cpp Clock.cpp Cursor.cpp Event.cpp -I../include -I../include/glad -I../include/stbImage -I../include/miniAudio -I../include/glm
cd ..
ar rcs lib/multimedia.lib src/*.o
del src\*.o