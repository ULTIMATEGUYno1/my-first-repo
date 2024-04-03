from PIL import Image

# Open the chosen image
image = Image.open("download.jpg")

# Check if the image was successfully loaded
if image.mode != 'RGB':
    print("Error: Image is not in RGB mode.")
    exit(1)

# Define the threshold for typeA pixels
threshold = (160, 160, 160)

# Initialize counters for typeA and typeB pixels
typeA_count = 0
typeB_count = 0

# Define the brightness level
brightness_level = 100

# Convert image to grayscale for brightness calculation
grayscale_image = image.convert("L")

# Create a new image for the black and white version
bw_image = grayscale_image.copy()

# Get pixel data
pixels = image.load()
bw_pixels = bw_image.load()

# Calculate the brightness level
brightness_threshold = brightness_level

# Iterate through each pixel
for y in range(image.height):
    for x in range(image.width):
        # Check if the pixel is typeA or typeB
        if pixels[x, y] > threshold:
            typeA_count += 1
        else:
            typeB_count += 1
        
        # Convert pixel to black or white based on brightness
        brightness = sum(pixels[x, y]) / 3  # Calculate brightness
        if brightness > brightness_threshold:
            bw_pixels[x, y] = 255  # White pixel
        else:
            bw_pixels[x, y] = 0    # Black pixel

# Calculate the percentage of typeA and typeB pixels
total_pixels = image.width * image.height
percentage_typeA = (typeA_count / total_pixels) * 100
percentage_typeB = (typeB_count / total_pixels) * 100

print("Percentage of typeA pixels:", percentage_typeA)
print("Percentage of typeB pixels:", percentage_typeB)

# Display the black and white image
bw_image.show()
