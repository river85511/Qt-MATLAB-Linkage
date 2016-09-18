clc; clear;
T_Int = 0:0.01:3

global T	L1	L2	
L1 = 50;
L2 = 100;
Xinit = [0 0 0 -47.6529 18.2125 0.698132 18.4829 17.1812 2.79253 65.4675 0.0801696 0 ];

for Iter = 1:length(T_Int);
T = T_Int(Iter)
[Xtemp, fval] = fsolve(@constrEq4bar,Xinit);
X(:,Iter) = Xtemp;

phi0 = Xtemp(3); phi1 = Xtemp(6); phi2 = Xtemp(9); phi3 = Xtemp(12); 
x3 = Xtemp(10); y3 = Xtemp(11);
x0 = Xtemp(1); y0 = Xtemp(2);
JacoMatrix = Jaco4bar(phi0,phi1,phi2,phi3,x3,y3,x0,y0);
Beta=[0 0 0 0 0 0 0 0 0 0 0 ((10)+(0)*T)]';
Vtemp = JacoMatrix\Beta;
V(:,Iter) = Vtemp;

dphi0 = Vtemp(3); dphi1 = Vtemp(6); dphi2 = Vtemp(9); dphi3 = Vtemp(12); 
dx3 = Vtemp(10); dy3 = Vtemp(11);
dx0 = Vtemp(1); dy0 = Vtemp(2);
Gamma = Gamma4bar(phi0,phi1,phi2,phi3,dphi0,dphi1,dphi2,dphi3,dx3,dy3,x3,y3,dx0,dy0,x0,y0);
Atemp = JacoMatrix\Gamma;
A(:,Iter)=Atemp;

if Iter == 1
	Xinit = X(:,Iter);
else
	Xinit = X(:,Iter) + (X(:,Iter) - X(:,Iter-1));
end
end

figure
for i=4:12
    subplot(9,1,i-3)
    plot(T_Int,X(i,:))
    set(gca,'xtick',[], 'FontSize', 5)
end
set(gca,'xtickMode', 'auto')

figure
for i=4:12
    subplot(9,1,i-3)
    plot(T_Int,V(i,:))
    set(gca,'xtick',[], 'FontSize', 5)
end
set(gca,'xtickMode', 'auto')

figure
for i=4:12
    subplot(9,1,i-3)
    plot(T_Int,A(i,:))
    set(gca,'xtick',[], 'FontSize', 5)
end
set(gca,'xtickMode', 'auto')

[m n] = size(X);
str = 'animation.txt';
fin = fopen(str,'wt');
for i = 1:m
    for j =1:n
    fprintf(fin,'%d	',X(i,j));
    end
fprintf(fin,'\n');
end
fclose(fin);
