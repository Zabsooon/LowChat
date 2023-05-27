cmake_minimum_required(VERSION 3.20)
project(LowChat)

set(PROJECT_HEADERS
	terminator.h
)

set(PROJECT_SOURCES
	server.cpp
	terminator.cpp
)

add_executable(LowChat
	${PROJECT_SOURCES}
	${PROJECT_HEADERS}
)
