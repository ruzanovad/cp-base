PROJECT_NAME := cp-base
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := test
BUILD_DIR := build
CONAN_DIR := $(BUILD_DIR)/conan

all: build exec

run: reload exec

build: mkdir-build conan cmake-load cmake-build

conan:
	@echo "Running Conan..."
	@mkdir -p $(CONAN_DIR)
	conan install . --build=missing --output-folder=$(CONAN_DIR)

reload: format-clang conan cmake-load cmake-build

mkdir-build:
	[ -d ./build ] | mkdir -p build

cmake-load:
	cd $(BUILD_DIR);cmake ..

cmake-build:
	cd $(BUILD_DIR);cmake --build . --target $(PROJECT_NAME)

format-clang:
	find $(INCLUDE_DIR) $(SRC_DIR) $(TEST_DIR) -iname '*.h' -o -iname '*.cpp' | xargs clang-format -i

clean:
	rm -rf $(BUILD_DIR)

exec:
	./$(BUILD_DIR)/$(PROJECT_NAME)
