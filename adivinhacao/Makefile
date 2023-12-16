CC = clang
CFLAGS = -Wall -Wextra -g    # Flags for the compiler

# List of source files
SRCS = adivinhacao.c

# Output executable name
TARGET = adivinhacao

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	$(RM) $(TARGET)
