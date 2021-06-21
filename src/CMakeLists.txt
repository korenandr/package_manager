set(SOURCE_FILES
        Main.cpp
        AppBuilder.cpp
        TerminalApp.cpp
        PackageManagerApp.cpp
        package/Package.cpp
        package/PackageController.cpp
        cmd/CommandCreator.cpp
        cmd/ShowHelpPage.cpp
        cmd/ShowErrorMessage.cpp
        cmd/CreatePackage.cpp
        cmd/AddPackage.cpp
        cmd/PrintPackage.cpp
        cmd/RemovePackage.cpp
        utils/InputCommandValidator.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE cxxopts
                                      PRIVATE nlohmann_json)
