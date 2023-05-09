from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class networkingRecipe(ConanFile):
    name = "networking"
    version = "1.0"
    package_type = "application"

    # Optional metadata
    license = "MIT"
    author = "Amir Nourinia amir.nouri.nia@gmail.com"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of networking package here>"
    topics = ("C++", "Networking", "Framework")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    def layout(self):
        cmake_layout(self, src_folder="..", build_folder="../build")

    def requirements(self):
        self.requires("boost/[~1]")
        self.requires("jsoncpp/[~1]")
        # self.requires("nlohmann_json/[~3]")
        self.requires("oatpp/[~1]")
        self.requires("imgui/cci.20230105+1.89.2.docking")

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.user_presets_path = "ConanPresets.json"
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
