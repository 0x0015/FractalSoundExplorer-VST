#pragma once
#include <iostream>

std::string vert_glsl(){
	return(
"#version 400 compatibility\nuniform vec2 iResolution;\nvoid main() {\n  vec2 pos = (gl_Vertex.xy / iResolution) * 2.0 - vec2(1.0, 1.0);\n  gl_Position = vec4(pos, 0.0, 1.0);\n}"
	      );
}
