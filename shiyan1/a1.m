close all;
A=imread('file.PNG');
B=rgb2gray(A);
J=imnoise(B,'salt & pepper',0.05);
k1=filter2(fspecial('average',3),J);
k2=filter2(fspecial('average',5),J);
subplot(331),imshow(J); %����
subplot(332),imshow(uint8(k1)); %3*3��ֵ
subplot(333),imshow(uint8(k2)); %5*5��ֵ

m1=medfilt2(J);
m2=medfilt2(J,[5,5]);
subplot(335);imshow(m1); %3*3��ֵ
subplot(336);imshow(m2); %5*5��ֵ

