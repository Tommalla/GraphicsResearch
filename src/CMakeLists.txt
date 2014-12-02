add_subdirectory(SFML)

set(SOURCES
	AnimatedCharacter.cpp
	main.cpp
	GraphicalObject.cpp
	MainWindow.cpp
)

set(HEADERS
	AnimatedCharacter.hpp
	GraphicalObject.hpp
)

set(MOC_HEADERS
	MainWindow.hpp
)

qt5_wrap_cpp(SOURCES ${MOC_HEADERS})
add_executable(main ${SOURCES} ${HEADERS})
target_link_libraries(main ${Qt5Widgets_LIBRARIES} ${SFML_LIBRARIES} SFMLGraphics)
