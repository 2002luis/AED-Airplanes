project(schedule)

include_directories(src)

set(SOURCE
src/main.cpp
src/Read.cpp
src/Read.h
src/Write.cpp
src/Write.h
src/Uc.cpp
src/Uc.h
src/Class.cpp
src/Class.h
src/Sort.cpp
src/Sort.h
src/Student.cpp
src/Student.h
)

add_executable(${PROJECT_NAME} ${SOURCE})

add_definitions("-g")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)