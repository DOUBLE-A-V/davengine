import os

defaultArgs = ' -g -O3 -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter '

linuxArgs = ' -L./lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 '
windowsArgs = " --target=x86_64-w64-windows-gnu "

windowsPaths = ' -L"E:/ACDEV/davengine/lib" -I"E:/ACDEV/davengine/include" -I"E:/ACDEV/davengine/include/modifiers" '
linuxPaths = ' -L"./lib" -I"./include" -I"./include/modifiers" '

excludeFromLib = ["src/modifiers/MoveModifier.cpp"]

inputfilesLib = ""
inputfilesLibPaths = ""

inputfiles = "davengine.cpp "
inputfilesPaths = "davengine.cpp "

for file in os.listdir("src"):
    if not os.path.isdir("src/" + file):
        inputfiles += file + " "
        inputfilesPaths += "src/" + file + " "
for file in os.listdir("src/modifiers"):
    inputfiles += file + " "
    inputfilesPaths += "src/modifiers/" + file + " "

inputfilesLib = inputfiles
for e in excludeFromLib:
    inputfilesLib = inputfilesLib.replace(os.path.basename(e), "")
inputfilesLibPaths = inputfilesPaths
for e in excludeFromLib:
    inputfilesLibPaths = inputfilesLibPaths.replace(e, "")

#build.bat
buildbat = "clang++ main.cpp " + inputfilesPaths + "-llibraylibdll -o davengine.exe " + windowsArgs + defaultArgs

#builddll.bat
builddll = "clang++ " + "-std=c++17 -I./include -I./include/modifiers -DDAV_DLL -DDAV_EXPORTS -target x86_64-w64-mingw32 -c " + inputfilesLibPaths
builddll += "\n" + "clang++ -std++17" + inputfilesLib.replace(".cpp", ".o") + "-Wl,--out-implib,davengine.lib -lraylibdll " + defaultArgs

#build.sh
buildsh = "clang++ main.cpp " + inputfilesPaths + linuxPaths + " -o davengine.bin" + defaultArgs + linuxArgs

#buildso.sh
buildso = 'clang++ -fPIC -std=c++17 -I./include -I./include/modifiers -c ' + inputfilesLibPaths
buildso += "\n" + "clang++ " + linuxPaths + '-shared -o davengine.so' + defaultArgs + linuxArgs + inputfilesLib.replace(".cpp", ".o") + linuxPaths

with open("build.bat", "w", encoding='utf-8') as f:
    f.write(buildbat)
with open("builddll.bat", "w", encoding='utf-8') as f:
    f.write(builddll)
with open("build.sh", "w", encoding='utf-8') as f:
    f.write(buildsh)
with open("buildso.sh", "w", encoding='utf-8') as f:
    f.write(buildso)
