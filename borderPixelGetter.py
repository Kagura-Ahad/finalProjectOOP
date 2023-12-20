from PIL import Image

# Load the image
image = Image.open("finalSprite.png")

# Define block dimensions
block_width = 60
block_height = 60

# Function to get the border pixels of non-transparent regions within a block
def get_border_pixels(img, x_start, y_start, width, height):
    border_pixels = []
    for y in range(y_start, y_start + height):
        for x in range(x_start, x_start + width):
            pixel = img.getpixel((x, y))
            if pixel[3] != 0:  # Checking the alpha channel for transparency
                # Check if the pixel is at the border and within image boundaries
                if (
                    x > 0 and img.getpixel((x - 1, y))[3] == 0
                    or x < img.width - 1 and img.getpixel((x + 1, y))[3] == 0
                    or y > 0 and img.getpixel((x, y - 1))[3] == 0
                    or y < img.height - 1 and img.getpixel((x, y + 1))[3] == 0
                ):
                    # Adjust the coordinates relative to the top-left corner of the block
                    border_pixels.append((x - x_start, y - y_start))
    return border_pixels

# Create or open a text file to write the transformed border pixels
with open('transformed_border_pixels.txt', 'w') as file:
    # Iterate through blocks and get transformed border pixels
    for row in range(0, 3):
        for col in range(0, 3):
            block_name = f"block_{row}_{col}"
            x_start = col * block_width
            y_start = row * block_height
            border_pixels = get_border_pixels(image, x_start, y_start, block_width, block_height)
            
            # Write block name, length of border pixels list, and its transformed border pixels to the file
            file.write(f"{block_name}: Length - {len(border_pixels)}, Border Pixels - {border_pixels}\n")
