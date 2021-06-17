set(SOURCE_FILES
        Main.cpp
        AppBuilder.cpp
        TerminalApp.cpp
        PackageManagerApp.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE cxxopts)
