/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
   if(strs.length === 0 || strs.includes("")){
       return "";
   }else if(strs.length ===1){
       return strs[0];
   }else{
        let out = strs[0][0];
       let index = 1;
      while(out.length <= strs[0].length){
           for(let i = 1; i<strs.length; i++){
           if(out !== strs[i].slice(0,index)){
               return out.slice(0, index-1);
           }
       }
        index +=1;
        out += strs[0][index-1];
      }
       return out.slice(0, index-1);
   }
    
};