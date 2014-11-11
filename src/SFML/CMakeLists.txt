set(SFML_GRAPHICS_HEADERS
	BenchmarkCanvas.hpp
	QSFMLCanvas.hpp
)

set(SFML_GRAPHICS_SOURCES
	BenchmarkCanvas.cpp
	QSFMLCanvas.cpp
)

qt5_wrap_cpp(SFML_GRAPHICS_SOURCES ${SFML_GRAPHICS_HEADERS})

add_library(SFMLGraphics ${SFML_GRAPHICS_SOURCES})
target_link_libraries(SFMLGraphics ${Qt5Widgets_LIBRARIES} ${SFML_LIBRARIES})