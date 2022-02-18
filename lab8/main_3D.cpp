#include <iostream>
#include "glut.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")

float angle = 0.0, angle1 = 0.0, angle2 = 0.0, angle3 = -30.0;
//Колодец 10; 5

int i1, i2, jj1, j2, l;
int m = 0;
int n = 0;
int p = 0;
//Матрица (20*20), -1 для обозначения границ и препятствий, 0 для обозначения пустой ячейки поля
int mat[22][22] = {{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,-1,-1,-1,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,-1,0,-1,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,-1,-1,-1,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1},
					{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};

// Вывод поля в консоль
void print(int mas[22][22])
{
	int i, j;
	for (i = 1; i<21; i++)
	{	//Пустая ячейка
		for (j = 1; j<21; j++)
			if (mas[i][j] == 0)
				std::cout << ". ";
			else
				//Препятствие
				if (mas[i][j] == -1)
					std::cout <<  "# ";
				else
					//Точки A и B
					if (mas[i][j] == -2)
						std::cout <<  "A ";
					else
						if (mas[i][j] == -3)
							std::cout <<  "B ";
						else
							//Кратчайший путь 
							if (mas[i][j] == -5)
								std::cout <<  "* ";
							else
								std::cout <<  mas[i][j]<<" ";
		std::cout <<std::endl;
	}
};

//Функция реализации волнового алгоритма
	void voln(int mas[22][22], int Ax, int Ay, int Bx, int By)
{
	int i, j;
	int v = 1;
	int k = 0;
	
	if (mas[Ax + 1][Ay] !=-1)
	mas[Ax + 1][Ay] = v;
	if (mas[Ax - 1][Ay] != -1)
	mas[Ax - 1][Ay] = v;
	if (mas[Ax ][Ay + 1] != -1)
	mas[Ax][Ay + 1] = v;
	if (mas[Ax][Ay - 1] != -1)
	mas[Ax][Ay - 1] = v;
	print(mas);
	while (mas[Bx][By] == -3)
	{
		for (i = 1; i < 21; i++)
		{
			for (j = 1; j < 21; j++)
			{
				if (mas[i][j] == v)
				{
					if (((mas[i + 1][j] == 0) || (mas[i + 1][j] == -3)) && (mas[i + 1][j] != -1))
					{
						mas[i + 1][j] = v + 1;
					}
					if (((mas[i - 1][j] == 0) || (mas[i - 1][j] == -3)) && (mas[i + 1][j] != -1))
					{
						mas[i - 1][j] = v + 1;
					}
					if (((mas[i][j + 1] == 0) || (mas[i][j + 1] == -3)) && (mas[i + 1][j] != -1))
					{
						mas[i][j + 1] = v + 1;
					}
					if (((mas[i][j - 1] == 0) || (mas[i][j - 1] == -3)) && (mas[i + 1][j] != -1))
					{
						mas[i][j - 1] = v + 1;
					}

				}
			}
		}
		v++;
		k++;
		if (k == 200)
			goto Q;
	}
Q:std::cout <<std:: endl;
};
	//Функция нахождения кратчайшего пути от А до В
	void show_the_way(int mas[22][22], int Ax, int Ay, int Bx, int By)
{
	int i3,j3;
	int c;
	c = mas[Bx][By]-1;
	mas[Bx][By] = -3;
	
		if (c == mas[Bx + 1][By])
		{
			i3 = Bx+1;
			j3 = By;
			c = mas[Bx + 1][By];
			mas[Bx + 1][By] = -5;
			goto C;
		}
			
		if (c  == mas[Bx - 1][By])
		{
			i3 = Bx-1;
			j3 = By;
			c = mas[Bx - 1][By];
			mas[Bx - 1][By] = -5;
			goto C;
		}
			
		if (c  == mas[Bx][By+1])
		{
			i3 = Bx;
			j3 = By+1;
			c = mas[Bx][By+1];
			mas[Bx][By + 1] = -5;
			goto C;
		}
			
		if (c  == mas[Bx][By - 1])
		{
			i3 = Bx;
			j3 = By-1;
			c = mas[Bx][By - 1];
			mas[Bx][By-1] = -5;
			goto C;
		}
		C:
		c = c - 1;
		for (int k = 0; k < 200; k++)
		{
			if (mas[i3 + 1][j3] == c )
			{
				c = c-1;
				mas[i3+1][j3] = -5;
				i3 = i3 + 1;
			}

			if ( mas[i3 - 1][j3] == c)
			{
				c = c-1;
				mas[i3-1][j3] = -5;
				i3 = i3 - 1;
			}

			if (mas[i3][j3 + 1] == c)
			{
				c = c-1;
				mas[i3][j3+1] = -5;
				j3 = j3 + 1;
			}

			if (mas[i3][j3 - 1] == c)
			{
				c = c-1;
				mas[i3][j3-1] = -5;
				j3 = j3 - 1;
			}
		}
	
}

	//Назначение для клавиш: → ↑ ← ↓ для управления камерой при 3D отрисовке
void special_kb (int key,int,int)
{
	if(key==GLUT_KEY_LEFT)
		angle-=2;
	glutPostRedisplay();
	if(key==GLUT_KEY_RIGHT)
		angle+=2;
	glutPostRedisplay();
	if(key==GLUT_KEY_UP)
		angle1-=2;
	glutPostRedisplay();
	if(key==GLUT_KEY_DOWN)
		angle1+=2;
	glutPostRedisplay();
;
}
//Назначение для клавиш: q e + -  для управления камерой при 3D отрисовке
void read_kb(unsigned char key ,int,int){
 if(key=='q')
	 angle2+=2;
 glutPostRedisplay();
 if(key=='e')
	 angle2-=2;
 glutPostRedisplay();
  if(key=='+')
	 angle3+=1;
 glutPostRedisplay();
 if(key=='-')
	 angle3-=1;
 glutPostRedisplay();
 	if(key==27)
		exit(0);
	glutPostRedisplay();
}
//Функция отрисовки 3D сцены 
void RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glViewport(0, 0, 800, 800);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,angle3);
  glRotatef(angle,0,1,0);
  glRotatef(angle1,1,0,0);
  glRotatef(angle2,0,0,1);
   glRotatef(-90,0,0,1);
  //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
 // glColor3f(1,1,1);

	for (int i = 1; i < 21; i++)
		{
			for (int j = 1; j < 21; j++)
			{
				
				
				switch (mat[i][j])
				{
				case 0:
					glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
					glColor3f(1,1,1);
					glBegin(GL_QUADS);
					glVertex3f(i-10,j-10,0);
					glVertex3f(i-10,j-10+1,0);
					glVertex3f(i-10+1,j-10+1,0);
					glVertex3f(i-10+1,j-10,0);
					
					glEnd();
					break;
				case -1: 
					glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
					glColor3f(1,0,1);
					glBegin(GL_QUADS);
					glVertex3f(i-10,j-10,0);
					glVertex3f(i-10,j-10+1,0);
					glVertex3f(i-10+1,j-10+1,0);
					glVertex3f(i-10+1,j-10,0);
					glEnd();
					break;
				case -2: 
					glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
					 glColor3f(1,1,1);
					glBegin(GL_QUADS);
					glVertex3f(i-10,j-10,0);
					glVertex3f(i-10,j-10+1,0);
					glVertex3f(i-10+1,j-10+1,0);
					glVertex3f(i-10+1,j-10,0);
					
					glEnd();
					glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
					glColor3f(1,0,0);
					glTranslatef(i-10+0.5,j-10+0.5,0.5);
					glutSolidSphere(0.5,50,50);
					glLoadIdentity();
					glTranslatef(0,0,angle3);
					glRotatef(angle,0,1,0);
					glRotatef(angle1,1,0,0);
					glRotatef(angle2,0,0,1);
					glRotatef(-90,0,0,1);
					break;

				case -3: 
					glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
					glColor3f(1,1,1);
					glBegin(GL_QUADS);
					glVertex3f(i-10,j-10,0);
					glVertex3f(i-10,j-10+1,0);
					glVertex3f(i-10+1,j-10+1,0);
					glVertex3f(i-10+1,j-10,0);
					
					glEnd();
					glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
					glColor3f(0,0,1);
					glTranslatef(i-10+0.5,j-10+0.5,0.5);
					glutSolidSphere(0.5,50,50);
					glLoadIdentity();
					glTranslatef(0,0,angle3);
					glRotatef(angle,0,1,0);
					glRotatef(angle1,1,0,0);
					glRotatef(angle2,0,0,1);
					 glRotatef(-90,0,0,1);
					 break;
				case -5:
					glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
					glColor3f(1,1,1);
					glBegin(GL_QUADS);
					glVertex3f(i-10,j-10,0);
					glVertex3f(i-10,j-10+1,0);
					glVertex3f(i-10+1,j-10+1,0);
					glVertex3f(i-10+1,j-10,0);
					
					glEnd();
					glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
					glColor3f(0,1,0);
					glTranslatef(i-10+0.5,j-10+0.5,0.5);
					glutSolidCube(1);
					glLoadIdentity();
					glTranslatef(0,0,angle3);
					glRotatef(angle,0,1,0);
					glRotatef(angle1,1,0,0);
					glRotatef(angle2,0,0,1);
					glRotatef(-90,0,0,1);
					break;

				default: 
					glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
					glColor3f(1,1,1);
					glBegin(GL_QUADS);
					glVertex3f(i-10,j-10,0);
					glVertex3f(i-10,j-10+1,0);
					glVertex3f(i-10+1,j-10+1,0);
					glVertex3f(i-10+1,j-10,0);
					glEnd();
				}

			}
		}
	  glRotatef(-90,0,0,1);
 // std::cout <<angle2<<std::endl;
	glutSwapBuffers();
}

int main(int argc, char *argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Пример вывода 3D графики");
	glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1);

for (int k = 0; k < 2; k++)
	{
		for (int i = 1; i < 21; i++)
		{
			for (int j = 1; j < 21; j++)
			{
				switch (mat[i][j])
				{
				case 0: std::cout << ". ";  break;
				case -1: std::cout << "# "; break;
				case -2: std::cout << "A "; break;
				case -3: std::cout << "B "; break;
				}
			}
			std::cout << std::endl;
		}
		if (k == 1) break;
			A:
			std::cout << "Enter coordinates(i,j) A" << std::endl;
			std::cin >> i1 >> jj1;
			if ((i1 > 21) || (i1 < 1) || (jj1 > 21) || (jj1 < 1)||(mat[i1][jj1] == -1))
			{
				std::cout << "Coordinates not correct" << std::endl;
				goto A;
			}
			else
			mat[i1][jj1] = -2;
			B:
			std::cout << "Enter coordinates(i,j) B" << std::endl;
			std::cin >> i2 >> j2;
			if ((i2 > 21) || (i2 < 1) || (j2 > 21) || (j2 < 1)||(mat[i2][j2] ==-1)||(mat[i2][j2] == -2))
			{
				std::cout << "Coordinates not correct" << std::endl;
				goto B;
			}
			else
			mat[i2][j2] = -3;	
}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Start of the wave algorithm"<<std::endl;
	voln(mat, i1, jj1, i2, j2);
	std::cout << std::endl;
	std::cout << std::endl;
	print(mat);
	
	if (mat[i2 + 1][j2] <= 0)
		p++;
	if (mat[i2 -1][j2] <= 0)
		p++;
	if (mat[i2][j2+1] <= 0)
		p++;
	if (mat[i2 ][j2+1] <= 0)
		p++;
	if (p==4)
	{
		std::cout << "There is no way" << std::endl;
		goto C;
	}


			

	
	std::cout << "To build a short path?(Y-1/N-any number)" << std::endl;
	std::cin >> l;
	if (l == 1)
	{
		show_the_way(mat, i1, jj1, i2, j2);
		for (int i = 1; i<21; i++)
		{
			for (int j = 1; j<21; j++)


				if (mat[i][j] == 0)
					std::cout << ". ";
				else
					if (mat[i][j] == -1)
						std::cout << "# ";
					else
						if (mat[i][j] == -2)
							std::cout << "A ";
						else
							if (mat[i][j] == -3)
								std::cout << "B ";
							else
								if (mat[i][j] == -5)
									std::cout << "+ ";
								else
									std::cout << ". ";
			std::cout << std::endl;
		}
	}
		//C:
		//std::cout << "See you!" << std::endl;




		if (p!=4)
  glutDisplayFunc(RenderScene);
		else 
		goto C;

  glutSpecialFunc(special_kb);
  glutKeyboardFunc(read_kb);
  glutMainLoop();

C:

		std::cout << "See you!" << std::endl;
	return 0;
}