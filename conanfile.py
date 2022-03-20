from conans import ConanFile, tools
from conan.tools.cmake import CMakeToolchain, CMakeDeps, CMake
from conan.tools.layout import cmake_layout


class MicroTexConan(ConanFile):
    name = "microtex"
    version = "1.0.0"

    # Optional metadata
    license = "MIT"
    author = "Nano <artiano@hotmail.com>"
    url = "https://github.com/NanoMichael/microtex"
    description = "A dynamic, cross-platform, and embeddable LaTeX rendering library"
    topics = ("latex", "cross-platform")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True],
        "fPIC": [True, False],
        "QT": [True, False],
        "GTK": [True, False],
        "GDI": [True, False],
        "WASM": [True, False],
        "USE_CONAN_QT": [True, False],
        "HAVE_LOG": [True, False]
    }
    default_options = {
        "shared": True,
        "fPIC": True,
        "QT": False,
        "GTK": False,
        "GDI": False,
        "WASM": False,
        "USE_CONAN_QT": True,
        "HAVE_LOG": True
    }

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "lib/*", "platform/*", "res/*", "MicroTeXInstall.cmake", "prebuilt/*"

    def requirements(self):
        if self.options.QT and self.options.USE_CONAN_QT:
            self.requires("qt/6.2.3")
            self.options['qt'].shared = True
        if self.settings.os == 'Linux' and self.options.GTK:
            self.requires("gtk/system")

    def build_requirements(self):
        self.build_requires("cmake/3.22.0")
        self.build_requires("ninja/1.10.2")

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC
        else:
            del self.options.GDI

        if self.settings.os != 'Linux':
            del self.options.GTK

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables['HAVE_LOG'] = self.options.HAVE_LOG
        # This writes the "conan_toolchain.cmake"
        if self.settings.os == 'Linux':
            tc.variables["GTK"] = self.options.get('GTK')
        tc.variables["QT"] = self.options.QT
        if self.settings.os == "Windows":
            tc.variables["GDI"] = self.options.GDI
        tc.variables["WASM"] = self.options.WASM
        tc.generate()

        deps = CMakeDeps(self)
        # This writes all the config files (xxx-config.cmake)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.includedirs = ["include/microtex", "include/microtex-qt"]
        self.cpp_info.libs = ["microtex", "microtex-qt"]

    def validate(self):
        # C++ minimum standard required
        if self.settings.compiler.get_safe("cppstd"):
            tools.check_min_cppstd(self, 17)
