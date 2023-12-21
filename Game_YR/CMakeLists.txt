set(HEADER_FILES 
	Player.h
	BabyGhost.h
	)
set(SOURCE_FILES
	main.cpp
	Player.cpp
	BabyGhost.cpp
)

add_executable(Game_YR ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_YR BackSpace)
include_directories(../BackSpace/include)