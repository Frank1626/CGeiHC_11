#include <stdio.h>
#include <glew.h>
#include <glfw3.h>

//Agregamos las bibliotecas para el uso de rand() y Sleep()
#include <iostream>
#include <Windows.h>

//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;   //Tamaño de la ventana en pixeles
float rojo = 0.0f, verde = 0.0f, azul = 0.0f, numAle = 0.0f;

int main()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");  //si no se inicializa manda este error debido a que no estan los archivos
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  //version 4
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  //version .3
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  //Esta relacionado con la version de OpenGl 3.3+ (Modern OpenGL)
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1", NULL, NULL);
	//Contenedor de tamaño, de nombre, ultimas dos se usan NULL, NULL (si tenemos +1 monitor, se dibujara en ambas)  

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");  //No se crea la ventana
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	int BufferWidth, BufferHeight;  //Estos valores recibiran de memoria 800x600 pixeles, guarda los valores de la ventana
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight); //Se asignan los valores del cache

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow); //Siempre se declara cual es la ventana activa, ya que podemos dibujar mas de 1 ventana

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE; //Es recomenada para nuevas funciones experimentales

	if (glewInit() != GLEW_OK) //Libreria en conjunto con OpenGL para optimizacion, glew y glad
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas
	//Asignar Viewport
	//OpenGL
	glViewport(0, 0, BufferWidth, BufferHeight); //Sirve para acomodar el punto 0,0 en el espacio y de  ahi crear un espacio dibujar de cierta cantidad de pixeles
	//Prints de consola
	printf("Version de Opengl: %s \n",glGetString(GL_VERSION));
	printf("Marca: %s \n", glGetString(GL_VENDOR));
	printf("Renderer: %s \n", glGetString(GL_RENDERER));
	printf("Shaders: %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	//Loop mientras no se cierra la ventana
	while (!glfwWindowShouldClose(mainWindow)) //Recibe la inormacion de teclado y mouse 
		//Lo anterior al presionar la X de la ventana pasa a ser true y elimina la ventana
	{
		//Recibir eventos del usuario
		glfwPollEvents(); //Esta linea debe conservarse como buena practica

		//Limpiar la ventana

		numAle = rand() % 3 + 1;   //Genera un numero aleatorio entre 1 y 3 
		//Dependiendo del caso se le asignaran valores a las variables     
		if (numAle == 1) {
			rojo = 1.0;
			verde = 0.0;
			azul = 0.0;
		}
		else if (numAle == 2) {
			rojo = 0.0;
			verde = 1.0;
			azul = 0.0;
		}
		else if (numAle == 3) {
			rojo = 0.0;
			verde = 0.0;
			azul = 1.0;
		}
		Sleep(3000);  //Esta funcion ayuda a que se quede el colo durante 2 segundos

		printf("El valor del numero aletorio es: %f \n", numAle);
		
		glClearColor(rojo,verde,azul,1.0f); //valores rojo, verde,azul, alpha  (RGB) (Alpha texturizado e ilumniacion, cambia su valor por uno mayor o menos a 0)
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow); //Sirve al tener 2 buffer, uno muestra en  pantalla y el segundo rinderiza
		//No declarar codigo despues de este punto!! 
	}

	glfwDestroyWindow(mainWindow);

	return 0;
}