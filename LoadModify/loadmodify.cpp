#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv){
    char* imageName = argv[1];
    
    Mat image;
    image = imread(imageName, IMREAD_COLOR);

    if (argc != 2 || !image.data){
        printf("No image data\n");
        return -1;
    }

    Mat grey_image;
    cvtColor(image, grey_image, COLOR_BGR2GRAY);

    imwrite("/home/luciana/Documents/Pesquisa/images/fractal.jpg", grey_image);

    namedWindow(imageName, WINDOW_NORMAL);
    namedWindow(imageName, WINDOW_NORMAL);

    imshow(imageName, image);
    imshow("Gay Image", grey_image);

    waitKey(0);
    return 0;
}