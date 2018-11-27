A=[2,1;1,-1];
B=[4;-1];
X=inv(A)*B;
fid=fopen('out.6.txt','a');
fprintf(fid,'********** P6 BEGIN *************\n');
fprintf(fid,'*** RESULT FROM MATLAB (UNSORTED):\n');
for k=1:2
fprintf(fid,'X[%d]=%6.2f\n',k-1,X(k));
end
fprintf(fid,'*********** P6 END **************\n');
