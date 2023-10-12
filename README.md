# basic-cicd
A minimal framework that demonstrates coverage and unit testing with CI/CD using Unity, FFF, GCov, makefile and GitHub CI/CD

This repository contains two C sources: `src/a.[ch]` and `src/b.[ch]`.  While `src/a.c` is a standalone module, `src/b.c` intentionally has dependencies on `src/a.c`.  

When you do a push on the `develop` branch, GitHub will automatically run unit tests and code coverage tests.  The results of the tests show up in the `Actions` tab on the home page.  (Note that it will NOT run the tests if you're in the `main` branch -- this is intentional.)

