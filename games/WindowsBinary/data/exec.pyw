import subprocess
import ctypes

MessageBox = ctypes.windll.user32.MessageBoxW
MessageBox(None,
"""This game was designed for Gameboy Advance and is being run in the mGBA open-source emulator.
The default button mappings are:

A BUTTON: Z
B BUTTON: X
LEFT TRIGGER:  C
RIGHT TRIGGER: V
D PAD: Arrow Keys
START: Enter
SELECT: Esc

You can change the keyboard mapping in Tools -> Settings -> Keyboard.

Thanks for playing!
- Cinemint""",
'Ahoy there!', 0)
subprocess.run(["mGBA", "Tremblay Island"])