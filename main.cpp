#include <opencv2/opencv.hpp>
#include <iostream>
#include <algorithm> 

using namespace cv;
using namespace std;


Mat ampliarImagem(const Mat& imagem, double fator) {

    int linhasOrig = imagem.rows;
    int colunasOrig = imagem.cols;
    int linhasNova = static_cast<int>(linhasOrig * fator);
    int colunasNova = static_cast<int>(colunasOrig * fator);

    Mat novaImagem(linhasNova, colunasNova, CV_8UC1);
    for (int i = 0; i < linhasNova; i++) {
        for (int j = 0; j < colunasNova; j++) {
            int orig_i = min(static_cast<int>(i / fator), linhasOrig - 1);
            int orig_j = min(static_cast<int>(j / fator), colunasOrig - 1);
            novaImagem.at<uchar>(i, j) = imagem.at<uchar>(orig_i, orig_j);
        }
    }
    return novaImagem;
}

Mat reduzirImagem(const Mat& imagem, double fator) {

    int linhasOrig = imagem.rows;
    int colunasOrig = imagem.cols;
    int linhasNova = static_cast<int>(linhasOrig * fator);
    int colunasNova = static_cast<int>(colunasOrig * fator);

    Mat novaImagem(linhasNova, colunasNova, CV_8UC1);
    for (int i = 0; i < linhasNova; i++) {
        for (int j = 0; j < colunasNova; j++) {
            int orig_i = min(static_cast<int>(i / fator), linhasOrig - 1);
            int orig_j = min(static_cast<int>(j / fator), colunasOrig - 1);
            novaImagem.at<uchar>(i, j) = imagem.at<uchar>(orig_i, orig_j);
        }
    }
    return novaImagem;
}

Mat ampliarImagemColorindoAdicionados(const Mat& imagem, int fator) {
    int linhasOrig = imagem.rows;
    int colunasOrig = imagem.cols;
    int linhasNova = linhasOrig * fator;
    int colunasNova = colunasOrig * fator;


    Mat novaImagem(linhasNova, colunasNova, CV_8UC3);


    Vec3b corAdicionado = Vec3b(0, 0, 255);

    for (int i = 0; i < linhasNova; i++) {
        for (int j = 0; j < colunasNova; j++) {
            int orig_i = i / fator;
            int orig_j = j / fator;

            if ((i % fator == 0) && (j % fator == 0)) {
                uchar pixelCinza = imagem.at<uchar>(orig_i, orig_j);
                novaImagem.at<Vec3b>(i, j) = Vec3b(pixelCinza, pixelCinza, pixelCinza);
            }
            else {

                novaImagem.at<Vec3b>(i, j) = corAdicionado;
            }
        }
    }
    return novaImagem;
}

int main() {

    Mat imagemColorida = imread("C:/Users/juedu/Documents/imgteste/2.png");
    Mat imagemCinza;
    cvtColor(imagemColorida, imagemCinza, COLOR_BGR2GRAY);
    imwrite("imagem_cinza.jpg", imagemCinza);


    double fatorAmplia = 10.0;
    int fatorInteiro = 2;
    double fatorReduz = 0.04;


    Mat imagemAmpliada = ampliarImagem(imagemCinza, fatorAmplia);
    imwrite("imagem_ampliada.jpg", imagemAmpliada);


    Mat imagemAmpliadaColorida = ampliarImagemColorindoAdicionados(imagemCinza, fatorInteiro);
    imwrite("imagem_ampliada_colorida.jpg", imagemAmpliadaColorida);


    Mat imagemReduzida = reduzirImagem(imagemCinza, fatorReduz);
    imwrite("imagem_reduzida.jpg", imagemReduzida);


    namedWindow("Imagem Cinza", WINDOW_NORMAL);
    resizeWindow("Imagem Cinza", 300, 300);
    imshow("Imagem Cinza", imagemCinza);

    namedWindow("Imagem Ampliada", WINDOW_NORMAL);
    resizeWindow("Imagem Ampliada", 300, 300);
    imshow("Imagem Ampliada", imagemAmpliada);

    namedWindow("Imagem Ampliada Colorida", WINDOW_NORMAL);
    resizeWindow("Imagem Ampliada Colorida", 300, 300);
    imshow("Imagem Ampliada Colorida", imagemAmpliadaColorida);

    namedWindow("Imagem Reduzida", WINDOW_NORMAL);
    resizeWindow("Imagem Reduzida", 300, 300);
    imshow("Imagem Reduzida", imagemReduzida);




    waitKey(0);

}
  