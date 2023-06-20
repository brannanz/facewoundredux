from PIL import Image
import os
from tqdm import tqdm

def tga_to_bmp(tga_dir):
    tga_files = []
    for root, dirs, files in os.walk(tga_dir):
        for filename in files:
            if filename.endswith(".tga"):
                tga_files.append(os.path.join(root, filename))

    for tga_path in tqdm(tga_files):
        bmp_path = tga_path.replace(".tga", ".bmp")
        with Image.open(tga_path) as im:
            im.save(bmp_path)

tga_to_bmp(r"d:\Git\app\facewoundredux\fwound\textures")