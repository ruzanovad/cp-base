from conan import ConanFile
from conan.tools.cmake import CMakeDeps, CMakeToolchain, CMake
from conan.tools.gnu import MakeDeps
from conan.tools.cmake import cmake_layout


class CpBaseConan(ConanFile):
    name = "cp-base"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain", "MakeDeps"
    layout = cmake_layout

    def requirements(self):
        self.requires("gtest/1.15.0")

    def build_requirements(self):
        self.tool_requires("cmake/3.23.5")