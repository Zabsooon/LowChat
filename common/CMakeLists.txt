file(GLOB_RECURSE lowchat_common_srcs CONFIGURE_DEPENDS lowchat/*.cpp)

add_library(lowchat_common STATIC ${lowchat_common_srcs})
