# EasySwift Library

## Overview

EasySwift Library is a 2D graphics rendering library based on OpenGL, stbImage, and miniAudio libraries. This library provides convenient interfaces that enable developers to easily implement graphics rendering and audio playback functions in their applications.

## Features

- **Graphics rendering**: Use the power of OpenGL to achieve efficient 2D graphics rendering.
- **Image loading**: By integrating the stbImage library, you can easily load various common image formats (such as PNG, JPG, etc.).
- **Audio playback**: With the help of the miniAudio library, cross-platform audio playback function is realized.
- **Ease of use**: Provides a concise and clear API interface for developers to integrate and use easily.

## Usage

### Compile and Run

1. **Download source code**: Download source code from GitHub repository [SAiNTe3/EasySwift-Library](https://github.com/SAiNTe3/EasySwift-Library).
2. **Compile library files**: Run the `build.bat` script, and the compiled `.lib` files will be automatically placed in the `/lib` directory.
3. **Compile project**: If you use the command line to compile the project, you need to add dependencies and specify the library file path. For example:

```bash
g++ <source file>.cpp -o <executable file> -lmultimedia -lglfw3 -lopengl32 -lgdi32 -lglad -L<library file path>
```

## Code Example

```cpp
#include "include/Window.hpp"

int main()
{
	Window::Initialize(4, 6);
	Window window(800, 450, "DemoWindow", true, true);
	while (window.isOpen())
	{
		window.pollEvents();
		window.clear();
		window.display();
	}
	Window::Terminate();
}
```
