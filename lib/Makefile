# Ferdinand Saufler <mail@saufler.de
# 04.11.2014
# makefile to include

# entry point
all: $(TARGET)

# link a binary from the object files
$(TARGET): $(OBJ)
	$(CC) -o $(O_DIR)/$(TARGET) $(OBJ) $(OBJ_BIND)

# Suffix rules
# $< source file (file.c)
# $@ destination file (file.o)
$(O_DIR)/%.o: %.c dir
	$(CC) $(CFLAGS) $< -o $@

dir:
	mkdir -p $(O_DIR)

valgrind:
	valgrind --tool=memcheck ./$(O_DIR)/$(TARGET)

# cleanup the mess
clean:
	rm -rf $(O_DIR)/
	rm -f *~
	rm -f *.orig
