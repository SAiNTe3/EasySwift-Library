# Multimedia-Library 库介绍

## 概述

Multimedia-Library 是基于 OpenGL、stbImage 和 miniAudio 库制作的 2D 图形渲染库。该库提供了方便的接口，使得开发者能够轻松地在应用程序中实现图形渲染和音频播放功能。

## 主要特性

- **图形渲染**：利用 OpenGL 的强大功能，实现高效的 2D 图形渲染。
- **图像加载**：通过集成 stbImage 库，能够轻松加载各种常见的图像格式（如 PNG、JPG 等）。
- **音频播放**：借助 miniAudio 库，实现跨平台的音频播放功能。
- **易用性**：提供简洁明了的 API 接口，方便开发者集成和使用。

## 使用方法

### 编译与运行

1. **下载源码**：从 GitHub 仓库 [SAiNTe3/Multimedia-Library](https://github.com/SAiNTe3/Multimedia-Library) 下载源码。
2. **编译库文件**：运行 `build.bat` 脚本，编译生成的 `.lib` 文件会自动放置在 `/lib` 目录中。
3. **编译项目**：如果使用命令行编译项目，需要加上依赖项并指定库文件路径。例如：

   ```bash
   g++ <源文件>.cpp -o <可执行文件> -lmultimedia -lglfw3 -lopengl32 -lgdi32 -lglad -L<库文件路径>
   ```

## 代码示例

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
