file(GLOB_RECURSE lowchat_server_srcs CONFIGURE_DEPENDS *.cpp)

add_executable(lowchat_server ${lowchat_server_srcs})
