#include <GLFW/glfw3.h>

static bool border = false;
static const float Speed = 0.01f;
static const int screenWRes = 1920;
static const int screenHRes = 1080;
static const float screenWBorder = 0.8f;
static const float screenHBorder = 0.8f;
float ball_x = 0.5, ball_y = 0.0, ball_z = 0.0;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	if (key == GLFW_KEY_A && ball_x > -screenWBorder)
		ball_x -= Speed;
	if (key == GLFW_KEY_D && ball_x < screenWBorder)
		ball_x += Speed;
}

void updatePoring()
{
	if (!border)
	{
		ball_y += Speed;
		if (ball_y > screenHBorder)
			border = true;
	}
	if (border)
	{
		ball_y -= Speed;
		if (ball_y < -screenHBorder)
			border = false;
	}
}


void drawPoring()
{
	
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.6f, 0.6f); // Pink body
	glVertex3f(-0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.2f, 0.0f, 0.0f);
	glVertex3f(0.1f, 0.2f, 0.0f);
	glVertex3f(-0.1f, 0.2f, 0.0f);
	glVertex3f(-0.2f, 0.0f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f); // Black eyes
	glVertex3f(-0.09f, 0.06f, 0.01f);
	glVertex3f(-0.06f, 0.06f, 0.01f);
	glVertex3f(-0.05f, 0.08f, 0.01f);
	glVertex3f(-0.06f, 0.10f, 0.01f);
	glVertex3f(-0.09f, 0.10f, 0.01f);
	glVertex3f(-0.10f, 0.08f, 0.01f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f); // Black eyes
	glVertex3f(0.09f, 0.06f, 0.01f);
	glVertex3f(0.06f, 0.06f, 0.01f);
	glVertex3f(0.05f, 0.08f, 0.01f);
	glVertex3f(0.06f, 0.10f, 0.01f);
	glVertex3f(0.09f, 0.10f, 0.01f);
	glVertex3f(0.10f, 0.08f, 0.01f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f); // Black Mouth
	glVertex3f(0.09f, -0.06f, 0.01f);
	glVertex3f(-0.10f, -0.06f, 0.01f);
	glVertex3f(-0.11f, -0.08f, 0.01f);
	glVertex3f(-0.10f, -0.10f, 0.01f);
	glVertex3f(0.09f, -0.10f, 0.01f);
	glVertex3f(0.10f, -0.08f, 0.01f);
	glEnd();
	
}

int main(void)
{

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	// glfwGetPrimaryMonitor() FullScreen
	window = glfwCreateWindow(screenWRes, screenHRes, "Polygon Poring", glfwGetPrimaryMonitor(), NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glClearColor(0.973f, 1.0f, 0.898f, 0.0f); //Yellow BG

		glPushMatrix();
		glTranslatef(ball_x, ball_y, ball_z);
		drawPoring();
		glPopMatrix();

		updatePoring();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}