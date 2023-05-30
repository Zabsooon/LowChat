file(GLOB_RECURSE lowchat_client_srcs CONFIGURE_DEPENDS *.cpp)

add_executable(lowchat_client ${lowchat_client_srcs})
