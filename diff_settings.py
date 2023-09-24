import os

def apply(config, args):
    basename = "slus-000.05"

    config["arch"] = "mipsel"
    config["baseimg"] = f"{basename}"
    config["myimg"] = f"build/{basename}"
    config["mapfile"] = f"build/{basename}.map"
    config["source_directories"] = [f"src/{basename}", "include"]
