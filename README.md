# basic-cicd
A minimal framework that demonstrates coverage and unit testing with CI/CD using Unity, FFF, GCov, makefile and GitHub CI/CD

This repository contains two C sources: `src/a.[ch]` and `src/b.[ch]`.  While `src/a.c` is a standalone module, `src/b.c` intentionally has dependencies on `src/a.c`.  Consequently, `test/test_b.c` includes the FFF constructs for fakes / mocks for the functions defined in `a.c`.

When you do a push, GitHub will automatically run unit tests and code coverage tests.  The results of the tests show up in the `Actions` tab on the home page.


