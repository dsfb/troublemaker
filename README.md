# troublemaker
Experimenting with graphics programming
Pet project to follow an opengl tutorial (https://learnopengl.com/)

The requirements are:

* CMake 3.14+.
* A C++17 compatible compiler
* OpenGL 3.3+

If an executable for clang-tidy is found, it will be used during the build.

To configure (on the root folder):

```bash
cmake -S . -B build
```

Specify a generator if required or desired

To build:

```bash
cmake --build build
```

To apply clang-format (if available), after having configured:

```bash
cmake --build build --target clangformat
```
