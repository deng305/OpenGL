#include "iostream"
#include "windows.h"
#include "GL/glut.h"

/*GLUT_SINGLE单缓冲，屏幕显示调用glFlush()，将图像在当前显示缓存中直接渲染，会有图形跳动(闪烁)问题
GLUT_DOUBLE双缓冲，屏幕显示调用glutSwapBuffers()，将图像先绘制在另外的缓存中，
渲染完毕之后，将其整个缓存贴到当前的窗口，能消除闪烁, 一般动画要用双缓冲
glutSwapBuffers()： 告诉 GLUT 在 backbuffer 和 frontbuffer 之间进行交换。在通过帧回调函数的下一个循环中，
我们将场景渲染到当前的 frontbuffer 中，而 backbuffer 将被显示*/

/*glutDialsFunc: 可以通过事件回调函数与运行中的项目进行交互。GLUT 可以和基本的窗口系统进行交互，
并且提供给我们一些回调函数。在这里我们仅仅使用了一个主回调函数，
这个主回调函数完成了一帧中的所有渲染工作。这个函数被 GLUT 内部循环不断的调用*/

/*glClearColor 的作用是，指定刷新颜色缓冲区时所用的颜色, 颜色有四个通道（RGBA），而且它被指定为 0.0 – 1.0 之间标准化的值
所以，完成一个刷新过程是要 glClearColor(COLOR) 与 glClear(GL_COLOR_BUFFER_BIT) 配合使用。
glClear 函数的功能仅仅就是清除帧缓存（使用我们在glClearColor指定过的颜色）
glClear 比手动涂抹一个背景画布效率高且省力，所以通常使用这种方式
清除颜色缓冲区的作用是，防止缓冲区中原有的颜色信息影响本次绘图（注意！即使认为可以直接覆盖原值，也是有可能会影响的），
当绘图区域为整个窗口时，就是通常看到的，颜色缓冲区的清除值就是窗口的背景颜色。所以，这两条清除指令并不是必须的：
比如对于静态画面只需要设置一次，比如不需要背景色/背景色为白色
*/

/*清除颜色缓冲区的作用是，防止缓冲区中原有的颜色信息影响本次绘图（注意！即使认为可以直接覆盖原值，也是有可能会影响的）
当绘图区域为整个窗口时，就是通常看到的，颜色缓冲区的清除值就是窗口的背景颜色。所以，
这两条清除指令并不是必须的：比如对于静态画面只需要设置一次，比如不需要背景色/背景色为白色*/

/*glutMainLoop: 这个函数调用将控制传递给 GLUT，并且开启了它自己内部的循环。在这个循环中，
它监听来自窗口系统的事件并通过我们设置的回调函数传递给 GLUT*/


void myDisplay(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(20);
	glBegin(GL_POINTS);
	glColor3f(0, 1, 0);
	glVertex2f(0, 0);
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("create window");
	glutDisplayFunc(&myDisplay);
	glutMainLoop();
	return 0;
}