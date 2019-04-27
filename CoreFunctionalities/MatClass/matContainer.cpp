#include <opencv2/opencv.hpp>
#include <iostream> 
using namespace std;
#include <vector>

using namespace cv;

int main(int argc, char** argv){

    // Using header parts
    Mat A, C;                           
    A = imread(argv[1], IMREAD_COLOR);

    //copy constructor
    Mat B(A);

    //Attribution operator
    C = A;

    // Using a rectangle
    Mat D (A, Rect(10, 10, 100, 100) ); 
    
    // And getting only the ROI (region of interest)
    Mat E = A(Range::all(), Range(1,3));

    // Copying the matrix
    Mat F = A.clone();
    Mat G;
    A.copyTo(G);

    /*
     * Creating the Mat object explicitly
     * Mat_name(row,column,CV_XYZW,Scalar())
     * where X = Number of bits per item
     * Y = Signed or Unsigned, 
     * Z = Type prefix
     * W = The channel number
     * if Scalar is defined, the matrix starts with a pre-defined value 
     * in all its entries
     */
    Mat M(2,2, CV_8UC3, Scalar(0,0,255));
    // Seing the Mat Constructor
    cout << "M = " << endl << " " << M << endl << endl;

    // It is possible to used a c/c++ array. 
    // In this example, it is possible to create matrixes with more than two dim.
    int sz[3] = {2,2,2};
    Mat L(3,sz, CV_8UC(1), Scalar::all(0));
    M.create(4,4, CV_8UC(2));
    cout << "M = "<< endl << " "  << M << endl << endl;

    // Matlab type initializers
    E = Mat::eye(4, 4, CV_64F);
    cout << "E = " << endl << " " << E << endl << endl;
    Mat O = Mat::ones(2, 2, CV_32F);
    cout << "O = " << endl << " " << O << endl << endl;
    Mat Z = Mat::zeros(3,3, CV_8UC1);
    cout << "Z = " << endl << " " << Z << endl << endl;

    // Using coma-separators
    C = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cout << "C = " << endl << " " << C << endl << endl;
    C = (Mat_<double>({0, -1, 0, -1, 5, -1, 0, -1, 0})).reshape(3);
    cout << "C = " << endl << " " << C << endl << endl;

    // Cloning and copying a pre-existent Mat object
    Mat RowClone = C.row(1).clone();
    cout << "RowClone = " << endl << " " << RowClone << endl << endl;

    // Creating a matrix with random numbers
    Mat R = Mat(3, 2, CV_8UC3);
    randu(R, Scalar::all(0), Scalar::all(255));

    // Output of other Commons types
    // 2D Point
    Point2f P(5, 1);
    cout << "Point (2D) = " << P << endl << endl;

    // 3D Point
    Point3f P3f(2, 6, 7);
    cout << "Point (3D) = " << P3f << endl << endl;

    // Vector via Mat
    vector<float> v;
    v.push_back( (float)CV_PI);   v.push_back(2);    v.push_back(3.01f);
    cout << "Vector of floats via Mat = " << Mat(v) << endl << endl;

    // Vector of points
    vector<Point2f> vPoints(20);
    for (size_t i = 0; i < vPoints.size(); ++i)
        vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
    cout << "A vector of 2D Points = " << vPoints << endl << endl;
}