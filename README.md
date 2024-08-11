# Requirements
1. conan 2
2. cmake 3.23 and higher
3. clang-format

# Build & Run
All commands allowed in [Makefile](./Makefile)

Build:
```sh
make build
```

Build and execute:
```sh
make
```

Apply changes and run:
```sh
make run
```
# Possible fix of "version `GLIBCXX_3.4.32' not found" (or similar)

https://stackoverflow.com/questions/48453497/anaconda-libstdc-so-6-version-glibcxx-3-4-20-not-found

``sh
conda install -c conda-forge libstdcxx-ng
``
