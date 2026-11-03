# Atelier

Atelier is a small 3D game engine I'm building to learn how game engines work under the hood.
It's an educational project, so expect things to change, break and get rewritten along the way.

The engine is built step by step through milestones. To keep it grounded, I'm also making a
small platformer game alongside it, which serves as a test bed for every new feature.

Built with C++ and OpenGL.

## Roadmap

### Milestone 0 – Foundations
- [x] CMake project setup
- [x] Dependencies: GLFW, glad, GLM, stb_image
- [ ] Main loop with delta time
- [ ] Basic project structure and `Atelier` namespace

**Demo:** a window that opens and closes cleanly, with the FPS shown in the title bar.

### Milestone 1 – OpenGL abstraction
- [ ] `Window`, `Shader`, `Texture` classes
- [ ] `VertexArray`, `VertexBuffer`, `IndexBuffer` classes (RAII)
- [ ] OpenGL debug output (`glDebugMessageCallback`)
- [ ] Simple logging system

**Demo:** a textured cube rendered without any raw OpenGL calls in the game code.

### Milestone 2 – Camera and input
- [ ] Input system (keyboard and mouse)
- [ ] First-person camera
- [ ] Window resizing (viewport and projection)

**Demo:** moving freely around a scene made of cubes.

### Milestone 3 – Models and resources
- [ ] `Mesh` and `Model` classes
- [ ] Model loading (glTF)
- [ ] Resource manager with caching
- [ ] Basic `Material` class

**Demo:** loading and displaying a real 3D model.

## Platformer

The test game. It will grow as the engine does.

## AI disclosure

This README may be proofread or corrected with the help of an LLM.
All the code in this repository is written by hand.
