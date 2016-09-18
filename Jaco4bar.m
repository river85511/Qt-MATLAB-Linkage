function JacoMatrix = Jaco4bar(phi0,phi1,phi2,phi3,x3,y3,x0,y0)

global	L1	L2	
JacoMatrix = [ 
1 0 0 0 0 0 0 0 0 0 0 0;
0 1 0 0 0 0 0 0 0 0 0 0;
0 0 1 0 0 0 0 0 0 0 0 0;
-1 0 0 1 0 0.5*L1 * ( sin(phi1)) 0 0 0 0 0 0;
0 -1 0 0 1 0.5*L1 * (-cos(phi1)) 0 0 0 0 0 0;
0 0 0 -1 0 -0.5*L1 * (-sin(phi1)) 1 0 0.5*L2 * (-sin(phi2)) 0 0 0;
0 0 0 0 -1 -0.5*L1 * ( cos(phi1)) 0 1 0.5*L2 * ( cos(phi2)) 0 0 0;
0 0 0 0 0 0 -1 0 -0.5*L2 * ( sin(phi2)) 1 0 0;
0 0 0 0 0 0 0 -1 -0.5*L2 * (-cos(phi2)) 0 1 0;
-sin(phi0) cos(phi0) (65.4675)*(cos(phi3)*cos(phi0) + sin(phi3)*sin(phi0)) + (0.0801696)*(sin(phi3)*cos(phi0) - cos(phi3)*sin(phi0)) 0 0 0 0 0 0 sin(phi3) -cos(phi3) (x3 - x0)*cos(phi3) + (y3 - y0)*sin(phi3) - (65.4675)*(cos(phi3)*cos(phi0) + sin(phi3)*sin(phi0)) - (0.0801696)*(sin(phi3)*cos(phi0) - cos(phi3)*sin(phi0));
0 0 -1 0 0 0 0 0 0 0 0 1;
0 0 0 0 0 1 0 0 0 0 0 0;
];
