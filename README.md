How to build:
    1) Clone git repository with submodules
        git clone --recurse-submodules git@github.com:korenandr/package_manager.git
    
    2) Generate build receipt 
        cd ./package_manager && cmake -S . -B build
        
    3) Build the project into 'build' directory
        cmake --build build
        
        
How to use (example):

cd ./build/src
./package_manager --help
./package_manager


How to work with packages (example):
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
