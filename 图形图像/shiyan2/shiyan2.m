close all;
clear;
clc;

A=rgb2gray(imread('pic.jpeg'));
B=double(A);
f=fft2(B);
g=fftshift(f);
subplot(221);imshow(log(abs(g)),[]);

N=imnoise(B,'salt');
f=fft2(N);
g=fftshift(f);
subplot(222);imshow(log(abs(g)),[]);

