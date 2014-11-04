set(SOURCES
	main.cpp
	GraphicalObject.cpp
)

set(HEADERS
	GraphicalObject.hpp
)

add_executable(main ${SOURCES})
target_link_libraries(main ${SFML_LIBRARIES})
