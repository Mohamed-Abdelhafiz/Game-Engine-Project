#include <glad/glad.h>
#include <glad/glad.c>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm\gtx\string_cast.hpp>
#include <iostream>
#include <learnopengl/shader.h>
#include <learnopengl/camera.h>
#include <learnopengl/model.h>
#include <assimp-model-loader\assimp_model.h>
#include "Classes\Windows\GLFWwindow.h"
#include "Classes\P-Shapes\Primitives.h"
#include <math.h>



using namespace std;

// settings
const unsigned int SCR_WIDTH2 = 1920;
const unsigned int SCR_HEIGHT2 = 1080;


int main()
{
	
	Mywindow* mainWindow = new Mywindow("test", SCR_WIDTH, SCR_HEIGHT);
	
	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//glEnable(GL_CULL_FACE);
	//glEnable(GL_PROGRAM_POINT_SIZE);


	Shader shaderTest("Shaders/TestingVS.vs", "Shaders/TestingFS.fs");
	
	
	Cube cube1("Textures/marble.jpg");
	//Cube cube2("Textures/container.jpg");
	//Cube cube3("Textures/container2.png");
	Quad quad1("Textures/bricks2.jpg");
	Point point1(1);
	Line line1(1);


	//shaderTest.use();
	//shaderTest.setInt("model_texture", 0);
	
	
	// render loop
	// -----------
	while (!glfwWindowShouldClose(mainWindow->window))
	{
		// per-frame time logic
		// --------------------
		mainWindow->calculateTime();

		// input
		mainWindow->processInput();
		

		// render
		// ------
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
			
		shaderTest.use();
		glm::mat4 model;
		shaderTest.setMat4("model", model);
		glm::mat4 view = camera.GetViewMatrix();
		shaderTest.setMat4("view", view);
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH2 / (float)SCR_HEIGHT2, 0.01f, 1000.0f);
		shaderTest.setMat4("projection", projection);

		model = glm::mat4();
		model = glm::translate(model, glm::vec3(0.0f,0.0f,0.0f));
		cube1.perspective_Trans(&camera, model);
		cube1.renderCube(glm::vec3(1.0f, 0.0f, 0.0f));
		//cube1.renderCube();
		model = glm::mat4();

		model = glm::translate(model, glm::vec3(1.9f, 0.0f, 0.0f));
		//cube2.perspective_Trans(&camera, model);
		//cube2.renderCube(glm::vec3(0.0f, 1.0f, 0.0f));
		//cube2.renderCube();
		model = glm::mat4();
		
		model = glm::translate(model, glm::vec3(-1.9f, 0.0f, 0.0f));
		//cube3.perspective_Trans(&camera, model);
		//cube3.renderCube();
		model = glm::mat4();

		//model = glm::scale(model, glm::vec3(200.0, 1.0, 200.0));
		model = glm::translate(model, glm::vec3(0.0, 1.2, 0.0));
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
		quad1.perspective_Trans(&camera, model);
		quad1.renderQuad();
		model = glm::mat4();

		model = glm::translate(model, glm::vec3(0.0, 1.0, 0.0));
		point1.perspective_Trans(&camera, model);
		point1.renderPoint(glm::vec3(1.0, 0.0, 0.0), 50);
		model = glm::mat4();

		model = glm::translate(model, glm::vec3(0.0, 0.5, 4.0));
		line1.perspective_Trans(&camera, model);
		line1.renderLine(glm::vec3(0.0, 0.0, 0.6));
		
		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(mainWindow->window);
		glfwPollEvents();
	}
	cube1.freeCube();
	//cube2.freeCube();
	quad1.freeQuad();
	point1.freePoint();
	line1.freeLine();
	glfwTerminate();
	return 0;
}

