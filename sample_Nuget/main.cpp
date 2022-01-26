#include<iostream>
#include<GL/glut.h>

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1., 0., 0.);
	glBegin(GL_QUAD_STRIP);
	glVertex2d(-0.9, -0.9);
	glVertex2d(0.9, -0.9);
	glVertex2d(0.9, 0.9);
	glVertex2d(-0.9, 0.9);
	glEnd();
	glFlush();
}

void initDisplay(void) {
	glClearColor(0.0, 0., 1., 1.);
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-w / 200., w / 200., -h / 200.0, h / 200.0,-1.0,1.0);
}

void mouse(int button, int state, int x, int y) {
	switch (button)
	{
	case GLUT_LEFT_BUTTON://左クリック
		printf("left");
		break;
	case GLUT_RIGHT_BUTTON://右クリック
		printf("right");
		break;
	case GLUT_MIDDLE_BUTTON:
		printf("middle");
		break;
	default:
		break;
	}

	printf("button is ");
	switch (state) {
	case GLUT_UP://押した→離したとき
		printf("up");
		break;
	case GLUT_DOWN://押したとき
		printf("down");
		break;
	default:
		break;
	}

	printf(" at (%d %d) \n", x, y);
}
int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	initDisplay();
	glutMainLoop();
	return 0;
}