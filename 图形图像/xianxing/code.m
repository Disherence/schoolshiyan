I=imread('pic.jpg');
subplot(221);imshow(I);title('原图像');
I=rgb2gray(I);
subplot(222);imshow(uint8(I));title('灰度图像');
A=double(I);
subplot(223);imshow(uint8(I));title('double灰度');

[M,N]=size(A);
for i = 1:M
    for j = 1:N
        if A(i,j)<=30
            A(i,j)=A(i,j);
        elseif A(i,j)<=150
            A(i,j)=(200-30)/(150-30)*(A(i,j)-30)+30;
        else 
            A(i,j)=(255-200)/(255-155)*(A(i,j)-150)+200;
        end
    end
end

subplot(224);imshow(uint8(A));title('线性');

figure();
subplot(221);imhist(I);title('原图直方图');
subplot(222);imshow(I);title('原图');

J=histeq(I);
subplot(223);imhist(J);title('均衡后直方图');
subplot(224);imshow(J);title('均衡后');
