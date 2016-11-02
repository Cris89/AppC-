cmake_minimum_required(VERSION 3.5.2)

project(AppCpp)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

set(SHARED_LIBS /usr/local/lib/libalpm.so /usr/local/lib/libpaho-mqtt3a.so /usr/local/lib/libpaho-mqtt3as.so /usr/local/lib/libpaho-mqtt3c.so /usr/local/lib/libpaho-mqtt3cs.so)
link_directories(shared_lib/build)

add_executable(AppCpp ${SOURCES})

target_link_libraries(AppCpp ${SHARED_LIBS})
