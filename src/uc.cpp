//
// Created by luism on 18/10/2022.
//

public UC::UC(int code){
    this.code = code;
}

public string UC::toString(){
    string out = "" + code;
    while(out.size()<3) out = '0'+out;
    return("L.EIC"+out);
}