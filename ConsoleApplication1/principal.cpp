//LIBRERIAS
#include "librerias.h"

//METODOS
void framebuffer_resize_callback(GLFWwindow* window, int fbw, int fbh);

int main()
{

	// INICIALIZANDO GLFW
	glfwInit();

	//CONFIGURACION VENTANA
	const int WINDOW_WIDTH = 600;
	const int WINDOW_HEIGHT = 600;
	int framebufferwidth = 0;
	int framebufferheight = 0;


	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MAC OS



	///CREAR VENTANA Y CONTECTO OPENGL
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Ventana", NULL, NULL);

	glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
	//glfwGetFramebufferSize(window, &framebufferwidth, &framebufferheight);
	//glViewport(0, 0,framebufferwidth, framebufferheight);


	glfwMakeContextCurrent(window); 

	// INICIALIZAR GLEW
	glewExperimental =GL_TRUE; 
	//ERROR
	if (glewInit() != GLEW_OK) {
		cout << "ERROR AL INICIAR GLEW";
		glfwTerminate();
	}
	
	//CICLO PRINCIPAL
	while(!glfwWindowShouldClose(window)) {

		//ACTUALIZAR ENTRADAS
		glfwPollEvents();
		//ACTUALIZAR

		//PINTAR
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
		//LIMPIAR

		//PINTAR

		//FINALIZAR PINTADO
		glfwSwapBuffers(window);
		glFlush();

	}

	glfwTerminate();
	return 0;
}


void framebuffer_resize_callback(GLFWwindow* window ,int fbw,int fbh) {
	glViewport(0, 0, fbw, fbh);
}