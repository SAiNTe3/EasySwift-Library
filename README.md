# EasySwift Library

## Overview

EasySwift Library is a 2D graphics rendering library based on OpenGL, stbImage, and miniAudio libraries. This library provides convenient interfaces that enable developers to easily implement graphics rendering and audio playback functions in their applications.

## Features

- **Graphics rendering**: Use the power of OpenGL to achieve efficient 2D graphics rendering.
- **Image loading**: By integrating the stbImage library, you can easily load various common image formats (such as PNG, JPG, etc.).
- **Audio playback**: With the help of the miniAudio library, cross-platform audio playback function is realized.
- **Ease of use**: Provides a concise and clear API interface for developers to integrate and use easily.

## Usage

### Build Static Library By Yourself

- g++:

```bash
cd src
```
```bash
g++ -c glad/glad.c Audio.cpp AudioEngine.cpp Shader.cpp Sprite.cpp Sprite3D.cpp Camera.cpp Texture.cpp Keyboard.cpp Mouse.cpp Window.cpp Clock.cpp Cursor.cpp Event.cpp CharacterMap.cpp Text.cpp BasicShape/Shape.cpp BasicShape/CircleShape.cpp -I../include -I../include/glad -I../include/stbImage -I../include/miniAudio -I../include/glm -I../include/BasicShape
```
```bash
cd ..
```
```bash
ar rcs lib/esl.lib src/*.o
```
```bash
del src\*.o
```

- CMake:

```bash
mkdir build
```
```bash
cd build
```
```bash
cmake ..
```
```bash
cmake --build .
```

## Code Example

```cpp
#include "ESL/ESL.hpp"
#include "ESL/Window.hpp"

int main()
{
	esl::Initialize();
	Window window(800, 600, "ESL Window");
	while (window.isOpen())
	{
		esl::Event e;
		window.pollEvents(e);
		window.clear();
		window.display();
	}
	esl::Terminate();
}
```
