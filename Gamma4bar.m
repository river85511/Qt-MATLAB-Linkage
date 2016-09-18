function Gamma = Gamma4bar(phi0,phi1,phi2,phi3,dphi0,dphi1,dphi2,dphi3,dx3,dy3,x3,y3,dx0,dy0,x0,y0)

global	L1	L2	

Gamma=[
0;
0;
0;
( -0.5*L1*cos(phi1)*dphi1^2 );
( -0.5*L1*sin(phi1)*dphi1^2 );
( 0.5*L2*cos(phi2)*dphi2^2 ) - ( 0.5*L1*cos(phi1)*dphi1^2 );
( 0.5*L2*sin(phi2)*dphi2^2 ) - ( 0.5*L1*sin(phi1)*dphi1^2 );
 - ( -0.5*L2*cos(phi2)*dphi2^2 );
 - ( -0.5*L2*sin(phi2)*dphi2^2 );
(phi0 - phi3)^2 * ((65.4675)*sin(phi0 - phi3) + (0.0801696)*cos(phi0 - phi3)) + 2*(dx0 - dx3)*cos(phi3)*(dphi3) + 2*(dy0 - dy3)*sin(phi3)*(dphi3) - (x0 - x3)*sin(phi3)*(dphi3)^2 + (y0 - y3)*cos(phi3)*(dphi3)^2;
0;
0
];
