#include "camera.hpp"  // cameras.hpp já inclue o arquivo depedencies.hpp
#include "colors.hpp"
#include "draw.hpp"

unsigned int cuboID[3];
Camera camera(vec3(-10, 0, 0));

void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	else if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		camera.forward();
	}
	else if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		camera.back();
	}
	else if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		camera.right();
	}
	else if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		camera.left();
	}
}

void init(GLFWwindow* window)
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetKeyCallback(window, keyboard_callback);

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);

	cuboID[0] = glGenLists(3);
	drawcube(cuboID[0], 10.0);
}

int main(void)
{
	const int LARGURA = 800;
	const int ALTURA = 600;
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(LARGURA, ALTURA, "Trabalho_03-Comp_Grafica", NULL, NULL);
	glfwMakeContextCurrent(window);
	init(window);
	float valor = 0.0;
	float lastTime = 0.0;
	float FPS = 60.0;

	while (!glfwWindowShouldClose(window))
	{
		float now;
		float dt;
		do {
			now = (float)glfwGetTime();
			dt = now - lastTime;

		} while (dt < 1.0 / FPS);
		lastTime = now;

		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		int largura, altura;
		glfwGetFramebufferSize(window, &largura, &altura);
		resize(largura, altura);
		draw(camera,cuboID);
		glfwSwapBuffers(window);
	}
	glDeleteLists(cuboID[0], 3);
	glfwTerminate();
	return 0;
}