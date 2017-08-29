clc 
clear all
close all
N=100;
shownum=zeros(1,N);
data=[];
tmp=0;i=0;
while 1
    i=i+1;
    a=urlread('http://www.sjjdata.local');
    tmp=str2num(a(26:29));
    tmp=tmp*0.085-55.6;
    data=[data,tmp];
    if length(data)<N
        plot(data);
    else
        shownum=data(end-N+1:end);
        plot(shownum);
    end
    axis([0 N 10 40])
    pause(0.1)
end
























