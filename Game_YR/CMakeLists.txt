set(HEADER_FILES 
	)
set(SOURCE_FILES
	main.cpp
)

add_executable(Game_YR ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_YR BackSpace)
include_directories(../BackSpace/include)