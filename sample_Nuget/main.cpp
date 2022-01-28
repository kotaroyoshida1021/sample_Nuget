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

void display2(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glRotated(25.0, 0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glColor3d(1.0, 0.0, 0.0); /* 赤 */
	glVertex2d(-0.9, -0.9);
	glColor3d(0.0, 1.0, 0.0); /* 緑 */
	glVertex2d(0.9, -0.9);
	glColor3d(0.0, 0.0, 1.0); /* 青 */
	glVertex2d(0.9, 0.9);
	glColor3d(1.0, 1.0, 0.0); /* 黄 */
	glVertex2d(-0.9, 0.9);
	glEnd();
	glFlush();
}

void initDisplay(void) {
	glClearColor(0.0, 0., 1., 1.);
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-w / 200., w / 200., -h / 200.0, h / 200.0,-1.0,1.0);
	//glOrtho(-0.5, (GLdouble)w - 0.5, (GLdouble)h - 0.5, -0.5, -1.0, 1.0);
	//glOrtho(-2., 2., -2., -2., -2.0, 2.0);
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
	//glTranslated(0.0, 0.0, -5.0);
	//gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
}
void idle(void);
void mouse(int button, int state, int x, int y) {
	static int x0, y0;
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			glutIdleFunc(idle);
		}
		else {
			glutIdleFunc(0);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}
	
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'q':
	case 'Q':
	case '\033':
		exit(0);
	default:
		break;
	}
}
//3D shape
GLdouble vertex[][3] = {
	{0.,0.,0.},
	{1.,0.0,0.},
	{1.,1.,0.},
	{ 0.0, 1.0, 0.0 }, /* D */
  { 0.0, 0.0, 1.0 }, /* E */
  { 1.0, 0.0, 1.0 }, /* F */
  { 1.0, 1.0, 1.0 }, /* G */
  { 0.0, 1.0, 1.0 }  /* H */
};

int edge[][2] = {
  { 0, 1 }, /* ア (A-B) */
  { 1, 2 }, /* イ (B-C) */
  { 2, 3 }, /* ウ (C-D) */
  { 3, 0 }, /* エ (D-A) */
  { 4, 5 }, /* オ (E-F) */
  { 5, 6 }, /* カ (F-G) */
  { 6, 7 }, /* キ (G-H) */
  { 7, 4 }, /* ク (H-E) */
  { 0, 4 }, /* ケ (A-E) */
  { 1, 5 }, /* コ (B-F) */
  { 2, 6 }, /* サ (C-G) */
  { 3, 7 }  /* シ (D-H) */
};

void display3(void) {
	static int r = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	/* 視点位置と視線方向 */
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glRotated((double)r, 0.0, 1.0, 0.0);
	glColor3d(0., 0., 0.);
	glBegin(GL_LINES);
	for (int i = 0; i < 12; i++) {
		glVertex3dv(vertex[edge[i][0]]);
		glVertex3dv(vertex[edge[i][1]]);
	}
	glEnd();
	//glFlush();
	glutSwapBuffers();
	if (++r >= 360) r = 0;
}

void idle(void) {
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display3);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	initDisplay();
	glutMainLoop();
	return 0;
}