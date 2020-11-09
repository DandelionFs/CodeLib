import serial
import time
import os


def at(port, cmd):
    """执行 AT 命令返回结果"""
    port.write(cmd.encode(encoding='ascii') + b'\r')
    time.sleep(1)
    lines = []
    while port.in_waiting > 0:
        result = port.read(port.in_waiting)
        if result != b'':
            result = result.decode(encoding='ascii')
            lines += [l for l in result.split('\r\n') if l != '']
        else:
            break
    return lines

def upload_file(port, file_path):
    """上传音频文件到 SIM800"""
    # 先检查文件存在不存在，存在了就跳过
    file_name = os.path.basename(file_path)
    result = at(port, 'AT+FSLS=C:\\')
    if file_name in result:
        return
    with open(file_path, 'rb') as src:
        file_content = src.read()
        file_size = len(file_content)
        print('Creating audio file...')
        result = at(port, 'AT+FSCREATE={0}'.format(file_name))
        if (not result) or (result[0] != 'OK'):
            print('RESULT=', result)
            raise IOError('Failed to create file')
        print('Writing audio file [filename={0}, size={1}] ...'.format(file_name, file_size))
        at_cmd = 'AT+FSWRITE={0},0,{1},10'.format(file_name, file_size)
        print(at_cmd)
        result = at(port, at_cmd)
        print('>>>>>>>>>>>>>>>>>>>', result)
        if result and result[0] == '>': 
            print('Uploading file content...')
            port.write(file_content)
            print('File content uploaded')
        else:
            raise IOError('Failed to write file content')

COM_PORT = '/dev/ttyAMA0'

# 打开串口
with serial.Serial(COM_PORT, baudrate=115200, timeout=5) as port:

    if port.isOpen():
        print(port.name + ' is open...!!!')

    result = at(port, 'ATE0') # 关闭回显，同时测试连接情况
    if result[0] != 'OK':
        print('Failed to execute ATE0, check connection please.')
    print('>>>', result)

    upload_file(port, './to_play.amr')
    print('-----------------------------')
    print(at(port, 'AT+FSLS=C:\\')) # 检查是否上传成功

    print(at(port, 'AT+COLP=1'))

    print(at(port, 'ATD139XXXXXXXX;'))  # 139XXXXXXX 改成要拨打的手机号

    # 等待对方摘机
    while True:
        result = port.read(port.in_waiting)
        if result != b'':
            lines = result.decode(encoding='ascii')
            print('ATD>', lines)
            break

    time.sleep(1)
    at(port, 'AT+CREC=4,"C:\\to_play.amr",0,90')

    print('All done.')

# EP008-Demo
#树莓派连接 SIM800C 开发板 Python 演示脚本
#MIT License
#
#Copyright (c) 2020 老革命
#
#Permission is hereby granted, free of charge, to any person obtaining a copy
#of this software and associated documentation files (the "Software"), to deal
#in the Software without restriction, including without limitation the rights
#to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#copies of the Software, and to permit persons to whom the Software is
#furnished to do so, subject to the following conditions:
#
#The above copyright notice and this permission notice shall be included in all
#copies or substantial portions of the Software.
#
#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#SOFTWARE.



# INNORE
# Byte-compiled / optimized / DLL files
#__pycache__/
#*.py[cod]
#*$py.class

# C extensions
#*.so

# Distribution / packaging
#.Python
#build/
#develop-eggs/
#dist/
#downloads/
#eggs/
#.eggs/
#lib/
#lib64/
#parts/
#sdist/
#var/
#wheels/
#pip-wheel-metadata/
#share/python-wheels/
#*.egg-info/
#.installed.cfg
#*.egg
#MANIFEST

# PyInstaller
#  Usually these files are written by a python script from a template
#  before PyInstaller builds the exe, so as to inject date/other infos into it.
#*.manifest
#*.spec

# Installer logs
#pip-log.txt
#pip-delete-this-directory.txt

# Unit test / coverage reports
#htmlcov/
#.tox/
#.nox/
#.coverage
#.coverage.*
#.cache
#nosetests.xml
#coverage.xml
#*.cover
#*.py,cover
#.hypothesis/
#.pytest_cache/

# Translations
#*.mo
#*.pot

# Django stuff:
#*.log
#local_settings.py
#db.sqlite3
#db.sqlite3-journal

# Flask stuff:
#instance/
#.webassets-cache

# Scrapy stuff:
#.scrapy

# Sphinx documentation
#docs/_build/

# PyBuilder
#target/

# Jupyter Notebook
#.ipynb_checkpoints

# IPython
#profile_default/
#ipython_config.py

# pyenv
#.python-version

# pipenv
#   According to pypa/pipenv#598, it is recommended to include Pipfile.lock in version control.
#   However, in case of collaboration, if having platform-specific dependencies or dependencies
#   having no cross-platform support, pipenv may install dependencies that don't work, or not
#   install all needed dependencies.
#Pipfile.lock

# PEP 582; used by e.g. github.com/David-OConnor/pyflow
#__pypackages__/

# Celery stuff
#celerybeat-schedule
#celerybeat.pid

# SageMath parsed files
#*.sage.py

# Environments
#.env
#.venv
#env/
#venv/
#ENV/
#env.bak/
#venv.bak/

# Spyder project settings
#.spyderproject
#.spyproject

# Rope project settings
#.ropeproject

# mkdocs documentation
#/site

# mypy
#.mypy_cache/
#.dmypy.json
#dmypy.json

# Pyre type checker
#.pyre/
