project(schedule)

include_directories(src)

set(SOURCE
lecture.cpp
lecture.h
student.h
uc.cpp
uc.h)

add_executable(${PROJECT_NAME} ${SOURCE})

add_definitions("-g")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
