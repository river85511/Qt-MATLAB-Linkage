function F=constrEq4bar(X)

global T	L1	L2	

x0=X(1); y0=X(2); phi0=X(3);
x1=X(4); y1=X(5); phi1=X(6);
x2=X(7); y2=X(8); phi2=X(9);
x3=X(10); y3=X(11); phi3=X(12);

F = [
(x0 - 0);
(y0 - 0);
(phi0 - 0);
( x1 - 0.5*L1 * cos(phi1) ) - ( x0 + (-66.804) );
( y1 - 0.5*L1 * sin(phi1) ) - ( y0 + (2.1428) );
( x2 + 0.5*L2 * cos(phi2) ) - ( x1 + 0.5*L1 * cos(phi1) );
( y2 + 0.5*L2 * sin(phi2) ) - ( y1 + 0.5*L1 * sin(phi1) );
( x3 ) - ( x2 - 0.5*L2 * cos(phi2) );
( y3 ) - ( y2 - 0.5*L2 * sin(phi2) );
( (( x0 + (cos(phi0)*(65.4675) - sin(phi0)*(0.0801696)) ) - ( x3 + (cos(phi3)*(1)) )  )*( -sin(phi3)*(1) )) + ( (( y0 + (sin(phi0)*(65.4675) + cos(phi0)*(0.0801696)) ) - ( y3 + (sin(phi3)*(1)) ) )*(  cos(phi3)*(1) ));
phi3 - phi0 - (0 - 0);
phi1 - (0.698132 + (10)*T + 0.5*(0)*T )];
