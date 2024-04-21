add_rules("mode.debug", "mode.release")
target("mihoyo_asm_interpreter")
    set_kind("binary")
    add_files("src/main.cpp")