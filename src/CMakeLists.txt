set(SOURCE_FILES
        Main.cpp
        AppBuilder.cpp
        TerminalApp.cpp
        PackageManagerApp.cpp
        package/Package.cpp
        package/PackageController.cpp
        log/logger.cpp
        cmd/CommandCreator.cpp
        cmd/ShowHelpPage.cpp
        cmd/ShowErrorMessage.cpp
        cmd/CreatePackage.cpp
        cmd/AddPackage.cpp
        cmd/PrintPackage.cpp
        cmd/RemovePackage.cpp
        utils/InputCommandValidator.cpp
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

file(GLOB configFile log/log.properties)
file(COPY ${configFile} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(${PROJECT_NAME} PRIVATE project_options
                                      PRIVATE project_warnings
                                      PRIVATE cxxopts
                                      PRIVATE nlohmann_json
                                      PRIVATE log4cplus)
