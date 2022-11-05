import os, sys
from pathlib import Path


dirbase = os.path.dirname(__file__) + "/"
dirbase = str(Path(dirbase).resolve().parents[0]) + "/"

helpz = """
COMMANDS:
    install
    remove
    prj  [
        build,
        run,
        init,
        setup
    ]
"""

if len(sys.argv) < 2:
    print("missing args use --help")
    exit()

if sys.argv[1] == "help":
    print(helpz)
    exit()
elif sys.argv[1] == "install" and len(sys.argv) >= 3:
    pkgs = sys.argv
    del pkgs[0]
    del pkgs[0]
    for pkg in pkgs:
        url = f"https://raw.githubusercontent.com/UnityTheCoder/vix/main/%40pkgs/{pkg}/{pkg}.vx"
        x = os.system("curl " + url)
        if "404" in str(x) or "Not Found" in str(x):
            print("Package not found!")
            exit()
        os.system(f"python3 {dirbase}src/getsubdir.py UnityTheCoder/vix -p @pkgs/{pkg} -r True")
        os.system(f"sudo mkdir /usr/lib/voxel/libc/{pkg}")
        os.system(f"sudo cp -r {dirbase}vix/* /usr/lib/voxel/libc/{pkg}/")
        os.system("rm -r vix")
        
elif sys.argv[1] == "remove" and len(sys.argv) >= 3:
    pkgs = sys.argv
    del pkgs[0]
    del pkgs[0]
    for pkg in pkgs:
        os.system(f"rm -r /usr/lib/voxel/libc/{pkg}")

elif sys.argv[1] == "prj":
    if len(sys.argv) >= 4:
        pass
