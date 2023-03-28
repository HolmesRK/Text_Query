import ctypes

lib = ctypes.cdll.LoadLibrary("./lib/libPackages.so")

path = "./test/example.txt".encode("utf-8")

lib.find_word(path)

