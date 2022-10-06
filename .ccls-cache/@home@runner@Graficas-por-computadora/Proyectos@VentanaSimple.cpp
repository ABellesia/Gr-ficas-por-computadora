#include <GLFW/glfw3.h> 
#include <stdio.h>
#include <iostream>
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
		printf("tecla r\n");
}
int main()
{
	glfwInit(); //inicializa glfw y vamos a la version 3.3 --> es porque el cambio 
	//no acepta después de 3.3 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //modo estricto sin compatibiidad hacia atrás
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Ejemplo glfw",
		NULL, NULL); //crea una ventana (la pone donde sea con el tamaño definido
	//si llamas a una función, regresa un apuntador a la ventana
	if (window == NULL) { //si es null implica que no creó la ventana
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate(); //termina el processo
		return -1; //lo regresa al sistema operativo --> los negativos significan que algo salió mal
	}
	glfwMakeContextCurrent(window); //crea el contexto = máquna de OpenGL de estado infinito 
	//todo lo que haga se aplica a esa ventana
	while (!glfwWindowShouldClose(window))
	{
		processInput(window); //procesa la entrada 
		// Dibujar algo
		glfwWaitEvents();
	}
	glfwTerminate();
	return 0;
}