CC = clang
CFLAGS = -Wall -Wextra -g -O0   # Flags for the compiler

# List of source files
SRCS = pacman.c

# Output executable name
TARGET = pacman

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	$(RM) $(TARGET)