from distutils.core import setup, Extension

module = Extension("_cgraph", sources=[],)

setup(name = "cgraph", version = "0.0.0", author="liurunzhan", description = "A C library for graph and mathematical analysis", ext_modules = module, py_modules = ["cgraph"])