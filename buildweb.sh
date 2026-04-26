emcc -o game.html main.cpp davengine.cpp src/Object.cpp src/Modifier.cpp src/modifiers/Objprops.cpp src/modifiers/Sprite.cpp src/modifiers/CircleCollision.cpp src/modifiers/RectCollision.cpp src/modifiers/Collision.cpp src/modifiers/Container.cpp src/modifiers/ContainerConstraintor.cpp src/modifiers/Text.cpp -Os -Wall -L"./lib" ./lib/librayweblib.a -L"./lib" -I. -I./include/ -I./include/modifiers/ -L./lib/librayweblib.a -L. -s USE_GLFW=3 -s ASYNCIFY --preload-file res/ --shell-file ~/cdev/raylib/src/minshell.html -DPLATFORM_WEB -DDAV_WEB

rm -rf webbuild
mkdir webbuild

mv game.js webbuild
mv game.wasm webbuild
mv game.html webbuild
mv game.data webbuild
mv game.mem webbuild
