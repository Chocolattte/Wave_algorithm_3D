#include "glut.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")

float angle=0.0;
float tr=0.0;

void read_kb(unsigned char key ,int,int){
 if(key=='a')
	 angle+=2;
 glutPostRedisplay();
  if(key=='s')
	 angle-=2;
 glutPostRedisplay();
 if(key=='q')
	 tr+=2;
 glutPostRedisplay();
 if(key=='w')
	 tr-=2;
 glutPostRedisplay();
}

void RenderScene() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(-0.3,-0.3,0);
  glRotatef(angle,0,0,1);
  //glTranslatef(0.3,0.3,0);
  glColor3f(1,0.5,0.5);
  glBegin(GL_QUADS);
	 glColor3f(1,0,0);
	 glVertex2f(0.3,0.3);
	 glColor3f(0,1,0);
	 glVertex2f(-0.3,0.3);
	 glColor3f(0,0,1);
	 glVertex2f(-0.3,-0.3);
	 glColor3f(1,1,0);
	 glVertex2f(0.3,-0.3);
  glEnd();
  glLoadIdentity();
  glTranslatef(0.15,0.15,0);
  glRotatef(tr,0,0,1);
  glBegin(GL_TRIANGLES);
	 glColor3f(1,0,0);
	 glVertex2f(0,0.2);
	 glColor3f(0,1,0);
	 glVertex2f(-0.2,-0.2);
	 glColor3f(0,0,1);
	 glVertex2f(0.2,-0.2);
  glEnd();
  glFlush();
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_ALPHA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Пример вывода 2D графики");
  glClearColor(0,0,0, 1);

  glutDisplayFunc(RenderScene);
  glutKeyboardFunc(read_kb);
  glutMainLoop();

  return 0;
}
