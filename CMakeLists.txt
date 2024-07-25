cmake_minimum_required(VERSION 3.14)
project(snake)  # 여기에 프로젝트 이름을 적어주세요

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 14)

# ncurses 라이브러리 찾기
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

# 실행 파일 생성
add_executable(snakeGame main.cpp)

# include 폴더 추가
target_include_directories(snakeGame PRIVATE include)

# 헤더와 구현 파일 추가
target_sources(snakeGame PRIVATE
    include/Game.h
    include/GameMap.h
    include/Item.h
    include/MissionBoard.h
    include/ScoreBoard.h
    include/Snake.h
    
    include/Game.cpp
    include/GameMap.cpp
    include/Item.cpp
    include/MissionBoard.cpp
    include/ScoreBoard.cpp
    include/Snake.cpp
)

# ncurses 라이브러리 링크
target_link_libraries(snakeGame ${CURSES_LIBRARIES})
