/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x < 0){
    return false
    }else if (x <=9){
        return true;
    }else{
        let sum = 0, b, a = x;
        while(a>0){
            b = a % 10;
            sum = sum*10 + b;
            a = parseInt(a /10);
        }
        console.log("sum", sum)
        return sum === x;
        
    }
    
};