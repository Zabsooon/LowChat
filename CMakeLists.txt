cmake_minimum_required(VERSION 3.20)
project(LowChat)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(lowchat_add_compile_options target)
	set_target_properties(${target} PROPERTIES
		CXX_STANDARD 20
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS OFF)
	target_compile_options(${target} PRIVATE
		$<$<CXX_COMPILER_ID:MSVC>:/MP /W4 /external:W0>
		$<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Wpedantic -Wtype-limits -Wconversion -Wsign-conversion -Wdouble-promotion -g>
		$<$<CXX_COMPILER_ID:GNU>:-fdiagnostics-color>
		$<$<CXX_COMPILER_ID:Clang,AppleClang>:-fcolor-diagnostics>)
endfunction()

add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(common)

#######################################################
# Common
lowchat_add_compile_options(lowchat_common)
target_include_directories(lowchat_common PUBLIC common)

#######################################################
# Client
lowchat_add_compile_options(lowchat_client)
target_link_libraries(lowchat_client PRIVATE lowchat_common)

#######################################################
# Server
lowchat_add_compile_options(lowchat_server)
target_link_libraries(lowchat_server PRIVATE lowchat_common)
