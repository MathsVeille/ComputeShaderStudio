
// Write your code HERE
int mouseClicked = 0;


void main() {

	uint x = gl_GlobalInvocationID.x;
	uint y = gl_GlobalInvocationID.y;
    uint p = x + y * WSX;

    //initialisation
    if(step == 0){
        if(x>50 && x<70 && y>50 && y<80){
        data_0[p] = 0xFF00FF00; //fluide initial
        }
        else if(y>120){
        data_0[p] = 0xFFFFFFFF; //sol
        }
        else{
            data_0[p] = 0x00000000; //backround
        }
    }
    //boucle principale
    else{

        if(x == mousex && y==mousey){
            data_0[p] = 0xFF000000+step;
        }
        //si le pixel est non vide et non sol
        if(data_0[p] != 0xFFFFFFFF && data_0[p]!= 0x00000000){
            //il tombe
            if(data_0[p+WSX] == 0x00000000){
               data_0[p+WSX] = data_0[p];
               data_0[p] =  0x00000000;
            }
             //l'eau va sur les cotes
             //vide a droite en bas
             else if(data_0[p+1+WSX] == 0x00000000){
                data_0[p+1+WSX] = data_0[p];
                data_0[p] = 0x00000000;
             }
              //vide a gauche en bas
             else if(data_0[p-1+WSX] == 0x00000000){
                data_0[p-1+WSX] = data_0[p];
                data_0[p] = 0x00000000;
             }

             
            
            
             //vide a droite en bas
            

             //il y a un pixel en bas/gacuhe/droit
             else{
                if(y<120){

                    int rouge1 =(data_0[p] & 0x000000FF);
                    int green1 =((data_0[p] & 0x0000FF00)>>8);
                    int blue1 = (data_0[p] & 0x00FF0000)>>16;

                    int rouge2 =(data_0[p+WSX] & 0x000000FF);
                    int green2 =((data_0[p+WSX] & 0x0000FF00)>>8);
                    int blue2 = (data_0[p+WSX] & 0x00FF0000)>>16;

                    int rouge = (rouge1 + rouge2)/2;
                    int green = (green1 + green2)/2;
                    int blue = (blue1 + blue2)/2;


                    int couleur = (0xFF << 24) + (blue<<16) + (green << 8)  +rouge ; 

                    data_0[p] = couleur;
                    data_0[p+WSX] = couleur;
                    



                    /* if(data_0[p] < 0xFFFFFF00 ){
                        int couleur = (data_0[p]/3 + data_0[p+WSX]/3);
                        data_0[p] = couleur;
                        data_0[p+WSX] = couleur;
                    } */
                    
                }
                
             }

             

          
           
        }

        

    }

    


	//
	//data_0[p] = 0xFFF00FFF - int(p)*(step+1);



}
