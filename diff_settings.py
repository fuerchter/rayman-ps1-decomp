import os

def apply(config, args):
    basename = "slus-000.05"

    config["arch"] = "mipsel"
    config["baseimg"] = f"SLUS-000.05"
    config["myimg"] = f"build/{basename}"
    config["mapfile"] = f"build/{basename}.map"
    config["source_directories"] = ["src", "src/obj", "include"]
    config["make_command"] = ["make", "-f", "mk-splat.mk"]
