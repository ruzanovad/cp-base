project = cp-base

all: build exec

run: reload exec

build: mkdir-build cmake-load cmake-build

reload: format cmake-load cmake-build

mkdir-build:
	[ -d ./build ] | mkdir -p build

cmake-load:
	cd build;cmake ..

cmake-build:
	cd build;cmake --build . --target $(project)

format:
	find include src test -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

clean:
	rm -rf build

exec:
	./build/$(project)
