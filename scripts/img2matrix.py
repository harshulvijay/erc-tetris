# converts an image of `WxH` pIxels into a matrix of dimensions `WxH`
# usage: python img2matrix.py <INPUT FILE/DIRECTORY> <OUTPUT FILE> <PATH TO "color.h">

from operator import attrgetter
from pathlib import Path
from PIL import Image
import sys
import os

# constants
DIR_PATH = os.path.dirname(os.path.realpath(__file__))
# user input
INPUT_FILE = sys.argv[1]
OUTPUT_FILE = sys.argv[2]
OUTPUT_FILE_PATH = Path(sys.argv[2])
COLOR_H_IMPORT_PATH = Path(os.path.relpath(
    sys.argv[3], start=OUTPUT_FILE_PATH.parent))
OUTPUT_FILE_NAME = os.path.basename(OUTPUT_FILE).split(".")[0]


def rgba_to_8_bit_color(rgba):
    R, G, B, A = rgba

    if A == 0:
        return -1

    red = (R >> 5) & 0b111
    green = (G >> 5) & 0b111
    blue = (B >> 6) & 0b111

    return (red << 5) | (green << 2) | blue


def read_image_with_8_bit_colors(image_path):
    image_path = Path(os.getcwd(), image_path).resolve()
    image = Image.open(image_path)
    # convert the image to RGBA and use 8-bit color
    image = image.convert("RGBA", colors=8)
    (height, width) = attrgetter("height", "width")(image)

    output_matrix = []
    for y in range(height):
        row = []

        for x in range(width):
            pixel = image.getpixel((x, y))
            row.append(pixel)

        output_matrix.append(row)

    return (output_matrix, (height, width))


def write_header_file(input_matrix, height, width):
    include_once_name = OUTPUT_FILE_NAME.upper()
    include_once_name_h = f"{include_once_name}_HEADER"

    with open(f"{os.path.dirname(OUTPUT_FILE)}/{OUTPUT_FILE_NAME}.h", "w") as file:
        if os.path.isdir(OUTPUT_FILE) or True:
            file.write("// Auto-generated image matrix\n")
            file.write(f"#ifndef {include_once_name_h}\n")
            file.write(f"#define {include_once_name_h}\n")
            file.write("\n")

        file.write(f"#include <stdbool.h>\n")
        file.write(f"#include \"{COLOR_H_IMPORT_PATH}\"\n")
        file.write("\n")

        file.write(f"#define {include_once_name}_HEIGHT {height}\n")
        file.write(f"#define {include_once_name}_WIDTH {width}\n")
        file.write(f"#define EMPTY_COLOR {{.r = 0, .g = 0, .b = 0, .a = 0}}\n")
        file.write(f"#define EMPTY_SET {{0, 0, 0}}\n")
        file.write("\n")

        for _, (name, _) in enumerate(input_matrix.items()):
            file.write(f"extern const int {include_once_name}_" +
                       f"{name.upper()}[{height}][{width}][3];\n")
            file.write("\n")
            file.write(f"extern const Color {include_once_name}_COLORED_" +
                       f"{name.upper()}[{height}][{width}];\n")
            file.write("\n")

        file.write("#endif")


def write_c_file(input_matrix, height, width):
    include_once_name = OUTPUT_FILE_NAME.upper()

    with open(f"{os.path.dirname(OUTPUT_FILE)}/{OUTPUT_FILE_NAME}.c", "w") as file:
        if os.path.isdir(OUTPUT_FILE) or True:
            file.write("// Auto-generated image matrix\n")
            file.write("\n")

        file.write(f"#include \"{OUTPUT_FILE_NAME}.h\"\n\n")

        for _, (name, matrix) in enumerate(input_matrix.items()):
            file.write(f"const int {include_once_name}_" +
                       f"{name.upper()}[{height}][{width}][3] = {{\n")

            for row in matrix:
                string_to_write = ""

                for column in row:
                    if column[3] != 0:
                        r = column[0]
                        g = column[1]
                        b = column[2]

                        if r:
                            r = "true"
                        else:
                            r = "false"
                        if g:
                            g = "true"
                        else:
                            g = "false"
                        if b:
                            b = "true"
                        else:
                            b = "false"

                        color_pair = f"{{{r}, {g}, {b}}}, "
                    else:
                        color_pair = "EMPTY_SET, "
                    string_to_write += color_pair

                file.write("\t{" + string_to_write + "},\n")

            file.write("};\n")
            file.write("\n")

            file.write(f"const Color {include_once_name}_COLORED_" +
                       f"{name.upper()}[{height}][{width}] = {{\n")

            for row in matrix:
                string_to_write = ""

                for column in row:
                    if column[3] != 0:
                        color_pair = (f"{{.r = {column[0]}, " +
                                      f".g = {column[1]}, .b = {column[2]}, .a = {column[3]}}}, ")
                    else:
                        color_pair = "EMPTY_COLOR, "
                    string_to_write += color_pair

                file.write("\t{" + string_to_write + "},\n")

            file.write("};\n")
            file.write("\n")


def write_output_file(input_matrix, height, width):
    write_header_file(input_matrix, height, width)
    write_c_file(input_matrix, height, width)


def main():
    images = {}

    if os.path.isdir(INPUT_FILE):
        for file_name in os.listdir(INPUT_FILE):
            name = os.path.splitext(file_name)[0]
            file_path = os.path.join(INPUT_FILE, file_name)

            if os.path.isdir(file_path):
                continue

            images[name], (height, width) = read_image_with_8_bit_colors(
                file_path)
    else:
        name = os.path.basename(INPUT_FILE).split(".")[0]
        file_path = INPUT_FILE
        images[name], (height, width) = read_image_with_8_bit_colors(file_path)

    write_output_file(images, height, width)
    print(f"Generated {OUTPUT_FILE} with {len(images)} images.")


if __name__ == "__main__":
    main()
