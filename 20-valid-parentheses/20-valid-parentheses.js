/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  if (s.length % 2 !== 0) {
    return false;
  } else {
    const leftSymbol = [];
    for (let i = 0; i < s.length; i++) {
      if (s[i] === '{' || s[i] === '(' || s[i] === '[') {
        leftSymbol.push(s[i]);
      } else if (
        (s[i] === '}' && leftSymbol.length !== 0 && leftSymbol.slice(-1)[0] === '{') ||
        (s[i] === ']' && leftSymbol.length !== 0 && leftSymbol.slice(-1)[0] === '[') ||
        (s[i] === ')' && leftSymbol.length !== 0 && leftSymbol.slice(-1)[0] === '(')
      ) {
        leftSymbol.pop();
      }else{
          return false;
      }
    }
      return !leftSymbol.length;
  }
};