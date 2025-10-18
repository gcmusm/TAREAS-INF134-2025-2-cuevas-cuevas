# ==== Configuración de compilación ====
CXX      := g++
CXXFLAGS := -std=gnu++17 -Wall -Wextra -Wpedantic -O2
# (opcional) para depurar usa: make debug
DBGFLAGS := -g
# ==== Archivos del proyecto ====
SRCS := main.cpp \
        carta.cpp \
        list.cpp \
        mazo.cpp \
        abb.cpp \
        interfaz.cpp \
        comandos.cpp \
        evaluador.cpp

OBJS := $(SRCS:.cpp=.o)
BIN  := balatro

# ==== Targets principales ====
all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Regla genérica para compilar .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ==== Atajos útiles ====
run: $(BIN)
	./$(BIN)

clean:
	rm -f $(OBJS) $(BIN)

# Compilación con símbolos de depuración
debug: CXXFLAGS += $(DBGFLAGS)
debug: clean all

# (opcional) AddressSanitizer para cazar fugas/overflows
asan: CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer -g
asan: clean all

.PHONY: all run clean debug asan