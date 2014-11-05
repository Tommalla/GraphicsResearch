set(SOURCES
	AnimatedCharacter.cpp
	main.cpp
	GraphicalObject.cpp
)

set(HEADERS
	AnimatedCharacter.hpp
	GraphicalObject.hpp
)

add_executable(main ${SOURCES})
target_link_libraries(main ${SFML_LIBRARIES})
