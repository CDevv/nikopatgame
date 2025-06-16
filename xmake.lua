add_requires("raylib", "raygui")

target("nikopatgame")
    set_kind("binary")
    add_includedirs("include/")
    add_files("src/*.cpp")
    add_packages("raylib", "raygui")
    set_targetdir("./")
