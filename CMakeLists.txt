cmake_minimum_required(VERSION 3.15)
project(gravityL CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(gravityL ${SOURCES})

target_include_directories(gravityL PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*"
    "${RAYLIB_INCLUDE_DIRS}"
    "${raylib_INCLUDE_DIRS}"
)

target_link_libraries(gravityL PRIVATE
	-g -fsanitize=address,undefined # -D_GLIBCXX_DEBUG
	${RAYLIB_LIBRARIES}
)

target_compile_options(gravityL PRIVATE
    $<$<CONFIG:Debug>:-g -O0 -fsanitize=address,undefined -D_GLIBCXX_DEBUG>
)
target_link_options(gravityL PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
)

# 3. Release mode optimizations (Optional - uncomment if needed)
target_compile_options(gravityL PRIVATE
    $<$<CONFIG:Release>:-O3 -march=native -flto>
)