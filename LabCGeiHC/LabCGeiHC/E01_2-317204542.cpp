#include <stdio.h>
#include <string.h>
#include <glew.h>
#include <glfw3.h>

//Agregamos las bibliotecas para el uso de rand() y Sleep()
#include <iostream>
#include <time.h>
#include <Windows.h>

//Dimensiones de la ventana
const int WIDTH = 600, HEIGHT = 600;
float rojo=0.0f, verde=0.0f, azul=0.0f, numAle=0.0f;
GLuint VAO, VBO, shader;  //Variables de tipo entero en OpenGL

//recibir color, salida Vcolor
static const char* vShader = "						\n\
#version 330										\n\
layout (location =0) in vec3 pos;					\n\
void main()											\n\
{													\n\
gl_Position=vec4(pos.x,pos.y,pos.z,1.0f); 			\n\
}";

//FRAGMENT SHADER (Procesa toda la informaion de color y texturizado)
//recibir Vcolor y dar de salida color
static const char* fShader = "						\n\
#version 330										\n\
out vec4 color;										\n\
void main()											\n\
{													\n\
	color = vec4(1.0f,0.0f,0.0f,1.0f);	 			\n\
}";



void CrearTriangulo()
{
	//Arreglo de flotantes
	GLfloat vertices[] = {
		//Datos de vertices, siempre importa el acomodo
		
		
		
		//EJERCICIO 2
		//Se ocuparan 4 triangulos para la generacion de estas figuras (cudrado y rombo)
		//Triangulo 1/2
		-0.2f, 0.3f,0.0f, //x,y,z
		-0.8f, 0.3f, 0.0f,
		-0.8f, -0.3f,0.0f,
		//Triangulo 2/2
		-0.2f, 0.3f,0.0f,
		-0.2f, -0.3f,0.0f,
		-0.8f, -0.3f, 0.0f,
		//Rombo 1/2
		0.2f,0.0f,0.0f,
		0.5f,0.3f,0.0f,
		0.8f,0.0f,0.0f,
		//Rombo 2/2
		0.2f,0.0f,0.0f,
		0.5f,-0.3f,0.0f,
		0.8f,0.0f,0.0f
		

		/*
		//EJERERCIO PRACTICA
		//Para la letra A se ocuparan 12 triangulos
		//Triangulo A1
		-0.7f,0.0f,0.0f,
		-0.7f,-0.3f,0.0f,
		-0.6f,-0.3f,0.0f,
		//Triangulo A2
		-0.7f,0.0f,0.0f,
		-0.6f,0.0f,0.0f,
		-0.6f,-0.3f,0.0f,
		//Triangulo A3
		-0.4f,0.0f,0.0f,
		-0.3f,0.0f,0.0f,
		-0.4f,-0.3f,0.0f,
		//Triangulo A4
		-0.3f,0.0f,0.0f,
		-0.3f,-0.3f,0.0f,
		-0.4f,-0.3f,0.0f,
		//Triangulo A5
		-0.7f,0.0f,0.0f,
		-0.7f,0.1f,0.0f,
		-0.3f,0.0f,0.0f,
		//Triangulo A6
		-0.7f,0.1f,0.0f,
		-0.3f,0.0f,0.0f,
		-0.3f,0.1f,0.0f,
		//Triangulo A7
		-0.7f,0.1f,0.0f,
		-0.6f,0.1f,0.0f,
		-0.7f,0.2f,0.0f,
		//Triangulo A8
		-0.6f,0.1f,0.0f,
		-0.7f,0.2f,0.0f,
		-0.5f,0.4f,0.0f,
		//Triangulo A9
		-0.6f,0.1f,0.0f,
		-0.5f,0.3f,0.0f,
		-0.5f,0.4f,0.0f,
		//Triangulo A10
		-0.5f,0.3f,0.0f,
		-0.5f,0.4f,0.0f,
		-0.4f,0.1f,0.0f,
		//Triangulo A11
		-0.4f,0.1f,0.0f,
		-0.3f,0.2f,0.0f,
		-0.5f,0.4f,0.0f,
		//Triangulo A12
		-0.4f,0.1f,0.0f,
		-0.3f,0.1f,0.0f,
		-0.3f,0.2f,0.0f,
		//Triangulo F1
		-0.1f,-0.3f,0.0f,
		-0.2f,-0.3f,0.0f,
		-0.2f,0.4f,0.0f,
		//Triangulo F2
		-0.1f,-0.3f,0.0f,
		-0.2f,0.4f,0.0f,
		-0.1f,0.4f,0.0f,
		//Triangulo F3
		-0.1f,0.0f,0.0f,
		-0.1f,0.1f,0.0f,
		0.1f,0.1f,0.0f,
		//Triangulo F4
		-0.1f,0.0f,0.0f,
		0.1f,0.0f,0.0f,
		0.1f,0.1f,0.0f,
		//Triangulo F5
		-0.1f,0.3f,0.0f,
		0.2f,0.3f,0.0f,
		0.2f,0.4f,0.0f,
		//Triangulo F6
		-0.1f,0.3f,0.0f,
		-0.1f,0.4f,0.0f,
		0.2f,0.4f,0.0f,

		//Triangulo H1
		0.3f,-0.3f,0.0f,
		0.3f,0.4f,0.0f,
		0.4f,0.4f,0.0f,
		//Triangulo H2
		0.3f, -0.3f, 0.0f,
		0.4f, -0.3f, 0.0f,			
		0.4f, 0.4f, 0.0f,
		//Triangulo H3
		0.4f,0.0f,0.0f,
		0.6f,0.0f,0.0f,
		0.6f,0.1f,0.0f,
		//Triangulo H4
		0.4f, 0.0f, 0.0f,
		0.4f, 0.1f, 0.0f,
		0.6f, 0.1f, 0.0f,
		//Triangulo H5
		0.6f, -0.3f, 0.0f,
		0.7f, -0.3f, 0.0f,
		0.6f, 0.4f, 0.0f,
		//Triangulo H6
		0.7f, -0.3f, 0.0f,
		0.6f, 0.4f, 0.0f,
		0.7f, 0.4f, 0.0f,
		*/
	};
	glGenVertexArrays(1, &VAO); //generar 1 VAO
	glBindVertexArray(VAO);//asignar VAO

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) /*Datos del arreglo*/, vertices, GL_STATIC_DRAW); //pasarle los datos al VBO asignando tamano, los datos y en este caso es estático pues no se modificarán los valores

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);//Stride en caso de haber datos de color por ejemplo, es saltar cierta cantidad de datos
		                     //Lee los datos de 3 en 3     (GLvoid se queda en cero ya que aun no hay datos)
		glEnableVertexAttribArray(0);
		//Siempre se debe habilitar
		//agregar valores a vèrtices y luego declarar un nuevo vertexAttribPointer
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

}
void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType) //Función para agregar los shaders a la tarjeta gráfica
//the Program recibe los datos de theShader


{
	GLuint theShader = glCreateShader(shaderType);//theShader es un shader que se crea de acuerdo al tipo de shader: vertex o fragment
	const GLchar* theCode[1];
	theCode[0] = shaderCode;//shaderCode es el texto que se le pasa a theCode
	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);//longitud del texto
	glShaderSource(theShader,1, theCode, codeLength);//Se le asigna al shader el código
	glCompileShader(theShader);//Se comila el shader
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	//verificaciones y prevención de errores
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al compilar el shader %d es: %s \n",shaderType, eLog);
		return;
	}
	glAttachShader(theProgram, theShader);//Si no hubo problemas se asigna el shader a theProgram el cual asigna el código a la tarjeta gráfica
}

void CompileShaders() {
	shader= glCreateProgram(); //se crea un programa
	if (!shader)
	{
		printf("Error creando el shader");
		return;
	}
	AddShader(shader, vShader, GL_VERTEX_SHADER);//Agregar vertex shader
	AddShader(shader, fShader, GL_FRAGMENT_SHADER);//Agregar fragment shader
	//Para terminar de linkear el programa y ver que no tengamos errores
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	glLinkProgram(shader);//se linkean los shaders a la tarjeta gráfica
	 //verificaciones y prevención de errores
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al linkear es: %s \n", eLog);
		return;
	}
	glValidateProgram(shader);
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al validar es: %s \n", eLog);
		return;
	}



}
int main()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1: Hola triangulo ", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	int BufferWidth, BufferHeight;
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas
	//Asignar Viewport
	glViewport(0, 0, BufferWidth, BufferHeight);

 //Crear tríangulo
	CrearTriangulo();
	CompileShaders();


	//Loop mientras no se cierra la ventana
	while (!glfwWindowShouldClose(mainWindow))
	{
		//Recibir eventos del usuario
		glfwPollEvents();

		//Funcion para generar los numeros aleatorios para los colores de la ventana

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
		Sleep(2000);  //Esta funcion ayuda a que se quede el colo durante 2 segundos 

		//Limpiar la ventana
		glClearColor(rojo,verde,azul,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader); //

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 12); //se pueden dibujar puntos, lineas y traingulos
		//glDrawArrays(GL_TRIANGLES,0,72); //se pueden dibujar puntos, lineas y traingulos
		//El valor del ultimo atributo se modifico para que muestre los 12 vertices
		glBindVertexArray(0);
		//Limpiar lo dibujado
		glUseProgram(0);

		glfwSwapBuffers(mainWindow);

	}


	return 0;
}

//Funcion addShader y compileShader siempre se mantienen