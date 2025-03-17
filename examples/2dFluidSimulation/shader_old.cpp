
// Write your code HERE
int mouseClicked = 0;


void main() {

	uint x = gl_GlobalInvocationID.x;
	uint y = gl_GlobalInvocationID.y;
    uint p = x + y * WSX;

    //initialisation
    if(step == 0){
        /* if(x>50 && x<70 && y>50 && y<80){
        data_0[p] = 0xFF00FF00; //fluide initial
        } */
        if(y>120){
        data_0[p] = 0xFFFFFFFF; //sol
        }
        else{
            data_0[p] = 0x00000000; //backround
        }
    }
    //boucle principale
    else{

        

        if(x == mousex && y==mousey){
            data_0[p] = 0xFFFF0000;
        }
        //si le pixel est non vide et non sol
        if(data_0[p] != 0xFFFFFFFF && data_0[p]!= 0x00000000){
            //il tombe
            if(data_0[p+WSX] == 0x00000000){
               data_0[p+WSX] = data_0[p];
               data_0[p] =  0x00000000;
            }


            if(data_0[p] == 0xFFFF0000){
                  if(data_0[p-1] == 0x00000000 && data_0[p+1] != 0x00000000){
                data_0[p-1] = data_0[p];
                data_0[p]=0x00000000; 
                }
                else if(data_0[p+1] == 0x00000000 && data_0[p-1] != 0x00000000){
                    data_0[p+1] = data_0[p];
                    data_0[p]=0x00000000; 
                }

                else if(data_0[p+1] == 0x00000000 && data_0[p-1] == 0x00000000){
                    data_0[p+1] = data_0[p];
                    data_0[p]=0x00000000; 
                }
            }
           



             //l'eau va sur les cotes
             //vide a droite en bas
           /*  else{
                if(x<125 && x>2 ){
                    int temp1, temp2;
                    temp1 = data_0[p-1];
                    temp2 = data_0[p+1];

                    data_0[p-1] = data_0[p-2];
                    data_0[p+1] = data_0[p+2];
                    
                    data_0[p+2] = temp2;
                    data_0[p-2] = temp1;
                    
                    
                }
                
            } */
             
        
             //vide a droite en bas
            

           /*   //il y a un pixel en bas/gacuhe/droit
             else{
                if(y<120){
                    if(data_0[p] < 0xFFFFFF00 ){
                        int couleur = (data_0[p]/3 + data_0[p+WSX]/3);
                        data_0[p] = couleur;
                        data_0[p+WSX] = couleur;
                    }
                    
                }
                
             } */

             

          
           
        }

        

    }


}
