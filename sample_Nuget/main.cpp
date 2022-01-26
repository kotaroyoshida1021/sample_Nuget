#include<iostream>
#include<GL/glut.h>

#define MAXPOINTS 100
GLint point[MAXPOINTS][2];
int pointnum = 0;
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	if (pointnum > 1) {
		glColor3d(0.0, 0., 0.);
		glBegin(GL_LINES);
		for (int i = 0; i < pointnum; i++) {
			glVertex2iv(point[i]);
		}
		glEnd();
	}
	glFlush();
}

void initDisplay(void) {
	glClearColor(0.0, 0., 1., 1.);
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glLoadIdentity();
	//glOrtho(-w / 200., w / 200., -h / 200.0, h / 200.0,-1.0,1.0);
	glOrtho(-0.5, (GLdouble)w - 0.5, (GLdouble)h - 0.5, -0.5, -1.0, 1.0);
}

void mouse(int button, int state, int x, int y) {
	static int x0, y0;
	switch (button)
	{
	case GLUT_LEFT_BUTTON://左クリック
		point[pointnum][0] = x;
		point[pointnum][1] = y;
		if (state == GLUT_UP) {
			glColor3d(0.0, 0.0, 0.0);
			glBegin(GL_LINES);
			glVertex2iv(point[pointnum-1]);
			glVertex2iv(point[pointnum]);
			glEnd();
			glFlush();
		}
		else {
		}
		if (pointnum < MAXPOINTS - 1) pointnum++;
		break;
	case GLUT_RIGHT_BUTTON://右クリック
		break;
	case GLUT_MIDDLE_BUTTON:
		break;
	default:
		break;
	}
	
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