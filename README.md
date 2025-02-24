## 自行构建库文件
运行**build.bat**即可，.lib会自动放在/lib中
## 链接库文件
如果使用命令行，需要加上依赖项并指定库文件路径，格式为<br>
``
g++ <源文件>.cpp -o <可执行文件> -lmultimedia -lglfw3 -lopengl32 -lgdi32 -lglad -L<库文件路径>
``
