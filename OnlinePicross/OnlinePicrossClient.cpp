#define _CRT_SECURE_NO_WARNINGS

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#pragma comment(lib, "OpenGL32")

static GLuint texName;

typedef struct tagBITMAPHEADER {
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    RGBQUAD hRGB[256];
}BITMAPHEADER;


BYTE* LoadBitmapFile(BITMAPHEADER* bitmapHeader, int* iWidth, int* iHeight, const char* filename)
{
    FILE* fp = fopen(filename, "rb");	//파일을 이진읽기모드로 열기
    if (fp == NULL)
    {
        printf("파일로딩에 실패했습니다.\n");	//fopen에 실패하면 NULL값을 리턴
        return NULL;
    }
    else
    {
        fread(&bitmapHeader->bf, sizeof(BITMAPFILEHEADER), 1, fp);	//비트맵파일헤더 읽기
        fread(&bitmapHeader->bi, sizeof(BITMAPINFOHEADER), 1, fp);	//비트맵인포헤더 읽기
        fread(&bitmapHeader->hRGB, sizeof(RGBQUAD), 256, fp);	//색상팔렛트 읽기

        *iWidth = bitmapHeader->bi.biWidth;
        *iHeight = bitmapHeader->bi.biHeight;
        
        int imgSizeTemp = bitmapHeader->bi.biWidth * bitmapHeader->bi.biHeight;	//이미지 사이즈 계산
     

        BYTE* image = (BYTE*)malloc(sizeof(BYTE) * imgSizeTemp * 3);	//이미지크기만큼 메모리할당
        fread(image, sizeof(BYTE), imgSizeTemp * 3, fp);//이미지 크기만큼 파일에서 읽어오기
        fclose(fp);
        int i = 0;
        for (i = 0; i < imgSizeTemp; i++)
        {
            BYTE temp = image[i * 3];
            image[i * 3] = image[i * 3 + 2];
            image[i * 3 + 2] = temp;
        }

        return image;
    }
}


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
    GLFWwindow* window;
    
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(640, 480, "Picross Client Example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    BITMAPHEADER originalHeader;	//비트맵의 헤더부분을 파일에서 읽어 저장할 구조체
    int imgWidth;
    int imgHeight;			//이미지의 크기를 저장할 변수
    BYTE* image = LoadBitmapFile(&originalHeader, &imgWidth, &imgHeight, "art_sample.bmp"); //비트맵파일을 읽어 화소정보를 저장
    if (image == NULL) return 0;

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBindTexture(GL_TEXTURE_2D, texName);
        glBegin(GL_TRIANGLES);
        
        glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
        glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
        
        glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);

        glEnd();
        glFlush();
        glDisable(GL_TEXTURE_2D);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
