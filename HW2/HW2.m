im = imread('picture.png');
img = rgb2gray(im);   %轉換成灰階(2D)
h = zeros(256,1);
[row col] = size(img); %取得行列數
for i = 1:row
     for j = 1: col
       h(img(i,j)+1) = h(img(i,j)+1) +1 ;
     end 
end   % h是灰階對應的次數陣列(每個灰階有幾次)

img2 =img ;        %複製一個陣列，以防下面修改之後再被拿去判斷
for z  = 1:256     %算出CDF
  freq =  sum(h(1:z));
  gray = round ( freq * (256 - 1)  / (row * col)  );
  index = find ( (z-1) == img2 );
  img(index) = gray;
end
imwrite(img,'picture(modified).png')
