CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -Iinclude/imgui -Iinclude/imgui/backends
LDLIBS   := -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

SRCS := main.cpp \
        src/glad.c \
        src/window/window.cpp \
        src/camera/camera.cpp \
        src/mesh/mesh.cpp \
        src/shader/shader.cpp \
        include/imgui/imgui.cpp \
        include/imgui/imgui_draw.cpp \
        include/imgui/imgui_tables.cpp \
        include/imgui/imgui_widgets.cpp \
        include/imgui/backends/imgui_impl_glfw.cpp \
        include/imgui/backends/imgui_impl_opengl3.cpp

test: $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

run: test
	./test

clean:
	rm -f test

.PHONY: run clean