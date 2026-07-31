set_project("ShroomEngine")

set_version("0.1.0")

set_languages("cxx23")

add_rules("mode.debug", "mode.release")

add_requires(
    "spdlog"
)

includes(
    "Shroom",
    "Sandbox"
)
