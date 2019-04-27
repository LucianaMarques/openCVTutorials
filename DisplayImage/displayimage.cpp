/*
 * Tutorial reference:
 * https://docs.opencv.org/4.1.0/db/deb/tutorial_display_image.html
 */

#include <opencv2/core.hpp> //core section include the basic building blocks of the library
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream> 
#include <string>

// openCV's own namespace
using namespace cv;

using namespace std;

int main(int argc, char** argv){

    String imageName = "../fractal.jpg";
    if (argc > 1) imageName = argv[1];
    
    // Creates an image object
    Mat image;

    // second parameter is the format in which we want the image
    image = imread(imageName, IMREAD_COLOR);
    // IMREAD_COLOR loads the image in the RGB format
    
    if (image.empty()){
        cout << "Could not open or find the image" << endl;
    }

    // creates a window to display the image
    namedWindow("Display window", WINDOW_AUTOSIZE);

    // displays image in Display Window
    imshow("Display window", image);

    // keeps displaying it until user presses a key
    waitKey(0);

    return 0;
}