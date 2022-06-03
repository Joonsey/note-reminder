import os

# Change this for custom directory paths.
AUTO_CONFIG = True 
DEFAULT_TEXT = "# change this line"

if AUTO_CONFIG:
    DESKTOP_DIR = '/home/'+os.getlogin()+'/Desktop/'
    TARGET_DIR = '/home/'+os.getlogin()+'/Documents/.notes/'

    if not os.access(DESKTOP_DIR, os.W_OK):
        raise('No write access in: ' + DESKTOP_DIR)

    if not os.access(TARGET_DIR, os.W_OK):
        raise('No write access in: ' + TARGET_DIR)

