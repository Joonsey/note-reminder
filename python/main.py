from conf import *
import os
import datetime
import shutil

def create_note_md(desktop_directory):
    with open(desktop_directory+ 'note.md', 'w+') as f:
        f.writelines(DEFAULT_TEXT)

def format_time_to_md(time):
    day = str(time.day)
    month = str(time.month)
    if time.month <= 9:
        month = "0"+month
    if time.day <= 9:
        day = "0"+day
    return day + "-" + month + "-"+str(time.year)+".md"

now = datetime.date.today()
def move_file(src, target):

    with open(src+'note.md', 'r') as f:
        line = f.readline()
        if line != DEFAULT_TEXT:
            file_name = format_time_to_md(now) 
            shutil.move(src + 'note.md', target + file_name)
            print("moved: "+src + "note.md " + "to: " + target + file_name)
        else:
            return 1
        
if __name__ == "__main__":
    #create_note_md(DESKTOP_DIR)
    #move_file(DESKTOP_DIR, TARGET_DIR)
    pass

# add more code here smiley-face :)
