CC = clang
CFLAGS = -Wall -Wextra -g    # Flags for the compiler

# List of source files
SRCS = forca.c

# Output executable name
TARGET = forca

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	$(RM) $(TARGET)
