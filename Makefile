CC=gcc
CFLAGS=-Isrc -Itest -fprofile-arcs -ftest-coverage
LDFLAGS=-fprofile-arcs -ftest-coverage
OBJ_DIR=build/obj
BIN_DIR=build/bin
GCOV_DIR=build/gcov

# gratuitous commment
all: run_tests

directories:
	mkdir -p $(OBJ_DIR) $(BIN_DIR) $(GCOV_DIR)

compile: directories $(OBJ_DIR)/a.o $(OBJ_DIR)/b.o $(BIN_DIR)/test_runner_a $(BIN_DIR)/test_runner_b

run_tests: compile
	$(BIN_DIR)/test_runner_a
	$(BIN_DIR)/test_runner_b

$(BIN_DIR)/test_runner_a: test/test_a.c $(OBJ_DIR)/a.o test/unity.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BIN_DIR)/test_runner_b: test/test_b.c $(OBJ_DIR)/b.o test/unity.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/a.o: src/a.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/b.o: src/b.c
	$(CC) $(CFLAGS) -c $< -o $@

coverage: compile
	mv $(OBJ_DIR)/*.gcno $(GCOV_DIR) || true
	mv $(OBJ_DIR)/*.gcda $(GCOV_DIR) || true
	gcov -o $(GCOV_DIR) -r $(OBJ_DIR)/*.o || true
	mv *.gcov $(GCOV_DIR) || true

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(GCOV_DIR)
