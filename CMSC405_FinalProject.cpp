//
//  CMSC405_FinalProject.cpp
//  Created by Yuji Shimojo on 12/9/12.
//
//  Press r to rotate right
//  Press l to rotate left
//  Click left mouse button to run
//

#include <iostream>
#include <GL/glut.h>

static int rotation = 0, left_shoulder = 0, right_shoulder = 0, left_elbow = 0, right_elbow = 0,
            left_thigh = 0, right_thigh = 0, left_shin = 0, right_shin = 0;
static bool runMode = true;

void init(void)
{
    GLfloat position[] = { 50.0, 50.0, -50.0, 1.0 };
    GLfloat ambient [] = { 0.5, 0.5, 0.5, 0.5 };
    GLfloat diffuse [] = { 10.0, 10.0, 10.0, 10.0 };
    GLfloat specular[] = { 5.0, 5.0, 5.0, 5.0 };
    GLfloat shininess[] = { 5.0 };
    
    glClearColor (1.0, 1.0, 1.0, 0.0);
    
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_SHININESS, shininess);
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    /*** whole the object ***/
    glPushMatrix();
    glColor3f(0.0, 0.5, 0.0);
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(0.0, 0.8, 0.0);
    glRotatef ((GLfloat) rotation, 0.0, 1.0, 0.0);
    
    /*** head ***/
    glColor3f (0.0, 0.5, 0.0);
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    glutSolidSphere (0.5, 15, 15);
    glPopMatrix();
        
    /*** horns ***/
    glPushMatrix();
    glColor3f (0.0, 0.5, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glRotatef(30, 0.0, 1.0, 0.0);
    glTranslatef(0.1, 0.0, 0.45);
    glScalef(0.6, 0.6, 0.6);
    glutSolidCone(0.15, 0.3, 15.0, 15.0);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-90, 1.0, 0.0, 0.0);
    glRotatef(-30, 0.0, 1.0, 0.0);
    glTranslatef(-0.1, 0.0, 0.45);
    glScalef(0.6, 0.6, 0.6);
    glutSolidCone(0.15, 0.3, 15.0, 15.0);
    glPopMatrix();
    
    /*** ears ***/
    glPushMatrix();
    GLdouble eqn[4] = {0.0, 0.0, -1.0, 0.0};
    glColor3f (1.0, 1.0, 0.0);
    glTranslatef(0.495, 0.0, 0.0);
    glRotatef(-90, 0.0, 1.0, 0.0);
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
    glutSolidSphere(0.03, 50, 50);
    glDisable (GL_CLIP_PLANE0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.495, 0.0, 0.);
    glRotatef(90, 0.0, 1.0, 0.0);
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
    glutSolidSphere(0.03, 50, 50);
    glDisable (GL_CLIP_PLANE0);
    glPopMatrix();

    /*** mane ***/
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(0.0, 0.25, -0.44);    
    glScalef(0.3, 0.3, 0.15);
    glRotatef(35, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.31, -0.41);    
    glScalef(0.3, 0.3, 0.15);
    glRotatef(43, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.36, -0.37);    
    glScalef(0.3, 0.3, 0.15);
    glRotatef(50, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.41, -0.33);    
    glScalef(0.3, 0.3, 0.15);
    glRotatef(56, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.45, -0.285);    
    glScalef(0.3, 0.3, 0.15);
    glRotatef(64, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.48, -0.24);    
    glScalef(0.3, 0.3, 0.15);
    glRotatef(72, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.50, -0.19);    
    glScalef(0.3, 0.3, 0.15);
    glRotatef(77, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.52, -0.145);    
    glScalef(0.3, 0.3, 0.15);
    glRotatef(82, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.53, -0.1);    
    glScalef(0.3, 0.3, 0.15);
    glRotatef(85, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.54, -0.05);    
    glScalef(0.3, 0.3, 0.15);
    glRotatef(86, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    /*** red small half spheres ***/
    glPushMatrix();
    glColor3f (1.0, 0.0, 0.0);
    glTranslatef(0.1, 0.39, -0.3);
    glRotatef(50, 1.0, 0.0, 0.0);
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
    glutSolidSphere(0.03, 50, 50);
    glDisable (GL_CLIP_PLANE0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.1, 0.39, -0.3);
    glRotatef(50, 1.0, 0.0, 0.0);
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
    glutSolidSphere(0.03, 50, 50);
    glDisable (GL_CLIP_PLANE0);
    glPopMatrix();
    
    /*** yellow half spheres ***/
    glPushMatrix();
    glColor3f (1.0, 1.0, 0.0);
    glTranslatef(0.17, 0.28, -0.38);
    glRotatef(33, 1.0, 0.0, 0.0);
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
    glutSolidSphere(0.1, 50, 50);
    glDisable (GL_CLIP_PLANE0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.17, 0.28, -0.38);
    glRotatef(33, 1.0, 0.0, 0.0);
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
    glutSolidSphere(0.1, 50, 50);
    glDisable (GL_CLIP_PLANE0);
    glPopMatrix();

    /*** sunglasses ***/
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.2, 0.0, -0.47);    
    glScalef(1.0, 1.0, 0.25);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.2, 0.0, -0.47);    
    glScalef(1.0, 1.0, 0.25);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.47);    
    glScalef(0.35, 0.4, 0.25);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.04, 0.07, -0.47);    
    glScalef(1.0, 1.0, 2.5);
    glutSolidCube (0.03);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.04, 0.07, -0.47);    
    glScalef(1.0, 1.0, 2.5);
    glutSolidCube (0.03);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.04, -0.07, -0.47);    
    glScalef(1.0, 1.0, 2.5);
    glutSolidCube (0.03);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.04, -0.07, -0.47);    
    glScalef(1.0, 1.0, 2.5);
    glutSolidCube (0.03);
    glPopMatrix();
    
    /*** teeth ***/
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(0.35, 0.0, -0.47);
    glScalef(0.1, 1.0, 0.2);
    glRotatef(25, 0.0, 1.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.35, 0.0, -0.47);    
    glScalef(0.1, 1.0, 0.2);
    glRotatef(-25, 0.0, 1.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    /*** mouth ***/
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(0.0, -0.3, -0.4);    
    glScalef(1.0, 0.4, 0.15);
    glRotatef(-50, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0, -0.33, -0.43);    
    glScalef(0.8, 0.01, 0.001);
    glRotatef(-50, 1.0, 0.0, 0.0);
    glutSolidCube (0.3);
    glPopMatrix();

    /*** body ***/
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0, -0.86, 0.0);
    glScalef(1.2, 1.5, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    /*** horizontal lines ***/
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslatef(0.18, -0.65, -0.27);
    glScalef(2.35, 0.8, 0.4);
    glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(1.0, 1.0, 0.0);
    glTranslatef(-0.18, -0.65, -0.27);
    glScalef(2.35, 0.8, 0.4);
    glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0.8, 0.8, 0.8);
    glTranslatef(0.17, -0.8, -0.27);
    glScalef(2.45, 0.5, 0.4);
    glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.17, -0.8, -0.27);
    glScalef(2.45, 0.5, 0.4);
    glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.17, -0.95, -0.27);
    glScalef(2.45, 0.5, 0.4);
    glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.17, -0.95, -0.27);
    glScalef(2.45, 0.5, 0.4);
    glutSolidCube(0.1);
    glPopMatrix();
    
    /*** vertical line ***/
    glPushMatrix();
    glTranslatef(0.0, -0.825, -0.27);
    glScalef(0.8, 6.6, 0.4);
    glutSolidCube(0.1);
    glPopMatrix();
    
    /*** yellow small half spheres ***/
    glPushMatrix();
    glColor3f (1.0, 1.0, 0.0);
    glTranslatef(0.1, -0.7, -0.25);
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
    glutSolidSphere(0.04, 50, 50);
    glDisable (GL_CLIP_PLANE0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.1, -0.7, -0.25);
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
    glutSolidSphere(0.04, 50, 50);
    glDisable (GL_CLIP_PLANE0);
    glPopMatrix();
    
    /*** green half sphere ***/
    glPushMatrix();
    glColor3f (0.0, 0.5, 0.0);
    glTranslatef(0.0, -1.05, -0.27);
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
    glutSolidSphere(0.04, 50, 50);
    glDisable (GL_CLIP_PLANE0);
    glPopMatrix();
    
    /*** belt ***/
    glPushMatrix();
    glColor3d(1.0, 0.0, 0.0);
    glTranslatef(0.0, -1.2, -0.27);
    glScalef(6.0, 0.8, 0.4);
    glutSolidCube(0.1);
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(0.0, 0.5, 0.0);
    glTranslatef(0.0, -1.2, -0.27);
    glScalef(1.8, 0.8, 0.4);
    glutSolidCube(0.1);
    glPopMatrix();
    
    /*** arms ***/
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef (0.43, -0.47, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) left_shoulder, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef (0.2, 0.0, 0.0);
    glScalef (0.465, 0.3, 0.3);
    glutSolidCube (0.8);
    glPopMatrix();
    
    glColor3f(0.0, 0.5, 0.0);
    glTranslatef (0.38, 0.0, 0.0);
    glRotatef ((GLfloat) left_elbow, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef (0.2, 0.0, 0.0);
    glScalef (0.465, 0.3, 0.3);
    glutSolidCube (0.8);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef (-0.43, -0.47, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) right_shoulder, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef (0.2, 0.0, 0.0);
    glScalef (0.465, 0.3, 0.3);
    glutSolidCube (0.8);
    glPopMatrix();
    
    glColor3f(0.0, 0.5, 0.0);
    glTranslatef (0.38, 0.0, 0.0);
    glRotatef ((GLfloat) right_elbow, 0.0, 1.0, 0.0);
    glTranslatef (0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef (0.465, 0.3, 0.3);
    glutSolidCube (0.8);
    glPopMatrix();
    glPopMatrix();
    
    /*** shoulders ***/
    glPushMatrix();
    glColor3f(0.0, 0.5, 0.0);
    glTranslatef (0.45, -0.48, 0.0);
    glScalef (0.6, 0.3, 1.0);
    glutSolidCube (0.5);
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.0, 0.5, 0.0);
    glTranslatef (-0.45, -0.48, 0.0);
    glScalef (0.6, 0.3, 1.0);
    glutSolidCube (0.5);
    glPopMatrix();
    
    /*** legs ***/
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef (0.16, -1.22, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) left_thigh, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef (0.2, 0.0, 0.0);
    glScalef (0.465, 0.35, 0.3);
    glutSolidCube (0.8);
    glPopMatrix();
    
    glColor3f(0.0, 0.5, 0.0);
    glTranslatef (0.38, 0.0, 0.0);
    glRotatef ((GLfloat) left_shin, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef (0.2, 0.0, 0.0);
    glScalef (0.465, 0.35, 0.3);
    glutSolidCube (0.8);
    glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef (-0.16, -1.22, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) right_thigh, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef (0.2, 0.0, 0.0);
    glScalef (0.465, 0.35, 0.3);
    glutSolidCube (0.8);
    glPopMatrix();
    
    glColor3f(0.0, 0.5, 0.0);
    glTranslatef (0.38, 0.0, 0.0);
    glRotatef ((GLfloat) right_shin, 0.0, 1.0, 0.0);
    glTranslatef (0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef (0.465, 0.35, 0.3);
    glutSolidCube (0.8);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix(); 
    
    glFlush();
    glutSwapBuffers();

}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-2.0, 0.0, -4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
}

void run(void)
{
    if (left_thigh > 50) {
        runMode = false;
    } else if (left_thigh < -50 ) {
        runMode = true;
    }
    
    if (runMode == true) {
        left_thigh = (left_thigh + 5) % 360;
        right_thigh = (right_thigh - 5) % 360;
        left_shin = (left_shin - 3 ) % 360;
        right_shin = (right_shin - 3 ) % 360;
        left_shoulder = (left_shoulder - 5) % 360;
        right_shoulder = (right_shoulder + 5) % 360;
        left_elbow = (left_elbow = + 3 ) % 360;
        right_elbow = (right_elbow + 3 ) % 360;

    } else if (runMode == false) {
        left_thigh = (left_thigh - 5) % 360;
        right_thigh = (right_thigh + 5) % 360;
        left_shin = (left_shin + 3 ) % 360;
        right_shin = (right_shin + 3 ) % 360;
        left_shoulder = (left_shoulder + 5) % 360;
        right_shoulder = (right_shoulder - 5) % 360;
        left_elbow = (left_elbow = - 3 ) % 360;
        right_elbow = (right_elbow - 3 ) % 360;
    }
    glutPostRedisplay();

}

void mouse (int button, int state, int x, int y)
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                glutIdleFunc(run);
            }
            else
                glutIdleFunc(0);
            break;
    }
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 'r':
            rotation = (rotation - 5) % 360;
            glutPostRedisplay();
            break;
        case 'l':
            rotation = (rotation + 5) % 360;
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (500, 500);
    glutCreateWindow("Ryujin Mabuyer");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);    
    glutMainLoop();
    
    return 0;
}
