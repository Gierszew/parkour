CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
LDLIBS   = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

test: main.cpp src/glad.c src/window/window.cpp src/camera/camera.cpp src/mesh/mesh.cpp src/shader/shader.cpp include/stb_image.h
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

run: test
	./test

clean:
	rm -f test