from operator import attrgetter
from pathlib import Path
from PIL import Image
import sys
import os

# Constants
DIR_PATH = os.path.dirname(os.path.realpath(__file__))

# User input
INPUT_FILE = sys.argv[1]
OUTPUT_FILE = sys.argv[2]
OUTPUT_FILE_PATH = Path(sys.argv[2])
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
    # Convert the image to RGBA and use 8-bit color
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


def write_python_file(input_matrix, height, width):
    """
    Write the matrix data into a Python file.
    """
    with open(f"{os.path.dirname(OUTPUT_FILE)}/{OUTPUT_FILE_NAME}", "w") as file:
        file.write("# Auto-generated image matrix\n")
        file.write("\n")

        file.write(f"HEIGHT = {height}\n")
        file.write(f"WIDTH = {width}\n")
        file.write("\n")

        for name, matrix in input_matrix.items():
            file.write(f"{name.upper()}_MATRIX = [\n")
            for row in matrix:
                file.write("    [")
                for column in row:
                    if column[3] != 0:
                        file.write(f"({column[0]}, {column[1]}, {column[2]}, {column[3]}), ")
                    else:
                        file.write("(0, 0, 0, 0), ")
                file.write("],\n")
            file.write("]\n\n")


def write_output_file(input_matrix, height, width):
    """
    Write the matrix data into a Python file.
    """
    write_python_file(input_matrix, height, width)


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
    print(f"Generated {OUTPUT_FILE}.py with {len(images)} images.")


if __name__ == "__main__":
    main()
