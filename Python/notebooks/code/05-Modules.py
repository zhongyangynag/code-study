# -*- coding: utf-8 -*-
# ---
# jupyter:
#   jupytext:
#     cell_metadata_json: true
#     comment_magics: false
#     formats: py:light,notebooks//ipynb
#     text_representation:
#       extension: .py
#       format_name: light
#       format_version: '1.5'
#       jupytext_version: 1.6.0
#   kernelspec:
#     display_name: Python 3
#     language: python
#     name: python3
# ---

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# # Modules
#
# If your Python program gets longer, you may want to split it into several files for easier maintenance. To support this, Python has a way to put definitions in a file and use them in a script or in an interactive instance of the interpreter. Such a file is called a module.

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# Run the cell below to create a file named fibo.py with several functions inside:

# + {"slideshow": {"slide_type": "slide"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:31.963243Z", "iopub.execute_input": "2020-09-12T13:29:31.964404Z", "iopub.status.idle": "2020-09-12T13:29:31.967533Z", "shell.execute_reply": "2020-09-12T13:29:31.968160Z"}}
%%file fibo.py
""" Simple module with
    two functions to compute Fibonacci series """

def fib1(n):
   """ write Fibonacci series up to n """
   a, b = 0, 1
   while b < n:
      print(b, end=', ')
      a, b = b, a+b

def fib2(n):   
    """ return Fibonacci series up to n """
    result = []
    a, b = 0, 1
    while b < n:
        result.append(b)
        a, b = b, a+b
    return result

if __name__ == "__main__":
    import sys
    fib1(int(sys.argv[1]))

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# You can use the function fib by importing fibo which is the name of the file without .py extension.

# + {"slideshow": {"slide_type": "fragment"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:31.972627Z", "iopub.execute_input": "2020-09-12T13:29:31.973839Z", "iopub.status.idle": "2020-09-12T13:29:31.978991Z", "shell.execute_reply": "2020-09-12T13:29:31.978327Z"}}
import fibo
print(fibo.__name__)
print(fibo.__file__)
fibo.fib1(1000)

# + {"execution": {"iopub.status.busy": "2020-09-12T13:29:31.983810Z", "iopub.execute_input": "2020-09-12T13:29:31.985343Z", "iopub.status.idle": "2020-09-12T13:29:31.990318Z", "shell.execute_reply": "2020-09-12T13:29:31.989653Z"}}
%run fibo.py 1000

# + {"slideshow": {"slide_type": "slide"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:31.995175Z", "iopub.execute_input": "2020-09-12T13:29:31.996128Z", "iopub.status.idle": "2020-09-12T13:29:31.998886Z", "shell.execute_reply": "2020-09-12T13:29:31.999551Z"}}
help(fibo)

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# ## Executing modules as scripts
#
# When you run a Python module with
# ```bash
# $ python fibo.py <arguments>
# ```
# the code in the module will be executed, just as if you imported it, but with the __name__ set to "__main__". The following code will be executed only in this case and not when it is imported.
# ```python
# if __name__ == "__main__":
#     import sys
#     fib(int(sys.argv[1]))
# ```
# In Jupyter notebook, you can run the fibo.py python script using magic command.

# + {"slideshow": {"slide_type": "slide"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.005047Z", "iopub.execute_input": "2020-09-12T13:29:32.006164Z", "iopub.status.idle": "2020-09-12T13:29:32.009821Z", "shell.execute_reply": "2020-09-12T13:29:32.010715Z"}}
%run fibo.py 1000

# + [markdown] {"slideshow": {"slide_type": "fragment"}}
# The module is also imported.

# + {"slideshow": {"slide_type": "fragment"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.016819Z", "iopub.execute_input": "2020-09-12T13:29:32.017788Z", "iopub.status.idle": "2020-09-12T13:29:32.020332Z", "shell.execute_reply": "2020-09-12T13:29:32.020947Z"}}
fib1(1000)

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# ## Different ways to import a module
# ```python
# import fibo
# import fibo as f
# from fibo import fib1, fib2
# from fibo import *
# ```

# + [markdown] {"slideshow": {"slide_type": "fragment"}}
# - Last command with '*' imports all names except those beginning with an underscore (_). In most cases, do not use this facility since it introduces an unknown set of names into the interpreter, possibly hiding some things you have already defined.

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# - If a function with same name is present in different modules imported. Last module function imported replace the previous one.

# + {"slideshow": {"slide_type": "fragment"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.025313Z", "iopub.execute_input": "2020-09-12T13:29:32.026261Z", "iopub.status.idle": "2020-09-12T13:29:32.179026Z", "shell.execute_reply": "2020-09-12T13:29:32.179636Z"}}
from numpy import sqrt
from scipy import sqrt
sqrt(-1)

# + {"slideshow": {"slide_type": "fragment"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.184726Z", "iopub.execute_input": "2020-09-12T13:29:32.185794Z", "iopub.status.idle": "2020-09-12T13:29:32.189313Z", "shell.execute_reply": "2020-09-12T13:29:32.189893Z"}}
from scipy import sqrt
from numpy import sqrt
sqrt(-1)

# + {"slideshow": {"slide_type": "slide"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.194542Z", "iopub.execute_input": "2020-09-12T13:29:32.195587Z", "iopub.status.idle": "2020-09-12T13:29:32.199684Z", "shell.execute_reply": "2020-09-12T13:29:32.199040Z"}}
import numpy as np
import scipy as sp

print(np.sqrt(-1+0j), sp.sqrt(-1))

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# - For efficiency reasons, each module is only imported once per interpreter session. Therefore, if you change your modules, you must restart the interpreter 
# ??? If you really want to test interactively after a long run, use :
# ```python
# import importlib
# importlib.reload(modulename)
# ```

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# ## The Module Search Path
#
# When a module is imported, the interpreter searches for a file named module.py in a list of directories given by the variable sys.path.
# - Python programs can modify sys.path
# - export the PYTHONPATH environment variable to change it on your system.

# + {"slideshow": {"slide_type": "fragment"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.204098Z", "iopub.execute_input": "2020-09-12T13:29:32.205177Z", "iopub.status.idle": "2020-09-12T13:29:32.207852Z", "shell.execute_reply": "2020-09-12T13:29:32.208467Z"}}
import sys
sys.path

# + {"slideshow": {"slide_type": "slide"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.212786Z", "iopub.execute_input": "2020-09-12T13:29:32.213743Z", "iopub.status.idle": "2020-09-12T13:29:32.216521Z", "shell.execute_reply": "2020-09-12T13:29:32.217111Z"}}
import collections
collections.__path__

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# `sys.path` is a list and you can append some directories:

# + {"execution": {"iopub.status.busy": "2020-09-12T13:29:32.221298Z", "iopub.execute_input": "2020-09-12T13:29:32.222227Z", "iopub.status.idle": "2020-09-12T13:29:32.224691Z", "shell.execute_reply": "2020-09-12T13:29:32.225273Z"}}
sys.path.append("/Users/navaro/python-notebooks/")
print(sys.path)

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# When you import a module `foo`, following files are searched in this order:
#
# - **foo.dll**, **foo.dylib** or **foo.so**
# - **foo.py**
# - **foo.pyc**
# - **foo/\_\_init__.py**
#

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# ## Packages
#
# - A package is a directory containing Python module files.
# - This directory always contains a file name \_\_init\_\_.py

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# <pre>
# sklearn
# ????????? base.py
# ????????? calibration.py
# ????????? cluster
# ??????? ????????? __init__.py
# ??????? ????????? _kmeans.py
# ??????? ????????? _mean_shift.py
# ????????? ensemble
# ??????? ????????? __init__.py
# ??????? ????????? _bagging.py
# ??????? ????????? _forest.py
# </pre>
#
# cluster `__init__.py`
#
# <pre>
# from ._mean_shift import mean_shift, MeanShift
# from ._kmeans import k_means, KMeans, MiniBatchKMeans
# </pre>

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# ## Relative imports
#
# These imports use leading dots to indicate the current and parent packages involved in the relative import. In the sugiton module, you can use:
# ```python
# from . import cluster # import module in the same directory
# from .. import base   # import module in parent directory
# from ..ensemble import _forest # import module in another subdirectory of the parent directory
# ```

# + [markdown] {"slideshow": {"slide_type": "slide"}}
# ## Reminder
#
# Don't forget that importing * is not recommended

# + {"slideshow": {"slide_type": "fragment"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.229868Z", "iopub.execute_input": "2020-09-12T13:29:32.230907Z", "iopub.status.idle": "2020-09-12T13:29:32.233262Z", "shell.execute_reply": "2020-09-12T13:29:32.233875Z"}}
sum(range(5),-1)

# + {"slideshow": {"slide_type": "fragment"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.240382Z", "iopub.execute_input": "2020-09-12T13:29:32.241342Z", "iopub.status.idle": "2020-09-12T13:29:32.243778Z", "shell.execute_reply": "2020-09-12T13:29:32.244478Z"}}
from numpy import *
sum(range(5),-1)

# + {"slideshow": {"slide_type": "slide"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.249481Z", "iopub.execute_input": "2020-09-12T13:29:32.250399Z", "iopub.status.idle": "2020-09-12T13:29:32.253014Z", "shell.execute_reply": "2020-09-12T13:29:32.253616Z"}}
del sum # delete imported sum function from numpy 
help(sum)

# + {"slideshow": {"slide_type": "slide"}, "execution": {"iopub.status.busy": "2020-09-12T13:29:32.258118Z", "iopub.execute_input": "2020-09-12T13:29:32.259095Z", "iopub.status.idle": "2020-09-12T13:29:32.261731Z", "shell.execute_reply": "2020-09-12T13:29:32.262316Z"}}
import numpy as np
help(np.sum)
