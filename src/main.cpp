#include "glad\glad.h"
#include "GLFW\glfw3.h"
#include <iostream>

class Graphics
{
	public:
		bool InitWindow();
		bool RenderLoop();
		void processInput();
	private:
		int m_height = 1600;
		int m_width = 1600;
		GLFWwindow* m_window {nullptr};
};


void Graphics::processInput()
{
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
}

void framebuffer_size_callback(GLFWwindow* m_window, int width, int height)
{
	std::cout << "Mikita changed the value to " << width << ", " << height << std::endl;
	glViewport(0, 0, width, height);
}

bool Graphics::InitWindow()
{
	
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_width, m_height, "Window Object", NULL, NULL);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(m_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init GLAD" << std::endl;
		return false;
	}
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

	glViewport(0,0,m_width,m_height);
	return true;
}

bool Graphics::RenderLoop()
{
	while (!glfwWindowShouldClose(m_window))
	{
		processInput();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_window);
    	glfwPollEvents();
	}
	glfwTerminate();
	return true;
}


int main(int argc,char* argv[])
{
	Graphics* myGraphics = new Graphics();
	myGraphics->InitWindow();
	myGraphics->RenderLoop();
	return 0;
}
