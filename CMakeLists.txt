cmake_minimum_required(VERSION 3.15)
project(gravityL CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -flto=thin -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -flto=thin -Wl,--gc-sections")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)
find_package(nlohmann_json 3.12.0 REQUIRED)


file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(gravityL ${SOURCES})

target_include_directories(gravityL PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*"
    "${RAYLIB_INCLUDE_DIRS}"
    "${raylib_INCLUDE_DIRS}"
)

target_link_libraries(gravityL PRIVATE
  # -g -fsanitize=address,undefined -D_GLIBCXX_DEBUG
	${RAYLIB_LIBRARIES}
)

