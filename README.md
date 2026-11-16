# Atelier

Atelier is a small 3D game engine I'm building to learn how game engines work under the hood.
It's an educational project, so expect things to change, break and get rewritten along the way.

The engine is built step by step through milestones. To keep it grounded, I'm also making a
small platformer game alongside it, which serves as a test bed for every new feature.

Built with modern C++ (C++17) and OpenGL.

## Roadmap

### Milestone 0 – Foundations

- [x] CMake project setup
- [x] Dependencies: GLFW, glad, GLM, stb_image
- [x] Main loop with delta time
- [x] Basic project structure and `Atelier` namespace

**Demo:** a window that opens and closes cleanly, with the FPS shown in the title bar.

### Milestone 1 – OpenGL abstraction

- [x] `Window`, `Shader`, `Texture` classes
- [x] `VertexArray`, `VertexBuffer`, `IndexBuffer` classes (RAII)
- [ ] OpenGL debug output (`glDebugMessageCallback`)
- [x] Simple logging system

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

### Milestone 4 – Lighting

- [ ] Phong / Blinn-Phong lighting
- [ ] Directional, point and spot lights
- [ ] Normal and specular maps
- [ ] Shadow mapping for the directional light

**Demo:** a lit scene with moving lights and real-time shadows.

### Milestone 5 – Scene and gameplay

- [ ] Scene graph with transform hierarchy
- [ ] Entity / component system
- [ ] AABB collision detection
- [ ] Basic character controller (gravity, jumping)

**Demo:** a first playable platformer level with a jumping character.

## Platformer

The test game. It will grow as the engine does.

## AI disclosure

This README may be proofread or corrected with the help of an LLM.
All the code in this repository is written by hand.
