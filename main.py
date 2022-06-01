from conf import *
import os

if not CONF_USER:
    user = os.getlogin()
else:
    user = CONF_USER
desktop_directory = '/home/'+user+'/Desktop/'

if not os.access(desktop_directory, os.F_OK):
    print('File path does not exists.')

with open(desktop_directory + 'note.md', 'w+') as f:
    f.writelines('# rename this note to invalidate it from script')

