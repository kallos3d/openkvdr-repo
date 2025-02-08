# Nastavenie kompilátora (MSYS2 MinGW)
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2 -D_USE_MINGW_
LDFLAGS = -lm

# Zoznam zdrojových súborov
SRCDIR = src
SOURCES = $(SRCDIR)/openkvdr.cpp \
          $(SRCDIR)/kvd_cli.cpp \
          $(SRCDIR)/kvd_core.cpp \
          $(SRCDIR)/kvd_framebuffer.cpp \
          $(SRCDIR)/kvd_gpu.cpp \
          $(SRCDIR)/kvd_image.cpp \
          $(SRCDIR)/kvd_video.cpp

# Generovanie objektových súborov
OBJECTS = $(SOURCES:.cpp=.o)

# Výstupný spustiteľný súbor
TARGET = OpenKVDR.exe

# Kompilácia všetkých súborov
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

# Kompilácia jednotlivých objektových súborov
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Vymazanie kompilovaných súborov
clean:
	rm -f $(OBJECTS) $(TARGET)

# Spustenie OpenKVDR (MSYS2 podporuje normálne spustenie)
run: $(TARGET)
	./$(TARGET)

# Ladenie pomocou GDB (MSYS2 podporuje GDB)
debug: CXXFLAGS += -g
debug: clean $(TARGET)
	gdb ./$(TARGET)
