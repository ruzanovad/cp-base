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

    # def configure(self):
    #     pass
    # def generate(self):
    #     tc = CMakeToolchain(self)
    #     tc.generate()
    #     deps = CMakeDeps(self)
    #     deps.generate()
    #     mk = MakeDeps(self)
    #     mk.generate()


    # def build(self):
    #     cmake = CMake(self)
    #     cmake.configure(cli_args=["-B", "build", "-S", "."])
    #     cmake.build(cli_args=[f"--target {self.name}"])
    #     cmake.test()

    # def package(self):
    #     cmake = CMake(self)
    #     cmake.install()

    # def package_info(self):
    #     pass

    # def layout(self):
    #     cmake_layout(self)