CC=gcc
CFLAGS=-Isrc -Itest -fprofile-arcs -ftest-coverage
LDFLAGS=-fprofile-arcs -ftest-coverage
OBJDIR=build/obj
BINDIR=build/bin
GCOVDIR=build/gcov

all: directories run_tests

directories:
	mkdir -p $(OBJDIR) $(BINDIR) $(GCOVDIR)

run_tests: $(BINDIR)/test_runner_a $(BINDIR)/test_runner_b
	$(BINDIR)/test_runner_a
	$(BINDIR)/test_runner_b

$(OBJDIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) $(CFLAGS) -MM $< > $(OBJDIR)/$*.d

$(BINDIR)/test_runner_a: test/test_a.c $(OBJDIR)/a.o test/unity.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BINDIR)/test_runner_b: test/test_b.c $(OBJDIR)/b.o test/unity.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

coverage:
	find . -name "*.gcno" -exec mv {} $(GCOVDIR) \;
	find . -name "*.gcda" -exec mv {} $(GCOVDIR) \;
	gcov -o $(GCOVDIR) -r $(OBJDIR)/*.o
	mv *.gcov $(GCOVDIR) || true

clean:
	rm -rf build

-include $(OBJDIR)/*.d
