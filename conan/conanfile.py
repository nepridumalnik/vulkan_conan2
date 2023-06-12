import os

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout, CMakeToolchain, CMakeDeps


class Recipe(ConanFile):
    name = 'vulkan_build'
    version = '0.1'
    package_type = 'application'

    settings = [
        'os',
        'compiler',
        'build_type',
        'arch',
    ]

    options = {
        'shared': [True, False],
        'fPIC': [True, False],
    }

    default_options = {
        'shared': False,
        'fPIC': True,
    }

    def layout(self) -> None:
        self.folders.root = '..'
        self.folders.source = '.'
        self.folders.build = 'build'
        cmake_layout(self)

    def build(self) -> None:
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def generate(self) -> None:
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.user_presets_path = 'ConanPresets.json'
        tc.generate()

    def requirements(self) -> None:
        self.requires('glfw/3.3.8')
        self.requires('glew/2.2.0')
        self.requires('glm/cci.20230113')

    def config_options(self) -> None:
        self.options['glfw'].shared = True
        self.options['glew'].shared = True

    def imports(self) -> None:
        self.copy('*.dll', dst='bin', src='bin')
        self.copy('*.so', dst='lib', src='lib')
        self.copy('*.dylib', dst='lib', src='lib')
