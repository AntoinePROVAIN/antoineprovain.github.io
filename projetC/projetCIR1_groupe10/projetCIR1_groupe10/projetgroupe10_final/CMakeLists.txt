cmake_minimum_required(VERSION 3.13)
project(project_goupe_10 C)

set(CMAKE_C_STANDARD 99)


add_executable(project_goupe_10 main.c filemanager.c population.c export_html.c advanced.c)
target_link_libraries(project_goupe_10 m)