# **webserv**
Codam / 42 webserv project

## Compiling and running
### Dependencies
- C++ compiler (clang++ or g++) with C++20 support
- CMake 3.21 or higher

### Compilation steps
- create build folder `mkdir build && cd build`
- generate build files `cmake ..`
- compile project `cmake --build .` or `make`

### Run project
- run project `./webserv [config_file]`

### Run tests
- generate build files with tests `cmake -DBUILD_TESTS=y ..`
- compile project `cmake --build .` or `make`
- run tests `ctest`

### Compile debug build (address sanitizer)
- generate build files with AddressSanitizer `cmake -DCMAKE_BUILD_TYPE=Debug ..`
- compile project `cmake --build .` or `make`

## Development
### Autoformat vscode

Steps to prepare vscode for autoformatting:
- Install vscode extension: C/C++ IntelliSense (`ms-vscode.cpptools`)
- Copy `.vscode/settings.json.default` to `.vscode/settings.json` (this will apply the default settings for this project)

Use the following key combinations to format the file:
- Macos: `Option + Shift + F` to format the file
- Linux: `Ctrl + Shift + I` to format the file

**Dont forget to format files before commiting!**

### Better C++ syntax & error highlighting
Steps to prepare vscode for better C++ syntax highlighting:
- Install vscode extension: C/C++ IntelliSense (`ms-vscode.cpptools`)
- Copy `.vscode/c_cpp_properties.json.default` to `.vscode/c_cpp_properties.json` (this will apply the default settings for this project)


## **config file**
To configure webserv, use the [configuration file](CONFIG.md).
