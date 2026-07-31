set_project("ShroomEngine")
set_version("0.1.0")

set_languages("cxx23")
set_warnings("all")

add_rules("mode.debug", "mode.release")
set_defaultmode("debug")

add_requires(
    "spdlog"
)

includes(
    "Shroom",
    "Sandbox"
)
