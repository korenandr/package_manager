# Package manager
> This manager helps to create a hierarchy of packages with different nesting.
<hr>

# How to build:
```
git clone --recurse-submodules git@github.com:korenandr/package_manager.git
cd ./package_manager && cmake -S . -B build
cmake --build build
```

# How to use (example):
```
cd ./build/src
./package_manager --help
./package_manager
```


# How to work with packages (example of commands):
```
create home
add home project
add home/project teslasuit
add home games
create media
add media devices
add media/devices headphones
add media/devices microphone
remove home/project
print media/devices
print
exit
```

### Useful links

* [C++ Starter Template](https://github.com/cpp-best-practices/gui_starter_template)
* [Google Test](https://github.com/google/googletest/blob/master/googletest/docs/Primer.md)
