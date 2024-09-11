all: debug

debug: project
	cmake --build build --config debug -j4

project: CMakeLists.txt
	cmake -B build -G "Ninja" -DCMAKE_CXX_COMPILER=clang -DCMAKE_C_COMPILER=clang
