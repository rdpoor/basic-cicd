CC=gcc
CFLAGS=-Isrc -Itest -fprofile-arcs -ftest-coverage
LDFLAGS=-fprofile-arcs -ftest-coverage

SRC_FILES=src/a.c src/b.c
TEST_FILES=test/test_a.c test/test_b.c test/unity.c

all: run_tests

run_tests: test_runner
	./test_runner

test_runner: $(SRC_FILES) $(TEST_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f test_runner
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.gcov
