close all;
clc;
clear;

%RGB转灰度
rgb = imread('pic.jpeg');
gray = rgb2gray(rgb);
dougray = double(gray);
subplot(221); imshow(gray);

%傅立叶
fft = fft2(gray);
fftshift = fftshift(fft);
subplot(222); imshow(log(abs(fftshift)), []);

%离散余弦
dct = dct2(gray);
subplot(223); imshow(dct);

[M, N] = size(fft);
n1 = floor(M / 2);
n2 = floor(N / 2);
d0 = 65;

for i = 1:M

    for j = 1:N
        d = sqrt((i - n1)^2 + (j - n2)^2);

        if d <= d0
            h = 1;
        else
            h = 0;
        end

        fftshift(i, j) = h * fftshift(i, j);
    end

end

fftshift = ifftshift(fftshift);
fftshift = uint8(real(ifft2(fftshift)));
subplot(224); imshow(fftshift);
