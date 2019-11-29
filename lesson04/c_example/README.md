# Многопоточность

Мы попробуем многопоточность на языке C с использование библиотеки pthread

### Как скомпилировать?

Для того, чтобы собрать приложение с использованием библиотеки pthread, нужно:

Если вы используете CMake: добавить в него ключ ```-pthread```. Например, такой строчкой:

```
set(CMAKE_CXX_FLAGS "${ CMAKE_CXX_FLAGS} -pthread")
```

### Как запустить санитайзер?

Из консоли вот так:

```
$ clang -fsanitize=thread -g main.cpp 
```

или для плюсов:

```
$ clang++ -fsanitize=thread -g main.cpp 
``` 

### А ещё есть валгринд!

```
$ valgrind --tool=drd ./your_executable
$ valgrind --tool=drd ./your_executable
```

### Автоматическое форматирование кода!

```
$ clang-format -i your_file.cpp
```

### Поменять дефолт для Cmake

```
sudo update-alternatives --config c++
```