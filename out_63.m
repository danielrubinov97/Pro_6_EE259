A=[2,1;1,-1];
X=inv(A);
fid=fopen('out.6.txt','a');
fprintf(fid,'********** P6 BEGIN *************\n');
fprintf(fid,'*** INVERSION RESULT FROM MATLAB: \n');
for i=1:2
for j=1:2
fprintf(fid,'X[%d][%d]=%6.2f ',i-1,j-1,X(i,j));
end
fprintf(fid,'\n');
end
fprintf(fid,'*********** P6 END **************\n');
