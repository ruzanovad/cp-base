PROJECT_NAME := cp-base
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := test
BUILD_DIR := build
# CONAN_DIR := $(BUILD_DIR)/conan

all: build exec

run: reload exec

build: mkdir-build conan-build cmake-load cmake-build conan-deactivate

conan-build:
	@echo "Running Conan..."
	@conan install . --output-folder $(BUILD_DIR) --build=missing
	sh build/build/Release/generators/conanbuild.sh


conan-deactivate:
	sh build/build/Release/generators/conanbuild.sh

reload: conan-build cmake-load cmake-build conan-deactivate

mkdir-build:
	[ -d ./build ] | mkdir -p build

cmake-load:
	cd $(BUILD_DIR); cmake .. -DCMAKE_BUILD_TYPE=Release

cmake-build:
	cd $(BUILD_DIR);cmake --build . --target $(PROJECT_NAME)

format-clang:
	find $(INCLUDE_DIR) $(SRC_DIR) $(TEST_DIR) -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

clean:
	rm -rf $(BUILD_DIR)

exec:
	./$(BUILD_DIR)/$(PROJECT_NAME)

.PHONY: all build cmake-build run clean

