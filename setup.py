#!/usr/bin/env python

"""
setup.py file for SWIG Interface
"""

from distutils.core import setup, Extension


interface_module = Extension('_interface',
                           sources=['interface_wrap.cxx', 'Decision.cpp'],
                           )

setup (name = 'interface',
       version = '0.1',
       author      = "pavan shah",
       description = """interface between python and decision object""",
       ext_modules = [interface_module],
       py_modules = ["interface"],
       )
	   