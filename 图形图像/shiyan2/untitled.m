A=[1 0 1 0 1 0 0 0 0 0 0 0 0 1;1 0 1 0 1 0 0 0 0 0 0 0 0 1;1 0 1 0 1 0 0 0 0 0 0 0 0 1;1 0 1 0 1 0 0 0 0 0 0 0 0 1;1 0 1 0 1 0 0 0 0 0 0 0 0 1;1 0 1 0 1 0 0 0 0 0 0 0 0 1;1 0 1 0 1 0 0 0 0 0 0 0 0 1;1 0 1 0 1 0 0 0 0 0 0 0 0 1;];
B=fft2(A);
C=fftshift(B);
imshow(log(abs(C)),[]);