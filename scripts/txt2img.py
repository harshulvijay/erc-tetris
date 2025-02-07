from PIL import Image, ImageDraw, ImageFont
import os

# Dictionary of non-alphanumeric characters and their shortened English names
NON_ALPHANUMERIC_CHARS = {
    '<': 'lt',      # less than
    '>': 'gt',      # greater than
    ':': 'colon',
    '"': 'quote',
    '/': 'slash',
    '\\': 'backslash',
    '|': 'pipe',
    '?': 'question',       # question
    '*': 'asterisk',
    '(': 'lparen',  # left parenthesis
    ')': 'rparen',  # right parenthesis
    '[': 'lbrack',  # left bracket
    ']': 'rbrack',  # right bracket
    '{': 'lbrace',  # left brace
    '}': 'rbrace',  # right brace
    ',': 'comma',
    '.': 'dot',
    '+': 'plus',
    '-': 'minus',
    '=': 'equal',
    '&': 'amp',     # ampersand
    '^': 'caret',
    '%': 'percent',
    '$': 'dollar',
    '#': 'hash',
    '@': 'at',
    ';': 'semicolon',
    "'": 'apostrophe',
    ' ': 'space',
    '!': 'excl',     # exclamation mark
    '_': 'underscore',
    '`': 'backtick',
    '~': 'tilde'     # tilde
}


def make_path_compatible(char):
    # Replace non-alphanumeric characters with their shortened English names
    filename = char
    for invalid, short_name in NON_ALPHANUMERIC_CHARS.items():
        filename = filename.replace(invalid, short_name)

    # Append the prefixes at the end
    if char.isupper():
        filename = f"uc_{filename}"
    elif char.isdigit():
        filename = f"num_{filename}"

    # Make sure it's compatible with both Windows and Linux by using os.path
    # This removes any leading/trailing path separators
    filename = os.path.basename(filename)

    return filename


def text_to_png_scaled(text, font_path, output_file, text_color=(255, 255, 255), bg_color=(0, 0, 0, 0)):
    """
    Converts a single ASCII character to a transparent PNG, removes transparent pixels,
    and scales it to 6x6 pixels.

    :param text: The ASCII text to convert (e.g., one character at a time).
    :param font_path: Path to the JetBrains Mono font file.
    :param output_file: Path to save the output PNG.
    :param text_color: Color of the text in (R, G, B).
    :param bg_color: Background color in (R, G, B, A).
    """
    if len(text) != 1:
        raise ValueError(
            "Only single characters are supported for this scaling method.")

    # Create a temporary canvas to render the text
    font_size = 100  # Start with a large font size
    font = ImageFont.truetype(font_path, font_size)
    temp_canvas_size = 200  # Large enough to avoid clipping
    temp_img = Image.new(
        "RGBA", (temp_canvas_size, temp_canvas_size), bg_color)
    draw = ImageDraw.Draw(temp_img)

    # Measure text dimensions and position
    text_width, text_height = draw.textsize(text, font=font)
    text_x = (temp_canvas_size - text_width) // 2
    text_y = (temp_canvas_size - text_height) // 2

    # Draw the text onto the temporary canvas
    draw.text((text_x, text_y), text, font=font, fill=text_color + (255,))

    # Crop the image to remove transparent areas
    # Crop to the bounding box of the text
    temp_img = temp_img.crop(temp_img.getbbox())

    # Resize to 6x6 while preserving sharpness
    scaled_img = temp_img.resize((8, 8), Image.NEAREST)

    # Save the resulting image
    scaled_img.save(output_file)


# Example usage
text = "".join(chr(i) for i in range(32, 127))
# Replace with the actual path to JetBrains Mono
font_path = "scripts/JetBrainsMono-Regular.ttf"

for char in text:
    output_file = f"res/text/{make_path_compatible(char)}.png"
    text_to_png_scaled(char, font_path, output_file, text_color=(
        255, 255, 255), bg_color=(0, 0, 0, 0))
