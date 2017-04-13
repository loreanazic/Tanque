#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>


const char *ssid = "ESPap";
const char *password = "picolinajllm1";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
   String form;
        
         
   int ledPin = 2;

   void ini_vaciar(){
    digitalWrite(D1, HIGH); 
    Serial.println("entroooo");  
   }
   void fin_vaciar(){
      digitalWrite(ledPin, HIGH); 
      digitalWrite(D1, LOW);       
   }
   void ini_llenar(){
    digitalWrite(ledPin, LOW); 
    digitalWrite(D2, HIGH);    
   }
   void fin_llenar(){
     digitalWrite(D2, LOW); 
   }

void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.println();
  Serial.print("Configuring access point...");

  /*---------------------------------------------------------------------------------*/
   form="<!DOCTYPE html>";
   form+="<html><head><meta charset='UTF-8'><script type='text/javascript'>"; 
             /*-------------------------------------------------------------------------------------------*/    
        

            form+=" function ajaxLoad(method ,URL,displayElementId,sendData){";
            form+="        var ajax; ";
            form+="        if (window.XMLHttpRequest) { ";
            form+="          ajax=new XMLHttpRequest();";
            form+="        }";
            form+="   if(!ajax){alert('No existe');return;}";
            form+="   ajax.open(method,URL,true);";
            form+="    ajax.send();}";

            form+="  function Enviar(state){ajaxLoad('GET','/'+state+'.html',null,null);}";
            
            form+=" function functionProgress2(i,x) {";
                    
            form+=" barra1=document.getElementById('barra');";

            form+=" if(x==-1){";
            form+="     msj=document.getElementById('mensaje');";
            form+="     barra = document.getElementById('barra');";
            form+="     l1 = document.getElementById('ll1');";
            form+="     l2 = document.getElementById('ll2');";
            form+="     max = 169;";
            form+="     TIME = 80;";
            form+="      if (barra1.style.height=='0px' || barra1.style.height=='') { ";
            form+="           ban=0;";
            form+="           vaciar_b=document.getElementById('v1');llenar_b=document.getElementById('ll');";
            form+="           llenar_b.disabled = true;vaciar_b.disabled= true;";
            form+="           msj.innerText='';";
            form+="          Enviar('inivaciar');"; 
            form+="     }else{";
            form+="             ban=1;";
            form+="             msj.innerText='El tanque esta vacio! ';}}";
 
            form+="  if (i > max){";
            form+="   ban=1; llenar_b.disabled = false;vaciar_b.disabled=false;";
            form+="   l2.setAttribute('style', 'height: 10px; background-color: #808B96;');";
            form+="          Enviar('finvaciar');}";
                    
            form+=" if(ban==0){";
            form+="   i=i+2;";
            form+="   barra.setAttribute('style', 'height:'+i+'px; width: 150px; background: #D0D3D4;');";
            form+="   l1.setAttribute('style', 'height: 10px; background-color: #808B96;');";
            form+="   l2.setAttribute('style', 'height: 10px; background-color: #CB4335;');";
            form+="   setTimeout('functionProgress2(' + (i) +','+ (0) + ')', TIME);}}";
       form+="  function functionProgress1(i,x) {";
                    
       form+="      barra1=document.getElementById('barra');";
       form+="          if(x==-1){";
       form+="              barra = document.getElementById('barra');";
       form+="              msj=document.getElementById('mensaje');";
       form+="              max = 0;";
       form+="              TIME1 = 80;";
       form+="              if (barra1.style.height=='170px') { ";
       form+="                ban=0;";
       form+="                vaciar_b=document.getElementById('v1');llenar_b=document.getElementById('ll');";
       form+="                llenar_b.disabled = true;vaciar_b.disabled= true;";
       form+="                msj.innerText='';";
       form+="                Enviar('inillenar');"; 
       form+="              }else{";
       form+="                  ban=1;";
       form+="                  msj.innerText='El tanque esta lleno! ';}";
       form+="              l1 = document.getElementById('ll1');l2 = document.getElementById('ll2');}";
                   
       form+="         if (i < max){ban=1;  llenar_b.disabled = false;vaciar_b.disabled=false;";
       form+="            l1.setAttribute('style', 'height: 10px; background-color: #808B96;');";
       form+="          Enviar('finllenar');}"; 
       form+="          if(ban==0){ i=i-2;";
       form+="            barra.setAttribute('style', 'height:'+i+'px; width: 150px; background: #D0D3D4;');";
       form+="            l1.setAttribute('style', 'height: 10px; background-color: #CB4335;');";
       form+="            l2.setAttribute('style', 'height: 10px; background-color: #808B96;');";
       form+="            setTimeout('functionProgress1(' + (i) +','+ (0) + ')', TIME1);}}";       
             /*-------------------------------------------------------------------------------------------*/ 
       form+=" </script> </head>";
form+="   <body style='overflow: hidden; height: 100%; display: -webkit-flex; display: -ms-flexbox; display: flex; -webkit-justify-content: center; -ms-flex-pack: center; justify-content: center; -webkit-align-items: center; -ms-flex-align: center; align-items: center;'><br><br><br>";

 form+="    <div id='llave1' style='position: absolute; top:  60px;  left: 40%; font: 120% monospace;'>Llave 1 &nbsp;<HR id='ll1' width=60% align='right' color='#808B96'  style='height: 10px; background-color: #808B96;'></div>";

form+="     <div id='etiquetas' style='position: absolute; top:  260px; left: 40%; font: 120% monospace;'>Limite</div>";
form+=" <div id='contenedor' style='width: 150px; height: 200px; background: #5DADE2; position: absolute; top:  100px;left: 45%;'>";
 form+="    <div id='barra'  style='height:0px; width: 150px; background: #D0D3D4;'>";
 form+= "     <HR width=100% align='center' color='#C0392B' style='position: absolute; top:160px; left: 0%;'>  </div>   </div>";
        
 form+="  <div id='llave2' style='position: absolute; top:  262px; left: 56%; font: 120% monospace;'> &nbsp; Llave 2 <HR id='ll2' width=50% align='left' color='#808B96'  style='height: 10px; background-color: #808B96;'>";
  form+= "    </div>  <form name='form1' action='' method='post' style='position:relative;right: 300px;top:150px; font-family:verdana,arial; font-size:9pt; text-align: center;'>";

   form+=   "     <legend id='eti' style=' font-size:14px; font-family:'Tahoma', 'Geneva', sans-serif; font-weight:bold; color:#C0392B; text-align: center;'>Sistema de llenado</legend>";
    form+=   "    <br> <fieldset><input id='v1' type='button' name='boton1' value='Vaciar' onclick='functionProgress2(0,-1);'/>";
      form+=  "     <input id='ll' type='button' name='boton' value='Llenar' onclick='functionProgress1(169,-1);'/>";
       form+=  "  </fieldset> <label id='mensaje'>  </label> </form> </body>  </html> ";
  /*------------------------------------------------------------ */

  pinMode(ledPin, OUTPUT); // tanque
  digitalWrite(ledPin, LOW);

  pinMode(D2, OUTPUT);  // llenar
  digitalWrite(D2, LOW);

  pinMode(D1, OUTPUT); // vaciar
  digitalWrite(D1, LOW);
  
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  server.on("/", [](){
  server.send(200, "text/html", form);
  });
  Serial.println("Pagina....");
  server.on("/inivaciar.html", ini_vaciar);
  server.on("/finvaciar.html", fin_vaciar);
  server.on("/inillenar.html", ini_llenar);
  server.on("/finllenar.html", fin_llenar);
  server.begin();
}

void loop() {
  server.handleClient();
}
