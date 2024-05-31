CC       = gcc
CFLAGS   = -Iinclude -g
SOURCES  = src/*.c
BIN      = -o bin/app
OBJ=obj
OBJS= $(OBJ)/list.o

$(OBJ)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJS)
	$(CC) $(CFLAGS) main.c $^ $(BIN) $(LDFLAGS)

debug: $(OBJS)
	$(CC) $(CFLAGS) -g main.c $^ $(BIN) $(LDFLAGS)

preprocess: $(OBJS)
	$(CC) $(CFLAGS) -E main.c $^ $(BIN) $(LDFLAGS)

clean:
	rm -rf $(BIN) *.o
