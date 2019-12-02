#include <windows.h>								 
#include "freeglut.h"

GLdouble eyeX=0.0;
GLdouble eyeY=0.0;
GLdouble eyeZ=30.0;
GLdouble centerX = 0;
GLdouble centerY = 0;
GLdouble centerZ = 0;

void cuboid(GLfloat x, GLfloat y, GLfloat z, GLfloat dx, GLfloat dy, GLfloat dz,
                      float r1, float g1, float b1,
                      float r2, float g2, float b2,
                      float r3, float g3, float b3)
{
  glBegin(GL_QUADS);

  // Góra: turkus
  glColor3f(r1, g1, b1);
  glVertex3f(x, y + dy, z);
  glVertex3f(x + dx, y + dy, z);
  glVertex3f(x + dx, y + dy, z + dz);
  glVertex3f(x, y + dy, z + dz);
  
  // Dół: turkus
  glColor3f(r1, g1, b1);
  glVertex3f(x, y, z);
  glVertex3f(x + dx, y, z);
  glVertex3f(x + dx, y, z + dz);
  glVertex3f(x, y, z + dz);
  
  // Prawa: turkus
  glColor3f(r1, g1, b1);
  glVertex3f(x + dx, y, z);
  glVertex3f(x + dx, y, z + dz);
  glVertex3f(x + dx, y + dy, z + dz);
  glVertex3f(x + dx, y + dy, z);
  
  // Lewa: turkus
  glColor3f(r1, g1, b1);
  glVertex3f(x, y, z);
  glVertex3f(x, y, z + dz);
  glVertex3f(x, y + dy, z + dz);
  glVertex3f(x, y + dy, z);
  
  // Przód: żółty
  glColor3f(r2, g2, b2);
  glVertex3f(x, y, z);
  glVertex3f(x + dx, y, z);
  glVertex3f(x + dx, y + dy, z);
  glVertex3f(x, y + dy, z);
  
  // Tył: zielony
  glColor3f(r3, g3, b3);
  glVertex3f(x, y, z + dz);
  glVertex3f(x + dx, y, z + dz);
  glVertex3f(x + dx, y + dy, z + dz);
  glVertex3f(x, y + dy, z + dz);
  
  glEnd();
}

void sphere(GLdouble radius, GLint slices, GLint stacks, 
            int movX, int movY, int movZ, 
            float r, float g, float b)
{
  glPushMatrix();
  glTranslatef(movX, movY, movZ);
  glColor3f(r, g, b);
  glutSolidSphere(radius, slices, stacks); 
  glPopMatrix();
}

void curvature(GLfloat x, GLfloat y, GLfloat z, GLfloat ddx, GLfloat dkx, GLfloat dy, GLfloat dz,
          float r1, float g1, float b1,
          float r2, float g2, float b2,
          float r3, float g3, float b3)
{
  glBegin(GL_QUADS);

  // Góra: turkus
  glColor3f(r1, g1, b1);
  glVertex3f(x, y + dy, z);
  glVertex3f(x + dkx, y + dy, z);
  glVertex3f(x + dkx, y + dy, z + dz);
  glVertex3f(x, y + dy, z + dz);
  
  // Dół: turkus
  glColor3f(r1, g1, b1);
  glVertex3f(x + ddx, y, z);
  glVertex3f(x + ddx + dkx, y, z);
  glVertex3f(x + ddx + dkx, y, z + dz);
  glVertex3f(x + ddx, y, z + dz);
  
  // Prawa: turkus
  glColor3f(r1, g1, b1);
  glVertex3f(x + ddx + dkx, y, z);
  glVertex3f(x + dkx, y + dy, z);
  glVertex3f(x + dkx, y + dy, z + dz);
  glVertex3f(x + ddx + dkx, y, z + dz);
  
  // Lewa: turkus
  glColor3f(r1, g1, b1);
  glVertex3f(x + ddx, y, z);
  glVertex3f(x, y + dy, z);
  glVertex3f(x, y + dy, z + dz);
  glVertex3f(x + ddx, y, z + dz);
  
  // Przód: żółty
  glColor3f(r2, g2, b2);
  glVertex3f(x + ddx, y, z);
  glVertex3f(x, y + dy, z);
  glVertex3f(x + dkx, y + dy, z);
  glVertex3f(x + ddx + dkx, y, z);
  
  // Tył: zielony
  glColor3f(r3, g3, b3);
  glVertex3f(x + ddx, y, z + dz);
  glVertex3f(x, y + dy, z + dz);
  glVertex3f(x + dkx, y + dy, z + dz);
  glVertex3f(x + ddx + dkx,  y, z + dz);
  
  glEnd();
}

void display() 
{
  glClearColor(1.0,1.0,1.0,1.0); 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 1.0, 0.1, 1000.0);
  gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0.0, 1.0, 0.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // A
  cuboid(-10.0, -2, 0.0, 6.0, 2.0, -6.0,
                   0, 1, 1,
                   1, 1, 0,
                   0, 1, 0);
  curvature(-8.0, -9.0, 0.0, 4.0, 2.0, 20.0, -6.0,
                   0, 1, 1,
                   1, 1, 0,
                   0, 1, 0);
  curvature(-9.0, -9.0, 0.0, -4.0, 2.0, 20.0, -6.0,
                   0, 1, 1,
                   1, 1, 0,
                   0, 1, 0);

  // D
  cuboid(5.0, -9.0, 0.0, 2.0, 20.0, -6.0,
                   0, 1, 1,
                   1, 1, 0,
                   0, 1, 0);
  cuboid(5.0, -9.0, 0.0, 6.0, 2.0, -6.0,
                   0, 1, 1,
                   1, 1, 0,
                   0, 1, 0);
  cuboid(5.0, 9.0, 0.0, 6.0, 2.0, -6.0,
                   0, 1, 1,
                   1, 1, 0,
                   0, 1, 0);

  cuboid(13, -3, 0.0, 2.0, 8.0, -6.0,
                   0, 1, 1,
                   1, 1, 0,
                   0, 1, 0);
  curvature(9.0, 5.0, 0.0, 4.0, 2.0, 6.0, -6.0,
                   0, 1, 1,
                   1, 1, 0,
                   0, 1, 0);
  curvature(13.0, -9.0, 0.0, -4.0, 2.0, 6.0, -6.0,
                   0, 1, 1,
                   1, 1, 0,
                   0, 1, 0);

  // Płyta
  cuboid(-15.0, -13.0, 0.0, 30.0, 4.0, -6.0,
                   1, 0, 0,
                   1, 0, 0,
                   1, 0, 0);

  // Kule-podpory
  sphere(1, 50, 50, 14, -14, -1, 1, 0, 0);
  sphere(1, 50, 50, 14, -14, -5, 1, 0, 0);
  sphere(1, 50, 50, -14, -14, -1, 1, 0, 0);
  sphere(1, 50, 50, -14, -14, -5, 1, 0, 0);

  // Kula między literami
  sphere(2, 50, 50, 0, 2, 0, 1, 1, 0);

  glFlush();
} 

void Redisplay(int width, int height)
{
  glViewport(0, 0, width, height);
  display();
}

void Klawiatura(unsigned char key, int x, int y)
{
    if( key == '+')
         eyeZ -= 3;
    else

    if( key == '-')
         eyeZ += 3;

    Redisplay(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void Strzalki(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        eyeX += 3;
        break;

    case GLUT_KEY_UP:
        eyeY -= 3;
        break;

    case GLUT_KEY_RIGHT:
        eyeX -= 3;
        break;

    case GLUT_KEY_DOWN:
        eyeY += 3;
        break;
    }
    Redisplay(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
  glutInitWindowSize(800,800);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Artur Dobrowolski | id: 439386");
  glutDisplayFunc(display);
  glutReshapeFunc(Redisplay);
  glutKeyboardFunc(Klawiatura);
  glutSpecialFunc(Strzalki);
  glutMainLoop();

  return 0;
}
