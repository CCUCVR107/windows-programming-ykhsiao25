im = imread('picture.png');
img = rgb2gray(im);   %�ഫ���Ƕ�(2D)
h = zeros(256,1);
[row col] = size(img); %���o��C��
for i = 1:row
     for j = 1: col
       h(img(i,j)+1) = h(img(i,j)+1) +1 ;
     end 
end   % h�O�Ƕ����������ư}�C(�C�ӦǶ����X��)

img2 =img ;        %�ƻs�@�Ӱ}�C�A�H���U���ק蠟��A�Q���h�P�_
for z  = 1:256     %��XCDF
  freq =  sum(h(1:z));
  gray = round ( freq * (256 - 1)  / (row * col)  );
  index = find ( (z-1) == img2 );
  img(index) = gray;
end
imwrite(img,'picture(modified).png')
