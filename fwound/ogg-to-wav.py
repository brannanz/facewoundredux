import os
from pydub import AudioSegment

def ogg_to_wav(ogg_dir):
    for root, dirs, files in os.walk(ogg_dir):
        for filename in files:
            if filename.endswith(".ogg"):
                ogg_path = os.path.join(root, filename)
                wav_path = ogg_path.replace(".ogg", ".wav")
                sound = AudioSegment.from_ogg(ogg_path)
                sound.export(wav_path, format="wav")

ogg_to_wav(r"d:\Git\app\facewoundredux\fwound\sound")